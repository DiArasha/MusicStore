#ifndef GUITARPRINT_H
#define GUITARPRINT_H

#include "guitar.h"
#include <qstring.h>


class GuitarPrint : public Guitar
{
public:
    GuitarPrint();


    QString Info(Guitar guitar);
};

#endif // GUITARPRINT_H
