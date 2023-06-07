#include "muro.h"

Muro::Muro() : px(0), py(0)
{
    dx = 30;
    dy = 30;
}

Muro::Muro(float px, float py) : px(px), py(py)
{
    dx = 30;
    dy = 30;
    setPos(px,py);
}


QRectF Muro::boundingRect() const
{
    return QRectF(0,0,dx,dy);
}

void Muro::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawRect(boundingRect());
}
