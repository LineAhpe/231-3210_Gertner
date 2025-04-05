#ifndef CLIENTINTERFACE_H
#define CLIENTINTERFACE_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QString>

class StorageItem {
public:
    int id;
    QString address;
    QString typename_;
    int capacity;
    int square;
    QString main_of_storage;

    void print() const;
};

class ClientInterface : public QObject
{
    Q_OBJECT
public:
    static ClientInterface* getInstance(const QString& root_url = "http://127.0.0.1:80/api");
    static void removeInstance();

    StorageItem GetStorage(unsigned int id);
    StorageItem UpdateStorage(const StorageItem& item, unsigned int id);
    StorageItem CreateStorage(const StorageItem& item);
    bool DeleteStorage(unsigned int id);
    QList<StorageItem> GetStorages();

    ~ClientInterface(){
        delete m_client;
    };

private:
    explicit ClientInterface(QObject* parent = nullptr);
    ClientInterface(const QString& root_url);

    static ClientInterface* existing_object;
    QNetworkAccessManager* m_client;
    QString m_root_url;
};

#endif // CLIENTINTERFACE_H
