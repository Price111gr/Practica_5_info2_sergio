
#include "bullet.h"

int bullet::getX() const
{
    return x;
}

void bullet::setX(int newX)
{
    x = newX;
}

int bullet::getY() const
{
    return y;
}

void bullet::setY(int newY)
{
    y = newY;
}

bullet::bullet(int rad)
{
    radio = rad;
}

bullet::~bullet()
{

}

void bullet::posicion()
{
    setPos(x,y);
}

void bullet::posicion(int newX, int newY)
{
    x=newX;
    y=newY;
    setPos(x,y);
}

void bullet::shot(int vel)
{
    posicion(x,y+vel);
}

QRectF bullet::boundingRect() const
{
    return QRectF(-radio/2,-radio/2,radio,radio);
}

void bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::darkBlue);
    painter->drawEllipse(boundingRect());
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

