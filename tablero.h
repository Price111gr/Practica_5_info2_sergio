#ifndef TABLERO_H
#define TABLERO_H

#include <QMainWindow>
#include <QDebug>
#include <QGraphicsScene>
#include <QTimer>
#include <QKeyEvent>
#include <QVector>
#include <QList>
#include <QMap>
#include <stdlib.h>
#include <QtMultimedia>
#include <QSoundEffect>
#include <QAudioOutput>
#include <QMediaPlayer>

#include "personaje.h"
#include "muro.h"
#include "proyectil.h"
#include "enemigo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Tablero; }
QT_END_NAMESPACE

class QMediaPlayer;

class Tablero : public QMainWindow
{
    Q_OBJECT

public:
    Tablero(QWidget *parent = nullptr);
    ~Tablero();
    void keyPressEvent(QKeyEvent *event);

    void crearMapa(void);

public slots:
    void onStart(void);
    void actualizar();
    void spawn();

private:
    int subtest = 0;
    Ui::Tablero *ui;
    QGraphicsScene *scene;
    QTimer *tiempo;
    int test=0;
    Personaje *pj;
    enemigo *p2;
    QVector<Muro *> Muros;
    QMap<int, enemigo *> creyente;

    QMediaPlayer *player;
    QAudioOutput *salida;

};
#endif // TABLERO_H








