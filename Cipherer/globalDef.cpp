#include "globalDef.h"
#include <QString>

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
