#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include "encode.h"
#include "decode.h"

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
    Encode *encoding=new Encode;
    encoding->show();
}


void MainWindow::on_DecodeButton_clicked()
{
    Decode *decoding=new Decode();
    decoding->show();
}

