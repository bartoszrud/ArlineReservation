#ifndef PRZECIAZENIA_H
#define PRZECIAZENIA_H

#include "rezerwacje.h"
#include <QtCore>

QDataStream &operator <<(QDataStream &out, const Karta_pokladowa &karta);
QDataStream &operator >>(QDataStream &in, const Karta_pokladowa &karta);
QDataStream &operator <<(QDataStream &out, const Karta_pokladowa &karta);
QDataStream &operator >>(QDataStream &in, const Karta_pokladowa &karta);
#endif // PRZECIAZENIA_H
