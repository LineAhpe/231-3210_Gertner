#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "clientinterface.h"
#include <QDebug>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_interface(ClientInterface::getInstance("http://127.0.0.1:80/api"))
{
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButton_get_clicked() {
    int id = ui->lineEdit_id->text().toInt();
    StorageItem item = m_interface->GetStorage(id);
    item.print();
}

void MainWindow::on_pushButton_post_clicked() {
    StorageItem storage;
    storage.address = ui->lineEdit_address->text();
    storage.typename_ = ui->lineEdit_type->text();
    storage.capacity = ui->lineEdit_capacity->text().toInt();
    storage.square = ui->lineEdit_square->text().toInt();
    storage.main_of_storage = ui->lineEdit_main->text();

    StorageItem result = m_interface->CreateStorage(storage);
    result.print();
}

void MainWindow::on_pushButton_patch_clicked() {
    int id = ui->lineEdit_id->text().toInt();

    StorageItem storage;
    storage.address = ui->lineEdit_address->text();
    storage.typename_ = ui->lineEdit_type->text();
    storage.capacity = ui->lineEdit_capacity->text().toInt();
    storage.square = ui->lineEdit_square->text().toInt();
    storage.main_of_storage = ui->lineEdit_main->text();

    if (storage.address.isEmpty() &&
        storage.typename_.isEmpty() &&
        ui->lineEdit_capacity->text().isEmpty() &&
        ui->lineEdit_square->text().isEmpty() &&
        storage.main_of_storage.isEmpty()) {
        qDebug() << "Error: хотя бы одно поле должно быть заполнено";
        return;
    }

    StorageItem result = m_interface->UpdateStorage(storage, id);
    result.print();
}

void MainWindow::on_pushButton_delete_clicked() {
    int id = ui->lineEdit_id->text().toInt();
    bool success = m_interface->DeleteStorage(id);
    qDebug() << "Операция удаления" << (success ? "successful" : "failed");
}

void MainWindow::on_pushButton_list_clicked() {
    QList<StorageItem> storages = m_interface->GetStorages();
    qDebug() << "=== List of storages ===";
    for (const StorageItem& storage : storages) {

        storage.print();
        qDebug() << "-----------------------";
    }
    qDebug() << "Total:" << storages.size() << "storages";
}
