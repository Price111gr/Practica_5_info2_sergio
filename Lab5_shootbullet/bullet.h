
#ifndef BULLET_H
#define BULLET_H

#include <QPainter>
#include <QGraphicsItem>



class bullet: public QGraphicsItem
{

private:
    int x;
    int y;
    int radio;

public:
    bullet(int rad);
    ~bullet();

    int getX() const;
    void setX(int newX);
    int getY() const;
    void setY(int newY);

    //Definir posicion graficar
    void posicion();
    void posicion(int newX, int newY);

    void shot(int);

    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // BULLET_H
