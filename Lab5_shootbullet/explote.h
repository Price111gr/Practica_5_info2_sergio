
#ifndef EXPLOTE_H
#define EXPLOTE_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>



class explote
{
private:

    int x;
    int y;

public:
    explote();
    void posicion();
    int getY() const;
    void setY(int newY);
    int getX() const;
    void setX(int newX);
};

#endif // EXPLOTE_H


