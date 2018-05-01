#include "qblock.h"

QBlock::QBlock(QWidget *parent) :
    QLabel(parent)
{
    this->setGeometry(QRect(100,100,50,50));
    QPixmap pix;
    pix.load(":/res.png");
    this->setPixmap(pix);
    this->show();
    this->setMouseTracking(true);
}

void QBlock::mouseMoveEvent(QMouseEvent *event){
    if(this->rect().contains(event->pos())){
        //this->move(210,210);
    } else {
        event->ignore();
    }
}
