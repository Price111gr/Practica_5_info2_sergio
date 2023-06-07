#ifndef PROYECTIL_H
#define PROYECTIL_H

#include <QGraphicsItem>
#include <QPainter>
#include <string>
#include <QPixmap>
#include <QTimer>
#include <QDebug>
#include <stdlib.h>

//#include <personaje.h>

using namespace std;

#define DT 0.8

class Proyectil :public QObject, public QGraphicsItem
{
    Q_OBJECT

private:
    float px, py;
    float vx, vy;
    float dx, dy;

    int nota =1 + rand()%(5-1);

public:
    Proyectil();
    Proyectil(float px, float py, float vx, float vy);
    ~Proyectil();

    float getPx() const;
    float getPy() const;
    float getVx() const;
    float getVy() const;

    void setPx(float value);
    void setPy(float value);
    void setVx(float newVx);
    void setVy(float newVy);

    virtual QRectF boundingRect() const;
    virtual void paint(
            QPainter *painter,
            const QStyleOptionGraphicsItem *option,
            QWidget *widget = nullptr);

    void mover();


};

#endif // PROYECTIL_H
