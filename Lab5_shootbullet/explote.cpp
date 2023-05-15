
#include "explote.h"

int explote::getY() const
{
    return y;
}

void explote::setY(int newY)
{
    y = newY;
}

int explote::getX() const
{
    return x;
}

void explote::setX(int newX)
{
    x = newX;
}

void explote::posicion(int Xn, int Yn)
{
    x=Xn;
    y=Yn;
    setPosi(Xn,Yn);
}
