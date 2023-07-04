#ifndef GLOBALDEF_H
#define GLOBALDEF_H
#include <QString>

enum exceptionValue
{
    contentVal=1,
    pictureVal=2,
    passwordVal=3,
    otherVal=0
};

QString textToBin(QString str);

#endif // GLOBALDEF_H
