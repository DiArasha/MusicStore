#include "guitarprint.h"
#include "guitar.h"
#include "formguitar.h"
#include <qstring.h>

GuitarPrint::GuitarPrint()
{

}




QString GuitarPrint::Info(Guitar guitar)
{


if (guitar.date == NULL)
{
return "Наименование: " + guitar.name + ", цена: " + guitar.costStr + ", материал корпуса: " + guitar.material;
}
if (guitar.date != NULL)
{
return "Наименование: " + guitar.name + ", цена: " + guitar.costStr + ", материал корпуса: " + guitar.material + ", год выпуска: " + guitar.dateStr;
}
}
