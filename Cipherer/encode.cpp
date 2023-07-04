#include "encode.h"
#include "ui_encode.h"
#include "globalDef.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QByteArray>
#include <QVector>
#include <math.h>
#include <QFileInfo>

Encode::Encode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Encode)
{
    ui->setupUi(this);
}

Encode::~Encode()
{
    delete ui;
}

void Encode::showException(QString e, exceptionValue type)
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


void Encode::on_textButton_clicked()
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
    QTextStream textStream(&file);
    while(!textStream.atEnd())
    {
        QChar c;
        textStream>>c;
        content.append(c);
    }
    if(content.isEmpty())
    {
        showException("File content is empty.", contentVal);
    }
    file.close();
}


void Encode::on_pictureButton_clicked()
{
    picturePath=QFileDialog::getOpenFileName(this, tr("Choose picture"), "/home");
    if((picturePath.isEmpty()) || (!picturePath.endsWith(".jpg") && !picturePath.endsWith(".jpeg")
                                    && !picturePath.endsWith(".png") && !picturePath.endsWith(".bmp")))
    {
        showException("Picture choosen incorrectly.", pictureVal);
    }

}


void Encode::on_confirmButton_clicked()
{
    password=ui->passwordEdit->toPlainText();
    if(password.isEmpty())
    {
        showException("Password is empty.", passwordVal);
    }
}
//============================================ CONVERTIONS ===================================================

QString Encode::binToHex(QString bytes)
{
    QString result="";
    QString oneByte="";
    int oneInt=0;
    for(int i=0; i<bytes.size(); i++)
    {
        oneByte.append(bytes.at(i));
        if((i+1)%8==0)
        {
            bool ok;
            try{
                oneInt=oneByte.toInt(&ok, 2);
                throw ok;
            }catch(bool e){
                if(!e)
                {
                    showException("Invalid convertion in function binToHex", otherVal);
                    break;
                }
            }
            result.append([&oneInt]()->QString{
                QString nonFullByte=QString::number(oneInt, 16);
                while(nonFullByte.size()<2)
                {
                    nonFullByte='0'+nonFullByte;
                }
                return nonFullByte;
            }());
            oneByte.clear();
        }
    }
    return result;
}

//============================================ COMPUTING ===================================================

QString xorTransformer(QString con, QString pass)
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

void Encode::ciphering()
{
    QString binOutput=xorTransformer(textToBin(content), textToBin(password));
    textOutput=binToHex(binOutput);
}

void Encode::on_encodeButton_clicked()
{
    ciphering();
    if(textOutput.isEmpty())
    {
        showException("Invalid cyphering.", otherVal);
    }

    // pathes
    QString tempTextPath="encodedFile.txt";
    QString tempArchPath="encodedArch.tar";
    QString finalPath=QFileDialog::getSaveFileName(this, tr("Choose Location"), "/home");

    // system commands
    const char *sysPointer=nullptr;
    QString archiveCom="tar -cvf "+tempArchPath+" "+tempTextPath;
    QString createCom="cat "+picturePath+" "+tempArchPath+" > "+finalPath;
    QString cleanComBin="rm "+tempTextPath;
    QString cleanComTar="rm "+tempArchPath;

    // saving in temporary location
    QFile tempFile(tempTextPath);
    try{
        throw tempFile.open(QIODevice::WriteOnly | QIODevice::Text);
    }catch(bool e){
        if(!e)
        {
            showException("Did not open temporary binary file.", otherVal);
        }
    }
    QTextStream stream(&tempFile);
    if(textOutput.isEmpty())
    {
        showException("Empty output text.", otherVal);
    }
    else
    {
        stream<<textOutput;
    }
    tempFile.close();

    // archiving | creating new file | cleaning
    sysPointer=archiveCom.toLatin1();
    system(sysPointer);

    sysPointer=createCom.toLatin1();
    system(sysPointer);

    sysPointer=cleanComBin.toLatin1();
    system(sysPointer);
    sysPointer=cleanComTar.toLatin1();
    system(sysPointer);

    delete[] sysPointer;
}
