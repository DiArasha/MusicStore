#ifndef GUITAR_H
#define GUITAR_H

#include <qstring.h>

class Guitar
{
public:
    Guitar();

QString name;
double cost;
QString costStr;
QString material;
int date = NULL;
QString dateStr /*= "1900"*/;

//QString Info1();
//QString Info2();

};

#endif // GUITAR_H
