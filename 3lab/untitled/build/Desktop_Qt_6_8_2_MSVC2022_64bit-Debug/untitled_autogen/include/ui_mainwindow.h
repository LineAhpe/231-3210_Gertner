/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox_data;
    QFormLayout *formLayout;
    QLabel *label_id;
    QLineEdit *lineEdit_id;
    QLabel *label_address;
    QLineEdit *lineEdit_address;
    QLabel *label_type;
    QLineEdit *lineEdit_type;
    QLabel *label_capacity;
    QLabel *label_square;
    QLabel *label_main;
    QLineEdit *lineEdit_main;
    QLineEdit *lineEdit_capacity;
    QLineEdit *lineEdit_square;
    QGroupBox *groupBox_actions;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_get;
    QPushButton *pushButton_post;
    QPushButton *pushButton_patch;
    QPushButton *pushButton_delete;
    QPushButton *pushButton_list;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(900, 344);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox_data = new QGroupBox(centralwidget);
        groupBox_data->setObjectName("groupBox_data");
        groupBox_data->setGeometry(QRect(30, 20, 500, 250));
        formLayout = new QFormLayout(groupBox_data);
        formLayout->setObjectName("formLayout");
        label_id = new QLabel(groupBox_data);
        label_id->setObjectName("label_id");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_id);

        lineEdit_id = new QLineEdit(groupBox_data);
        lineEdit_id->setObjectName("lineEdit_id");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_id);

        label_address = new QLabel(groupBox_data);
        label_address->setObjectName("label_address");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_address);

        lineEdit_address = new QLineEdit(groupBox_data);
        lineEdit_address->setObjectName("lineEdit_address");

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_address);

        label_type = new QLabel(groupBox_data);
        label_type->setObjectName("label_type");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_type);

        lineEdit_type = new QLineEdit(groupBox_data);
        lineEdit_type->setObjectName("lineEdit_type");

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_type);

        label_capacity = new QLabel(groupBox_data);
        label_capacity->setObjectName("label_capacity");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_capacity);

        label_square = new QLabel(groupBox_data);
        label_square->setObjectName("label_square");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_square);

        label_main = new QLabel(groupBox_data);
        label_main->setObjectName("label_main");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_main);

        lineEdit_main = new QLineEdit(groupBox_data);
        lineEdit_main->setObjectName("lineEdit_main");

        formLayout->setWidget(5, QFormLayout::FieldRole, lineEdit_main);

        lineEdit_capacity = new QLineEdit(groupBox_data);
        lineEdit_capacity->setObjectName("lineEdit_capacity");

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit_capacity);

        lineEdit_square = new QLineEdit(groupBox_data);
        lineEdit_square->setObjectName("lineEdit_square");

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEdit_square);

        groupBox_actions = new QGroupBox(centralwidget);
        groupBox_actions->setObjectName("groupBox_actions");
        groupBox_actions->setGeometry(QRect(550, 20, 300, 250));
        verticalLayout = new QVBoxLayout(groupBox_actions);
        verticalLayout->setObjectName("verticalLayout");
        pushButton_get = new QPushButton(groupBox_actions);
        pushButton_get->setObjectName("pushButton_get");

        verticalLayout->addWidget(pushButton_get);

        pushButton_post = new QPushButton(groupBox_actions);
        pushButton_post->setObjectName("pushButton_post");

        verticalLayout->addWidget(pushButton_post);

        pushButton_patch = new QPushButton(groupBox_actions);
        pushButton_patch->setObjectName("pushButton_patch");

        verticalLayout->addWidget(pushButton_patch);

        pushButton_delete = new QPushButton(groupBox_actions);
        pushButton_delete->setObjectName("pushButton_delete");

        verticalLayout->addWidget(pushButton_delete);

        pushButton_list = new QPushButton(groupBox_actions);
        pushButton_list->setObjectName("pushButton_list");

        verticalLayout->addWidget(pushButton_list);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 900, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Storage Facilities Manager", nullptr));
        groupBox_data->setTitle(QCoreApplication::translate("MainWindow", "\320\224\320\260\320\275\320\275\321\213\320\265 \320\264\320\273\321\217 \320\267\320\260\320\277\321\200\320\276\321\201\320\276\320\262", nullptr));
        label_id->setText(QCoreApplication::translate("MainWindow", "ID:", nullptr));
        label_address->setText(QCoreApplication::translate("MainWindow", "Address:", nullptr));
        label_type->setText(QCoreApplication::translate("MainWindow", "Type:", nullptr));
        label_capacity->setText(QCoreApplication::translate("MainWindow", "Capacity:", nullptr));
        label_square->setText(QCoreApplication::translate("MainWindow", "Square:", nullptr));
        label_main->setText(QCoreApplication::translate("MainWindow", "Main of Storage:", nullptr));
        groupBox_actions->setTitle(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\321\200\320\276\321\201\321\213", nullptr));
        pushButton_get->setText(QCoreApplication::translate("MainWindow", "GET", nullptr));
        pushButton_post->setText(QCoreApplication::translate("MainWindow", "POST", nullptr));
        pushButton_patch->setText(QCoreApplication::translate("MainWindow", "PATCH", nullptr));
        pushButton_delete->setText(QCoreApplication::translate("MainWindow", "DELETE", nullptr));
        pushButton_list->setText(QCoreApplication::translate("MainWindow", "LIST", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
