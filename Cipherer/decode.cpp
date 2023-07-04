#include "decode.h"
#include "ui_decode.h"
#include "globalDef.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QVector>
#include <math.h>

Decode::Decode(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Decode)
{
    ui->setupUi(this);
}

Decode::~Decode()
{
    delete ui;
}

void Decode::showException(QString e, exceptionValue type)
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

void Decode::readContent()
{
    QString path=QFileDialog::getOpenFileName(this, tr("Choose text file"), "/home");
    if(!path.endsWith(".txt"))
    {
        showException("Incorrect text file extension.", contentVal);
    }
    QFile file(path);
    try{
        file.open(QIODevice::ReadOnly | QIODevice::Text);
    }catch(bool e){
        if(!e)
        {
            showException("Text file did not be open correctly.", contentVal);
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
        showException("File content is empty.", contentVal);
    }
}


void Decode::on_pictureButton_clicked()
{
    picturePath=QFileDialog::getOpenFileName(this, tr("Choose picture"), "/home");
    if(picturePath.isEmpty())
    {
        showException("Picture choosen incorrectly.", pictureVal);
    }
}


void Decode::on_confirmButton_clicked()
{
    password=ui->passwordEdit->toPlainText();
    if(password.isEmpty())
    {
        showException("Password is empty.", passwordVal);
    }
}
//============================================ CONVERTIONS ===================================================

QString Decode::hexToBin(QString str)
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
                showException("Cannot convert HexString to Integer", otherVal);
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

QString Decode::binToText(QString strBytes)
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
                    showException("Invalid convertion in function binToText", otherVal);
                }
            }
            result.append((char)oneInt);
            oneByte.clear();
        }
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

void Decode::deciphering()
{
    QString binOutput=xorTransormer(hexToBin(content), textToBin(password));
    textOutput=binToText(binOutput);
}

void Decode::on_decodeButton_clicked()
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
        showException("Empty output.", otherVal);
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
                showException("Destiny file did not be open correctly.", otherVal);
            }
        }
        QTextStream stream(&outFile);
        stream<<textOutput;
        outFile.close();
    }
    delete[] sysPointer;
}

