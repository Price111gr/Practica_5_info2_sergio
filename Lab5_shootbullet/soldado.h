#ifndef SOLDADO_H
#define SOLDADO_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class soldado: public QObject,
                public QGraphicsPixmapItem
{
    Q_OBJECT

private:
    int x;
    int y;

public:

    soldado(QGraphicsItem* carr = 0);

    int getX() const;
    void setX(int value);
    int getY() const;
    void setY(int value);

    //Definir posicion graficar
    void posicion();
    void posicion(int newX, int newY);
//    void MoveUp();
//    void MoveDown();
//    void MoveLeft();
//    void MoveRight();

};

#endif // SOLDADO_H
