#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <QGraphicsItem>
#include <QPainter>
#include <string>
#include <QPixmap>
#include <QTimer>
#include <QDebug>
#include <QMovie>

using namespace std;

#define DT 0.9

class enemigo: public QObject, public QGraphicsItem
{
    Q_OBJECT
private:
    float px, py;
    float vx, vy;
    float dx, dy;

    QTimer *duracion;



public:
    enemigo();
    enemigo(float px, float py, float vx, float vy);
    ~enemigo();

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

#endif // ENEMIGO_H
