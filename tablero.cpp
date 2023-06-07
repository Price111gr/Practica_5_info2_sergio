#include "tablero.h"
#include "ui_tablero.h"

Tablero::Tablero(QWidget *parent) : QMainWindow(parent) , ui(new Ui::Tablero)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,600,500);
    ui->graphicsView->setScene(scene);

    pj = nullptr;
    //pro = nullptr;

    player = new QMediaPlayer;
    salida = new QAudioOutput;



    QMediaPlayer * player = new QMediaPlayer();
    player->setMedia(QUrl("qrc:/musica/Blood Red.mp3"));
    player->play();


    connect(ui->pB_start, &QPushButton::clicked, this, &Tablero::onStart);
    scene->setBackgroundBrush(QBrush(QImage(":/Sprites/slayer_0.jpg").scaled(600,500)));
}

Tablero::~Tablero()
{
    creyente.clear();
    pj->Proyectiles.clear();
    delete ui;
}

void Tablero::keyPressEvent(QKeyEvent *event)
{
    if(pj!=nullptr){
        if(event->key()==Qt::Key_W){
            pj->setVy(-20);
            pj->setVx(0);
        }else if(event->key()==Qt::Key_S){
            pj->setVy(20);
            pj->setVx(0);
        }else if(event->key()==Qt::Key_P){
            auto p = pj->disparar();
            if(p!=nullptr){
                scene->addItem(p);
            }


        }else if(event->key()==Qt::Key_Space){
            pj->setVx(0);
            pj->setVy(0);
        }
    }
}

void Tablero::onStart()
{
    player->stop();

    scene->setBackgroundBrush(QBrush(QImage(":/Sprites/back (1).png")/*.scaled(400,400)*/));
    pj = new Personaje;
    scene->addItem(pj);


    tiempo = new QTimer;
    tiempo->start(100);


   // player->setMedia(QUrl("qrc:/musica/Piece By Piece.mp3"));
    //player->play();

    connect(tiempo, &QTimer::timeout,
            this, &Tablero::actualizar);

    QTimer *tiempoenemigo = new QTimer();
    connect(tiempoenemigo,SIGNAL(timeout()),this,SLOT(spawn()));
    tiempoenemigo->start(4000);



    ui->pB_start->hide();
}

void Tablero::actualizar(){
    pj->move();

    for(auto it: creyente){
        it->mover();
    }



    if(pj->getPy()<0){pj->setVy(5);};

    if(pj->getPy()>scene->height()-40){pj->setVy(-5);};

    /*for(auto itr = creyente.begin(); itr != creyente.end(); ++itr){
        auto it=itr.value();
    }*/

    QList<QGraphicsItem*> Colisiones = scene->collidingItems(pj);
    if(!Colisiones.isEmpty()){
        //qDebug()<<"Colision";
        for(auto c : Colisiones){
            Muro *muro = dynamic_cast<Muro *>(c);
            if(muro){
                qDebug()<<"Muro";
            }

            Proyectil *proyectil = dynamic_cast<Proyectil *>(c);
            if(proyectil){
                qDebug()<<"Proyectil";
            }

            enemigo *creyentes = dynamic_cast<enemigo *>(c);
            if(creyentes){
                qDebug()<<"golpe a jugador";
                qDebug()<<"creyente escena";
                //scene->removeItem(creyente);
                qDebug()<<"creyente vector";
                //creyente.clear();

            }





            for(auto loco: creyente){
                if((!loco->collidingItems().isEmpty())){
                    for(auto bala: pj->Proyectiles){
                        if(loco->collidingItems().first() == bala){

                            qDebug()<<"choque";
                            qDebug()<<"bala escena";
                            ///scene->removeItem(bala);
                            qDebug()<<"bala vector";
                            //pj->Proyectiles.erase(bala);

                            qDebug()<<"creyente escena";
                            //scene->removeItem(loco);
                            qDebug()<<"creyente vector";
                            //creyente.removeOne(loco);

                        }
                    }
                }
            }

            for(auto itr = pj->Proyectiles.begin(); itr!= pj->Proyectiles.end(); ++itr){
                auto it=itr.value();

                    if(it->getPx()>scene->width()-1){
                        qDebug()<<"bala escena";
                        scene->removeItem(it);
                        qDebug()<<"bala vector";
                        itr = pj->Proyectiles.erase(itr);
                    }
                    for(auto loco = creyente.begin(); loco != creyente.end(); ++loco){
                        auto loc=loco.value();

                        if(it->collidesWithItem(loc)){
                            qDebug()<<"bala escena";
                            scene->removeItem(it);
                            qDebug()<<"bala vector";
                            itr = pj->Proyectiles.erase(itr);

                            qDebug()<<"bala escena";
                            scene->removeItem(loc);
                            qDebug()<<"bala vector";
                            loco = creyente.erase(loco);

                        }
                    }

            }

           /* for(auto itr = pj->Proyectiles.begin(); itr != pj->Proyectiles.end(); ++itr){
                auto ap= itr.value();
            }

            for(auto bala: pj->Proyectiles){
                if(!bala->collidingItems().isEmpty()){
                    for(auto loco: creyente){
                        if(bala->collidesWithItem(loco)){

                            qDebug()<<"creyente escena";
                            scene->removeItem(loco);
                            qDebug()<<"creyente vector";
                            //creyente.removeOne(loco);


                            qDebug()<<"choque";
                            qDebug()<<"bala escena";
                            scene->removeItem(bala);
                            qDebug()<<"bala vector";
                            //pj->Proyectiles.removeOne(bala);


                        }
                    }
                }
            }*/


        }
    }
    for(auto itr = pj->Proyectiles.begin(); itr!= pj->Proyectiles.end(); ++itr){
        auto it=itr.value();
        if(itr.value()!=0){
            if(it->getPx()>scene->width()-1){
                 qDebug()<<"bala escena";
                 scene->removeItem(it);
                 qDebug()<<"bala vector";
                 itr = pj->Proyectiles.erase(itr);
            }
        }
    }

}

void Tablero::spawn(){
    int posy =20 + rand()%(281-1);

    creyente.insert(test , new enemigo(490,posy,-20,80));

    scene->addItem(creyente.last());

}
/*
 *
 *    float _vx, _vy;

        _vx=vx+20;

    Proyectiles.insert(test , new Proyectil(px,py,_vx,_vy));
        //return Proyectiles.last();
       // Proyectiles.insert(test ,new Proyectil(px,py,_vx,_vy));
        int ap=test;
        test++;
        auto it= Proyectiles.value(ap);
        return it;
 *
 *
 *
 *
 * void Tablero::crearMapa(){
    // Algortimo logico => ciclo, archivo, random
    for(int i=0; i<20; i++){
        for(int j=0; j<20; j++){
            if(i==0 && j==0){
                Mapa[i][j] = 1;
                continue;
            }

            if(i==0 && j==10){
                Mapa[i][j]=1;
            }else{
                Mapa[i][j]=0;
            }
        }
    }



    // Parte grafico
    for(int i=0; i<20; i++){
        for(int j=0; j<20; j++){
            if(Mapa[i][j]==1){
                Muros.push_back(new Muro(i*30,j*30));
                scene->addItem(Muros.last());
            }
        }
    }
}*/



/*    for(auto bala = balas.begin() ;bala != balas.end(); ++bala){
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



            for(auto bala: pj->Proyectiles){
                if((!bala->collidingItems().isEmpty())){
                    for(auto loco: creyente){
                        if(bala->collidingItems().first() == creyente){

                            qDebug()<<"choque";
                            qDebug()<<"bala escena";
                            scene->removeItem(bala);
                            qDebug()<<"bala vector";
                            pj->Proyectiles.removeOne(bala);

                            qDebug()<<"creyente escena";
                            scene->removeItem(loco);
                            qDebug()<<"creyente vector";
                            creyente.removeOne(loco);

                        }
                    }
                }
            }















*/







