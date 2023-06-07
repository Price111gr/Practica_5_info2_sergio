#ifndef GALLETA_H
#define GALLETA_H

#include <QGraphicsItem>
#include <QPainter>
#include <string>
#include <QPixmap>

class Galleta : public QGraphicsItem
{
private:
    float px, py;
    float dx, dy;

public:    
    Galleta();
    Galleta(float px, float py);

    virtual QRectF boundingRect() const;
    virtual void paint(
            QPainter *painter,
            const QStyleOptionGraphicsItem *option,
            QWidget *widget = nullptr);
};

#endif // GALLETA_H
