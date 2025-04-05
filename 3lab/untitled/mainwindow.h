#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "clientinterface.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_get_clicked();
    void on_pushButton_patch_clicked();
    void on_pushButton_post_clicked();
    void on_pushButton_delete_clicked();
    void on_pushButton_list_clicked();

private:
    Ui::MainWindow *ui;
    ClientInterface* m_interface;
};

#endif // MAINWINDOW_H
