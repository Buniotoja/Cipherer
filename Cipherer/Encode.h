#ifndef ENCODE_H
#define ENCODE_H

#include
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Encode; }
QT_END_NAMESPACE

class Encode : public QMainWindow
{
    Q_OBJECT

public:
    Encode(QWidget *parent=nullptr);
    ~Encode();
private:
    Ui::Encode *ui;
};

#endif // ENCODE_H
