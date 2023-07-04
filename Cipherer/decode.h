#ifndef DECODE_H
#define DECODE_H

#include <QWidget>
#include "globalDef.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Decode; }
QT_END_NAMESPACE

class Decode : public QWidget
{
    Q_OBJECT

public:
    Decode(QWidget *parent = nullptr);
    ~Decode();

    friend QString textToBin(QString str);

private slots:
    void on_pictureButton_clicked();

    void on_confirmButton_clicked();

    void on_decodeButton_clicked();

private:
    Ui::Decode *ui;
    QString picturePath;
    QString password;
    QString content;
    QString textOutput;

    void deciphering();
    void readContent();
    void showException(QString e, exceptionValue type);
    QString hexToBin(QString str);
    QString binToText(QString strBytes);
};
#endif // DECODE_H
