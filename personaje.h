#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QGraphicsItem>
#include "proyectil.h"
#include <QPainter>
#include <string>
#include <QPixmap>
#include <QVector>
#include <QMap>


using namespace std;

#define DT 0.2


class Personaje : public QGraphicsItem
{

private:
    int test=1;
    int subtest=0;
    int vida;
    string nombre;
    float px, py;
    float vx, vy;
    float ax, ay;
    float dx, dy;

public:
    Personaje();
    Proyectil *bala;
    Personaje(float px, float py, string nombre);
    QMap<int,Proyectil*> Proyectiles;
    float getVx() const;
    float getVy() const;

    void setVx(float newVx);
    void setVy(float newVy);

    Proyectil* disparar(void);

    virtual QRectF boundingRect() const;
    virtual void paint(
            QPainter *painter,
            const QStyleOptionGraphicsItem *option,
            QWidget *widget = nullptr);

    void move();
    float getPx() const;
    void setPx(float value);
    float getPy() const;
    void setPy(float value);
};

#endif // PERSONAJE_H














