#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum exceptionValue
{
    contentVal=1,
    pictureVal=2,
    passwordVal=3,
    otherVal=0
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void deciphering();
    void readContent();
    void showException(QString e, exceptionValue type);


    friend QString hexToBin(QString str, MainWindow obj);
    friend QString binToText(QString strBytes, MainWindow obj);

private slots:
    void on_pictureButton_clicked();

    void on_confirmButton_clicked();

    void on_decodeButton_clicked();

private:
    Ui::MainWindow *ui;
    QString picturePath;
    QString password;
    QString content;
    QString textOutput;
};
#endif // MAINWINDOW_H
