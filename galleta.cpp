#include "galleta.h"

Galleta::Galleta()
{
    dx = 15;
    dy = 15;
}

Galleta::Galleta(float px, float py) : px(px), py(py)
{
    dx = 16;
    dy = 16;
    setPos(px+8,py+8);
}


QRectF Galleta::boundingRect() const
{
    return QRectF(0,0,dx,dy);
}

void Galleta::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::yellow);
    painter->drawEllipse(boundingRect());
}
