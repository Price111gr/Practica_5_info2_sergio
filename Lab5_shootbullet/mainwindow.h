#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include "soldado.h"
#include "bullet.h"
#include "muro.h"
#include <QTimer>
#include <QGraphicsRectItem>
#include <QDebug>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    int blokW=0;
    int blokS=0;
    int blokA=0;
    int blokD=0;
    char letraPulse;

public:

    void disparo();
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    char getLetraPulse() const;
    void setLetraPulse(char newLetraPulse);
    //colisiones();
    void keyPressEvent(QKeyEvent *event);
    explote();

private slots:
    void hmov();
    void bullet_mov();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    soldado *jugador;
    int vel;
    int vel_auto;
    QTimer *timer;
    QTimer *timer_bullet;
    //QGraphicsRectItem *rect;
    QVector<Muros*> Muro;
    QList<QGraphicsRectItem*> Ellipse;
    QList<bullet*> balas;
    bullet * bala_temp;
};
#endif // MAINWINDOW_H
