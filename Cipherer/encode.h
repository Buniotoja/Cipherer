#ifndef ENCODE_H
#define ENCODE_H

#include <QWidget>
#include "globalDef.h"

namespace Ui {
class Encode;
}

class Encode : public QWidget
{
    Q_OBJECT

public:
    explicit Encode(QWidget *parent = nullptr);
    ~Encode();

private slots:

    void on_textButton_clicked();

    void on_pictureButton_clicked();

    void on_confirmButton_clicked();

    void on_encodeButton_clicked();

private:
    Ui::Encode *ui;
    QString content;
    QString picturePath;
    QString password;
    QString textOutput;

    void showException(QString e, exceptionValue type);
    void ciphering();
    QString binToHex(QString bytes);
};

#endif // ENCODE_H
