#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QVector>
#include <math.h>

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

void MainWindow::showException(QString e, int type)
{
    QMessageBox::information(this, "Exception", e, QMessageBox::Ok);
    switch(type)
    {
    case 1:{content.clear();}break;
    case 2:{picturePath.clear();}break;
    case 3:{password.clear();}break;
    default:{this->close();}break;
    }
}
//========================================== LOADING DATA =====================================================

void MainWindow::readContent()
{
    QString path=QFileDialog::getOpenFileName(this, tr("Choose text file"), "/home");
    if(!path.endsWith(".txt"))
    {
        showException("Incorrect text file extension.", 1);
    }
    QFile file(path);
    try{
        file.open(QIODevice::ReadOnly | QIODevice::Text);
    }catch(bool e){
        if(!e)
        {
            showException("Text file did not be open correctly.", 1);
        }
    }
    QTextStream stream(&file);
    QString catcher="";
    while(!stream.atEnd())
    {
        stream>>catcher;
        content.append(catcher);
    }
    file.close();
    if(content.isEmpty())
    {
        showException("File content is empty.", 1);
    }
}


void MainWindow::on_pictureButton_clicked()
{
    picturePath=QFileDialog::getOpenFileName(this, tr("Choose picture"), "/home");
    if(picturePath.isEmpty())
    {
        showException("Picture choosen incorrectly.", 2);
    }
}


void MainWindow::on_confirmButton_clicked()
{
    password=ui->passwordEdit->toPlainText();
    if(password.isEmpty())
    {
        showException("Password is empty.", 3);
    }
}
//============================================ CONVERTIONS ===================================================

QString hexToBin(QString str, MainWindow obj)
{
    QString oneByte="";
    QString result="";
    int intOneByte=0;
    for(int i=0; i<str.size(); i+=2)
    {
        oneByte.append(str.at(i));
        oneByte.append(str.at(i+1));
        bool ok;
        try{
            intOneByte=oneByte.toInt(&ok, 16);
            throw ok;
        }catch(bool e)
        {
            if(!e)
            {
                obj.showException("Cannot convert HexString to Integer", 0);
            }
        }
        result.append([&intOneByte]()->QString{
            QString nonFullByte=QString::number(intOneByte, 2);
            while(nonFullByte.size()<8)
            {
                nonFullByte='0'+nonFullByte;
            }
            return nonFullByte;
        }());
        oneByte.clear();
    }
    return result;
}

QString binToText(QString strBytes, MainWindow obj)
{
    QString result="";
    QString oneByte="";
    int oneInt=0;
    for(int i=0; i<strBytes.size(); i++)
    {
        oneByte.append(strBytes.at(i));
        if((i+1)%8==0)
        {
            try{
                bool ok;
                oneInt=oneByte.toInt(&ok, 2);
                throw ok;
            }catch(bool e){
                if(!e)
                {
                    obj.showException("Invalid convertion in function binToText", 0);
                }
            }
            result.append((char)oneInt);
            oneByte.clear();
        }
    }
    return result;
}

QString textToBin(QString str)
{
    QString result="";
    for(int i=0; i<str.size(); i++)
    {
        int oneInt=(int)str.at(i).toLatin1();
        result.append([&oneInt]()->QString{
            QString nonFullByte=QString::number(oneInt, 2);
            while(nonFullByte.size()<8)
            {
                nonFullByte='0'+nonFullByte;
            }
            return nonFullByte;
        }());
    }
    return result;
}

//============================================ COMPUTING ===================================================

QString xorTransormer(QString con, QString pass)
{
    QString result;
    for(int i=0, j=0; i<con.size(); i++, j++)
    {
        if(j>=pass.size())
        {
            j=0;
        }
        if(QString::compare(con.at(i), pass.at(j)))
        {
            result.append('0');
        }
        else
        {
            result.append('1');
        }
    }
    return result;
}

//============================================ MANAGING ===================================================

void MainWindow::deciphering()
{
    QString binOutput=xorTransormer(hexToBin(content, this), textToBin(password));
    textOutput=binToText(binOutput, this);
}

void MainWindow::on_decodeButton_clicked()
{
    // pathes
    QString homePath="/home/bunio/Pulpit/";

    // system commands
    const char *sysPointer=nullptr;
    QString extractCom="binwalk -e -C="+homePath+" "+picturePath;

    // extracting file
    sysPointer=extractCom.toLatin1();
    system(sysPointer);

    //decoding process
    readContent();
    deciphering();

    // saving in temporary location
    if(textOutput.isEmpty())
    {
        showException("Empty output.", 0);
    }
    else
    {
        QString outPath=QFileDialog::getSaveFileName(this, tr("Choose destiny location."), "/home");
        QFile outFile(outPath);
        try{
            throw outFile.open(QIODevice::WriteOnly | QIODevice::Text);
        }catch(bool e){
            if(!e)
            {
                showException("Destiny file did not be open correctly.", 0);
            }
        }
        QTextStream stream(&outFile);
        stream<<textOutput;
        outFile.close();
    }
    delete[] sysPointer;
}

