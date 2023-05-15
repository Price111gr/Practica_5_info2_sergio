#ifndef BOMBA_H
#define BOMBA_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "explote.h"

class bomba
{
Q_OBJECT
public:

    void posicion(int x,int y);

    int getX() const;
    void setX(int newX);

    int getY() const;
    void setY(int newY);

public slots:
    void explocion(int x,int y);

private:
    int x;
    int y;

    QTimer *timer;
    explote *exploci;
};

#endif // BOMBA_H
