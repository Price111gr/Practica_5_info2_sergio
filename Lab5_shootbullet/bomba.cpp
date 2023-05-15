#include "bomba.h"
#include "explote.h"
void bomba::posicion(int x, int y)
{

    setPos(x,y);
}

void bomba::explocion(int x,int y)
{
    exploci = new explote();
    exploci->posicion(getY(),getX());

}

int bomba::getY() const
{
    return y;
}

void bomba::setY(int newY)
{
    y = newY;
}


int bomba::getX() const
{
    return x;
}

void bomba::setX(int newX)
{
    x = newX;
}
