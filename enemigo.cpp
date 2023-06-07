#include "enemigo.h"

float enemigo::getPx() const
{
    return px;
}

void enemigo::setPx(float value)
{
    px = value;
}

float enemigo::getPy() const
{
    return py;
}

void enemigo::setPy(float value)
{
    py = value;
}

float enemigo::getVx() const
{
    return vx;
}

void enemigo::setVx(float value)
{
    vx = value;
}

float enemigo::getVy() const
{
    return vy;
}

void enemigo::setVy(float value)
{
    vy = value;
}
enemigo::enemigo()
{

}

enemigo::enemigo(float px, float py,float vx, float vy)
    : px(px), py(py), vx(vx), vy(vy)
{
    dx = 60;
    dy = 60;
    setPos(px+8,py+8);

}

enemigo::~enemigo()
{
    delete duracion;
}

QRectF enemigo::boundingRect() const
{
    return QRectF(0,0,dx,dy);
}

void enemigo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    int preist=0;
    while(preist<8){
        preist++;
        if(preist==1){
            QPixmap p(":/Sprites/preist1.png");
            painter->drawPixmap(0,0,dx,dy,p);
        }
        else if(preist==2){
            QPixmap p(":/Sprites/preist2.png");
            painter->drawPixmap(0,0,dx,dy,p);
        }
        else if(preist==3){
            QPixmap p(":/Sprites/preist3.png");
            painter->drawPixmap(0,0,dx,dy,p);
        }
        else if(preist==4){
            QPixmap p(":/Sprites/preist4.png");
            painter->drawPixmap(0,0,dx,dy,p);
        }
        else if(preist==5){
            QPixmap p(":/Sprites/preist5.png");
            painter->drawPixmap(0,0,dx,dy,p);
        }
        else if(preist==6){
            QPixmap p(":/Sprites/preist6.png");
            painter->drawPixmap(0,0,dx,dy,p);
        }
        else if(preist==7){
            QPixmap p(":/Sprites/preist7.png");
            painter->drawPixmap(0,0,dx,dy,p);
        }
        else if(preist==8){
            QPixmap p(":/Sprites/preist8.png");
            painter->drawPixmap(0,0,dx,dy,p);
        }
    }
    preist=0;

}

void enemigo::mover()
{
    px = px + vx*DT;
    py = py;
    setPos(px,py);
}

