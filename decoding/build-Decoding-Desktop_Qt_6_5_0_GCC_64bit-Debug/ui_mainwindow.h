/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *titleLabel;
    QLabel *pictureLabel;
    QLabel *passwordLabel;
    QPushButton *confirmButton;
    QTextEdit *passwordEdit;
    QPushButton *decodeButton;
    QPushButton *pictureButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setGeometry(QRect(330, 100, 171, 41));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        titleLabel->setFont(font);
        pictureLabel = new QLabel(centralwidget);
        pictureLabel->setObjectName("pictureLabel");
        pictureLabel->setGeometry(QRect(120, 200, 141, 31));
        passwordLabel = new QLabel(centralwidget);
        passwordLabel->setObjectName("passwordLabel");
        passwordLabel->setGeometry(QRect(440, 210, 91, 21));
        confirmButton = new QPushButton(centralwidget);
        confirmButton->setObjectName("confirmButton");
        confirmButton->setGeometry(QRect(670, 240, 101, 41));
        passwordEdit = new QTextEdit(centralwidget);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setGeometry(QRect(340, 240, 301, 41));
        decodeButton = new QPushButton(centralwidget);
        decodeButton->setObjectName("decodeButton");
        decodeButton->setGeometry(QRect(340, 400, 191, 61));
        pictureButton = new QPushButton(centralwidget);
        pictureButton->setObjectName("pictureButton");
        pictureButton->setGeometry(QRect(100, 240, 161, 51));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        titleLabel->setText(QCoreApplication::translate("MainWindow", "Decoding", nullptr));
        pictureLabel->setText(QCoreApplication::translate("MainWindow", "Choose picture", nullptr));
        passwordLabel->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        confirmButton->setText(QCoreApplication::translate("MainWindow", "confirm", nullptr));
        decodeButton->setText(QCoreApplication::translate("MainWindow", "Decode", nullptr));
        pictureButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
