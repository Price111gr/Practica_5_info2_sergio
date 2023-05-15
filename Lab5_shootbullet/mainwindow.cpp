#include "mainwindow.h"
#include "ui_mainwindow.h"

char MainWindow::getLetraPulse() const
{
    return letraPulse;
}

void MainWindow::setLetraPulse(char newLetraPulse)
{
    letraPulse = newLetraPulse;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene =  new QGraphicsScene();
    scene->setSceneRect(0,0,500,500);
    ui->graphicsView->setScene(scene);
    scene->addRect(scene->sceneRect());





    int mapatriz[11][9]={{1, 1, 1, 1, 1, 1, 1, 1, 1},
                       {1, 0, 0, 2, 2, 2, 2, 2, 1},
                       {1, 0, 1, 2, 1, 2, 1, 2, 1},
                       {1, 2, 2, 2, 2, 2, 2, 2, 1},
                       {1, 2, 1, 2, 1, 2, 1, 2, 1},
                       {1, 2, 2, 2, 2, 2, 2, 2, 1},
                       {1, 2, 1, 2, 1, 2, 1, 2, 1},
                       {1, 2, 2, 2, 2, 2, 2, 2, 1},
                       {1, 2, 1, 2, 1, 2, 1, 2, 1},
                       {1, 2, 2, 2, 2, 2, 2, 2, 1},
                       {1, 1, 1, 1, 1, 1, 1, 1, 1}};

    for (int var = 0; var < 11; var++) {

        for (int var2 = 0; var2 < 9; var2++){

            if(mapatriz[var][var2]==1){
                Muro.push_back(new Muros(30*var,30*var2, 1));
                scene->addItem(Muro.last());
            }
            else if(mapatriz[var][var2]==2){
                Muro.push_back(new Muros(30*var,30*var2, 2));
                scene->addItem(Muro.last());
            }
        }
    }

    jugador = new soldado();
    jugador->posicion(26,11);
    scene->addItem(jugador);
    vel=5;
    vel_auto=1;

    timer =  new QTimer;
    connect(timer,SIGNAL(timeout()),this, SLOT(hmov()));

    timer_bullet =  new QTimer;
    connect(timer_bullet,SIGNAL(timeout()),this, SLOT(bullet_mov()));

    timer->stop();
    timer_bullet->stop();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*void MainWindow::keyPressEvent(QKeyEvent *event)
{

    if(event->key()==Qt::Key_W  && blokW==0){
        setLetraPulse('W');
        jugador->MoveUp();
        blokA=0;
        blokS=0;
        blokD=0;
    } else if(event->key()==Qt::Key_S  && blokS==0){
        setLetraPulse('S');
        jugador->MoveDown();
        blokA=0;
        blokW=0;
        blokD=0;
    }else if(event->key()==Qt::Key_D   && blokD==0){
        setLetraPulse('D');
        jugador->MoveRight();
        blokA=0;
        blokS=0;
        blokW=0;
    }else if(event->key()==Qt::Key_A   && blokA==0){
        setLetraPulse('A');
        jugador->MoveLeft();
        blokW=0;
        blokS=0;
        blokD=0;
    }
}*/

void MainWindow::keyPressEvent(QKeyEvent *event){
    if(event->key()== Qt::Key_F4) close();

    if(event->key()== Qt::Key_A && jugador->getX()>0){
        if (!jugador->collidesWithItem(Qvector <Muros>)) jugador->setX(jugador->getX()-vel);
        else jugador->setX(jugador->getX()+vel);
        qDebug() << "Posicion actual: " << jugador->getX();

    }

    if(event->key()== Qt::Key_S && jugador->getY()<scene->height()-55){
        jugador->setY(jugador->getY()+vel);
        qDebug() << "Posicion actual: " << jugador->getY();
    }

    if(event->key()== Qt::Key_D && jugador->getX()<scene->width()-36){
        jugador->setX(jugador->getX()+vel);
        qDebug() << "Posicion actual: " << jugador->getX();

    }

    if(event->key()== Qt::Key_W && jugador->getY()>0){
        jugador->setY(jugador->getY()-vel);
        qDebug() << "Posicion actual: " << jugador->getY();

    }

    if (event->key()== Qt::Key_K){
        disparo();
    }

    if(event->key()== Qt::Key_M){
        if(timer->isActive()) timer->stop();
        else timer->start(8);

    }
    if(event->key()==Qt::Key_Space) explote();
    jugador->posicion();
}

void MainWindow::explote()
{
    bombap= new bomba();
    bombap->posicion(player1->getX(),player1->getY());
    scene->addItem(bombap);

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(explotarbum()));
    timer->start(2500);
}


void MainWindow::disparo()
{
    balas.append(new bullet(10));
    balas.last()->posicion(jugador->getX(), jugador->getY());
    scene->addItem(balas.last());

    if(!timer_bullet->isActive()) timer_bullet->start(20);
}


void MainWindow::hmov()
{
    if(jugador->getX()<scene->width()-36) jugador->posicion(jugador->getX()+vel_auto,jugador->getY());
    else {
        vel_auto *= -1;
        jugador->posicion(scene->width()-36+vel_auto,jugador->getY());
    }

    if(jugador->getX()>0) jugador->posicion(jugador->getX()+vel_auto,jugador->getY());
    else {
        vel_auto *= -1;
        jugador->posicion(0+vel_auto,jugador->getY());
    }
}

void MainWindow::bullet_mov()
{
    for(auto bala = balas.begin() ;bala != balas.end(); ++bala){
        bala_temp = *bala;
        bala_temp->shot(-5);
        if (!bala_temp->collidingItems().isEmpty()){

            for(auto re = Muro.begin() ;re != Muro.end(); ++re){
                auto f1 = *re;
                if (bala_temp->collidingItems().first() == f1){

                    scene->removeItem(bala_temp);
                    balas.removeOne(bala_temp);

                    scene->removeItem(f1);
                    Muro.removeOne(f1);
                    break;
                }
            }
        }
        if (bala_temp->getY()<20){

            balas.removeOne(bala_temp);
            scene->removeItem(bala_temp);
        }

    }
}

//void MainWindow::colisiones()
//{
//    QList<QGraphicsItem *> Colisiones = scene->collidingItems(jugador);
//    if(!Colisiones.isEmpty()){
//        for(auto K:Colisiones){
//            Muros *muro=dynamic_cast<Muros *>(K);
//            if(muro){
//                if(muro->getMuroTipe()==1 && getLetraPulse()=='A'){
//                    blokA=1;
//                    jugador->setX(jugador->getX()-vel);
//                }else if(muro->getMuroTipe()==1 && getLetraPulse()=='D'){
//                    blokD=1;
//                    jugador->setX(jugador->getX()+vel);
//                }else if(muro->getMuroTipe()==1 && getLetraPulse()=='W'){
//                    blokW=1;
//                    jugador->setY(jugador->getY()-vel);
//                }else if(muro->getMuroTipe()==1 && getLetraPulse()=='S'){
//                    jugador->setY(jugador->getY()+vel);

//                }
//            }
//            }
//        }
//    }


