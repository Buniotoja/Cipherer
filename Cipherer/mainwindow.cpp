#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QProcess>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_encodeButton_clicked()
{
    QProcess starter;
    starter.start("/home/bunio/Pulpit/Cipherer/Encoding");
    starter.waitForFinished(-1);
}


void MainWindow::on_DecodeButton_clicked()
{
    QProcess starter;
    starter.start("/home/bunio/Pulpit/Cipherer/Decoding");
    starter.waitForFinished(-1);
}

