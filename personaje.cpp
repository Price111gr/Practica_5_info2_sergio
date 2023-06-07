#include "personaje.h"

float Personaje::getPx() const
{
    return px;
}

void Personaje::setPx(float value)
{
    px = value;
}

float Personaje::getPy() const
{
    return py;
}

void Personaje::setPy(float value)
{
    py = value;
}

Personaje::Personaje()
    : px(0), py(100),
      vx(0), vy(0),
      ax(0), ay(0),
      dx(40), dy(40)
{
    nombre = "NN";
    vida = 100;
}
Personaje::Personaje(float px, float py, string nombre)
    : px(px), py(py),
    vx(0), vy(0),
    ax(0), ay(0),
    dx(20), dy(20)
{
  this->nombre = nombre;
  vida = 100;
}

float Personaje::getVx() const
{
    return vx;
}

float Personaje::getVy() const
{
    return vy;
}

void Personaje::setVx(float newVx)
{
    vx = newVx;
}

void Personaje::setVy(float newVy)
{
    vy = newVy;
}

Proyectil* Personaje::disparar()
{
    float _vx, _vy;

        _vx=vx+20;

    Proyectiles.insert(test , new Proyectil(px,py,_vx,_vy));
        //return Proyectiles.last();
       // Proyectiles.insert(test ,new Proyectil(px,py,_vx,_vy));
        int ap=test;
        test++;
        auto it = Proyectiles.value(ap);
        return it;

}

QRectF Personaje::boundingRect() const
{
    return QRectF(0,0,dx,dy);
}

void Personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//    painter->setBrush(Qt::red);
//    painter->drawEllipse(boundingRect());

    QPixmap p(":/Sprites/image-w856.png");
    painter->drawPixmap(0,0,dx,dy,p);
}

void Personaje::move()
{

    for(auto it: Proyectiles){
        it->mover();
    }
    vx = vx + ax*DT;
    vy = vy + ay*DT;

    px = px + vx*DT +0.5*ax*DT*DT;
    py = py + vy*DT +0.5*ay*DT*DT;

    setPos(px,py);

    float _vx, _vy;

    if(Proyectiles.size()==0){
        Proyectiles.insert(subtest ,new Proyectil(100,100,0,0));
    }
}










