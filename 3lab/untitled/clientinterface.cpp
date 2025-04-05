#include "clientinterface.h"
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QEventLoop>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QJsonArray>

ClientInterface* ClientInterface::existing_object = nullptr;

ClientInterface* ClientInterface::getInstance(const QString& root_url) {
    if(existing_object == nullptr) {
        existing_object = new ClientInterface(root_url);
    }
    return existing_object;
}

void ClientInterface::removeInstance() {
    if(existing_object) {
        delete existing_object;
        existing_object = nullptr;
    }
}

ClientInterface::ClientInterface(QObject* parent)
    : QObject(parent), m_client(new QNetworkAccessManager(this)) {}

ClientInterface::ClientInterface(const QString& root_url)
    : QObject(nullptr), m_root_url(root_url), m_client(new QNetworkAccessManager(this)) {}


void StorageItem::print() const {
    qDebug() << "Id:" << id;
    qDebug() << "Address:" << address;
    qDebug() << "Type:" << typename_;
    qDebug() << "Capacity:" << capacity;
    qDebug() << "Square:" << square;
    qDebug() << "Main of Storage:" << main_of_storage;
}

StorageItem ClientInterface::GetStorage(unsigned int id) {
    QNetworkRequest request(QUrl(m_root_url + "/storage/" + QString::number(id)));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply* reply = m_client->get(request);
    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    StorageItem result;
    if (reply->error() == QNetworkReply::NoError) {
        QJsonParseError parseError;
        QJsonDocument doc = QJsonDocument::fromJson(reply->readAll(), &parseError);
        if (parseError.error == QJsonParseError::NoError) {
            QJsonObject obj = doc.object();
            result.id = obj["id"].toInt();
            result.address = obj["address"].toString();
            result.typename_ = obj["typename"].toString();
            result.capacity = obj["capacity"].toInt();
            result.square = obj["square"].toInt();
            result.main_of_storage = obj["main_of_storage"].toString();
        } else {
            qDebug() << "JSON Ошибка:" << parseError.errorString();
        }
    } else {
        qDebug() << "Network error:" << reply->errorString();
    }
    reply->deleteLater();
    return result;
}

StorageItem ClientInterface::UpdateStorage(const StorageItem& item, unsigned int id) {
    QNetworkRequest request(QUrl(m_root_url + "/storage/" + QString::number(id)));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject json;
    if (!item.address.isEmpty()) {
        json["address"] = item.address;
    }
    if (!item.typename_.isEmpty()) {
        json["typename"] = item.typename_;
    }
    if (item.capacity != 0) {
        json["capacity"] = item.capacity;
    }
    if (item.square != 0) {
        json["square"] = item.square;
    }
    if (!item.main_of_storage.isEmpty()) {
        json["main_of_storage"] = item.main_of_storage;
    }

    QNetworkReply* reply = m_client->put(request, QJsonDocument(json).toJson());
    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    StorageItem result;
    if (reply->error() == QNetworkReply::NoError) {
        QJsonParseError parseError;
        QJsonDocument doc = QJsonDocument::fromJson(reply->readAll(), &parseError);
        if (parseError.error == QJsonParseError::NoError) {
            QJsonObject obj = doc.object();
            result.id = obj["id"].toInt();
            result.address = obj["address"].toString();
            result.typename_ = obj["typename"].toString();
            result.capacity = obj["capacity"].toInt();
            result.square = obj["square"].toInt();
            result.main_of_storage = obj["main_of_storage"].toString();
            qDebug() << "Storage updated successfully";
        } else {
            qDebug() << "JSON ошибка:" << parseError.errorString();
        }
    } else {
        qDebug() << "Update ошибка:" << reply->errorString();
    }

    reply->deleteLater();
    return result;
}

StorageItem ClientInterface::CreateStorage(const StorageItem& item) {
    QNetworkRequest request(QUrl(m_root_url + "/storage"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject json;
    json["address"] = item.address;
    json["typename"] = item.typename_;
    json["capacity"] = item.capacity;
    json["square"] = item.square;
    json["main_of_storage"] = item.main_of_storage;

    QNetworkReply* reply = m_client->post(request, QJsonDocument(json).toJson());
    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    StorageItem result;
    if (reply->error() == QNetworkReply::NoError) {
        QJsonParseError parseError;
        QJsonDocument doc = QJsonDocument::fromJson(reply->readAll(), &parseError);
        if (parseError.error == QJsonParseError::NoError) {
            QJsonObject obj = doc.object();
            result.id = obj["id"].toInt();
            result.address = obj["address"].toString();
            result.typename_ = obj["typename"].toString();
            result.capacity = obj["capacity"].toInt();
            result.square = obj["square"].toInt();
            result.main_of_storage = obj["main_of_storage"].toString();
            qDebug() << "Storage created successfully";
        } else {
            qDebug() << "JSON ошибка:" << parseError.errorString();
        }
    } else {
        qDebug() << "Create ошибка:" << reply->errorString();
    }

    reply->deleteLater();
    return result;
}

bool ClientInterface::DeleteStorage(unsigned int id) {
    QNetworkRequest request(QUrl(m_root_url + "/storage/" + QString::number(id)));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply* reply = m_client->deleteResource(request);
    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    bool success = false;

    // Получаем HTTP статус код ответа
    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();

    if (reply->error() == QNetworkReply::NoError && statusCode == 204) {
        qDebug() << "Storage удалён усешно (HTTP 204)";
        success = true;
    } else {
        if (reply->error() != QNetworkReply::NoError) {
            qDebug() << "Delete ошибка:" << reply->errorString();
        } else {
            qDebug() << "Код ответа не 204:" << statusCode;
        }
    }

    reply->deleteLater();
    return success;
}

QList<StorageItem> ClientInterface::GetStorages() {
    QList<StorageItem> storages;

    QNetworkRequest request(QUrl(m_root_url + "/storage"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply* reply = m_client->get(request);
    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    if (reply->error() == QNetworkReply::NoError) {
        QJsonParseError parseError;
        QByteArray responseData = reply->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(responseData, &parseError);

        if (parseError.error == QJsonParseError::NoError) {
            if (doc.isArray()) {
                const QJsonArray& jsonArray = doc.array();

                for (const QJsonValue& value : jsonArray) {
                    if (value.isObject()) {
                        QJsonObject obj = value.toObject();
                        StorageItem item;

                        // Извлекаем только существующие поля
                        item.id = obj["id"].toInt();
                        item.address = obj["address"].toString();
                        item.typename_ = obj["typename"].toString();
                        item.capacity = obj["capacity"].toInt();
                        item.square = obj["square"].toInt();
                        item.main_of_storage = obj["main_of_storage"].toString();

                        storages.append(item);
                    }
                }
                qDebug() << "Успешно получены данные" << storages.size() << "storages";
            } else {
                qDebug() << "Data:" << responseData;
            }
        } else {
            qDebug() << "Response data:" << responseData;
        }
    } else {
        qDebug() << "Network error:" << reply->errorString();
    }

    reply->deleteLater();
    return storages;
}
