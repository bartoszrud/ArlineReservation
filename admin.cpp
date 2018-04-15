#include "admin.h"

Admin::Admin()
{

}


bool Admin::zaloguj(QString h)
{
    if (h == haslo)
        return true;
    else return false;
}
