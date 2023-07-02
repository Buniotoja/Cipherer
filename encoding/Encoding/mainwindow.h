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

    void showException(QString e, exceptionValue type);
    void ciphering();

    friend QString binToHex(QString bytes, MainWindow obj);

private slots:

    void on_textButton_clicked();

    void on_pictureButton_clicked();

    void on_confirmButton_clicked();

    void on_encodeButton_clicked();

private:
    Ui::MainWindow *ui;
    QString content;
    QString picturePath;
    QString password;
    QString textOutput;
};
#endif // MAINWINDOW_H
