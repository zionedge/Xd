#include "qblock.h"

QBlock::QBlock(QWidget *parent, Block bl) :
    QLabel(parent),block()
{
    modal = new Modal(parentWidget());
    block=bl;
    this->setGeometry(QRect(100,100,50,50));
    QPixmap pix;
    pix.load(":/res.png");
    this->setPixmap(pix);
    this->show();
    this->setMouseTracking(true);
}

QBlock::~QBlock(){
    if(modal!=NULL){
        delete modal;
    }
}

/*
void QBlock::mouseMoveEvent(QMouseEvent *event){
    if(this->rect().contains(event->pos())){

    } else {

        event->ignore();
    }
}
*/

void QBlock::enterEvent(QEvent *event){
    modal->show();
    modal->setGeometry(QRect(x()-50,y()-85,160,82));
    QWidget::enterEvent(event);
}

void QBlock::leaveEvent(QEvent *event){
    modal->hide();
    QWidget::leaveEvent(event);
}
