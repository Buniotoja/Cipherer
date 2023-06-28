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
    QLabel *textLabel;
    QLabel *pictureLabel;
    QLabel *title;
    QLabel *passwordLabel;
    QTextEdit *passwordEdit;
    QPushButton *textButton;
    QPushButton *pictureButton;
    QPushButton *confirmButton;
    QPushButton *encodeButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        textLabel = new QLabel(centralwidget);
        textLabel->setObjectName("textLabel");
        textLabel->setGeometry(QRect(140, 180, 151, 31));
        pictureLabel = new QLabel(centralwidget);
        pictureLabel->setObjectName("pictureLabel");
        pictureLabel->setGeometry(QRect(520, 190, 141, 21));
        title = new QLabel(centralwidget);
        title->setObjectName("title");
        title->setGeometry(QRect(310, 70, 151, 41));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        title->setFont(font);
        passwordLabel = new QLabel(centralwidget);
        passwordLabel->setObjectName("passwordLabel");
        passwordLabel->setGeometry(QRect(320, 310, 91, 21));
        passwordEdit = new QTextEdit(centralwidget);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setGeometry(QRect(180, 350, 361, 41));
        textButton = new QPushButton(centralwidget);
        textButton->setObjectName("textButton");
        textButton->setGeometry(QRect(100, 230, 221, 41));
        pictureButton = new QPushButton(centralwidget);
        pictureButton->setObjectName("pictureButton");
        pictureButton->setGeometry(QRect(480, 230, 221, 41));
        confirmButton = new QPushButton(centralwidget);
        confirmButton->setObjectName("confirmButton");
        confirmButton->setGeometry(QRect(590, 350, 111, 41));
        encodeButton = new QPushButton(centralwidget);
        encodeButton->setObjectName("encodeButton");
        encodeButton->setGeometry(QRect(290, 460, 191, 51));
        MainWindow->setCentralWidget(centralwidget);
        encodeButton->raise();
        textLabel->raise();
        pictureLabel->raise();
        title->raise();
        passwordLabel->raise();
        passwordEdit->raise();
        textButton->raise();
        pictureButton->raise();
        confirmButton->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        textLabel->setText(QCoreApplication::translate("MainWindow", "Choose text file", nullptr));
        pictureLabel->setText(QCoreApplication::translate("MainWindow", "Choose picture", nullptr));
        title->setText(QCoreApplication::translate("MainWindow", "Encoding", nullptr));
        passwordLabel->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        textButton->setText(QCoreApplication::translate("MainWindow", "Choose", nullptr));
        pictureButton->setText(QCoreApplication::translate("MainWindow", "Choose", nullptr));
        confirmButton->setText(QCoreApplication::translate("MainWindow", "Confirm", nullptr));
        encodeButton->setText(QCoreApplication::translate("MainWindow", "Encode", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
