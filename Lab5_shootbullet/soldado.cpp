#include "soldado.h"

int soldado::getX() const
{
    return x;
}

void soldado::setX(int value)
{
    x = value;
}

int soldado::getY() const
{
    return y;
}

void soldado::setY(int value)
{
    y = value;
}

soldado::soldado(QGraphicsItem *carr):QGraphicsPixmapItem(carr)
{
    setPixmap(QPixmap(":/Images/playmove.png"));
}

void soldado::posicion()
{
    setPos(x,y);
}

void soldado::posicion(int newX, int newY)
{
    x=newX;
    y=newY;
    setPos(x,y);
}

//void soldado::MoveUp()
//{
//    soldado.setX(soldado.getX()-vel);
//    setPos(posx, posy);
//    MinMax(1);
//    qDebug()<<posy<<"posicion en y actual\n";
//}

//void soldado::MoveDown()
//{
//    posy+=velocidad;
//    setPos(posx, posy);
//    MinMax(2);
//    qDebug()<<posy<<"posicion en y actual\n";
//}

//void soldado::MoveLeft()
//{
//    posx-=velocidad;
//    setPos(posx, posy);
//    MinMax(3);
//    qDebug()<<posx<<"posicion en x actual\n";
//}

//void soldado::MoveRight()
//{
//    posx+=velocidad;
//    setPos(posx, posy);
//    MinMax(4);
//    qDebug()<<posx<<"posicion en x actual\n";
//}
