#include "proyectil.h"

float Proyectil::getPx() const
{
    return px;
}

void Proyectil::setPx(float value)
{
    px = value;
}

float Proyectil::getPy() const
{
    return py;
}

void Proyectil::setPy(float value)
{
    py = value;
}

float Proyectil::getVx() const
{
    return vx;
}

void Proyectil::setVx(float value)
{
    vx = value;
}

float Proyectil::getVy() const
{
    return vy;
}

void Proyectil::setVy(float value)
{
    vy = value;
}

Proyectil::Proyectil()
{
    dx = 15;
    dy = 15;
}

Proyectil::Proyectil(float px, float py,float vx, float vy)
    : px(px), py(py), vx(vx), vy(vy)
{
    dx = 16;
    dy = 16;
    setPos(px+8,py+8);


}

Proyectil::~Proyectil()
{
    //delete duracion;
}

QRectF Proyectil::boundingRect() const
{
    return QRectF(0,0,dx,dy);
}

void Proyectil::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->setBrush(Qt::red);
    //painter->drawRect(boundingRect());



    if(nota==1){
        QPixmap p(":/Sprites/nota1.png");
        painter->drawPixmap(0,0,dx,dy,p);
    }
    else if(nota==2){
        QPixmap p(":/Sprites/nota2.png");
        painter->drawPixmap(0,0,dx,dy,p);
    }
    else if(nota==3){
        QPixmap p(":/Sprites/nota3.png");
        painter->drawPixmap(0,0,dx,dy,p);
    }
    else if(nota==4){
        QPixmap p(":/Sprites/nota4.png");
        painter->drawPixmap(0,0,dx,dy,p);
    }


}

void Proyectil::mover()
{
    px = px + vx*DT;
    py = py;
    setPos(px,py);
}



