#include "qblock.h"

QBlock::QBlock(QWidget *parent, Block bl, int blockType) :
    QLabel(parent),block()
{
    modal = new Modal(parentWidget());
    block=bl;
    this->setGeometry(QRect(100,100,50,50));
    QPixmap pix;
    switch(blockType){
    case 1:
        pix.load(":/plus.png");
        break;
    case 2:
        pix.load(":/mul.png");
        break;
    case 3:
        pix.load(":/max.png");
        break;
    case 4:
        pix.load(":/min.png");
        break;
    case 5:
        pix.load(":/pyth.png");
        break;
    }
    this->setPixmap(pix);
    this->show();
    this->setMouseTracking(true);
}

QBlock::~QBlock(){
    if(modal!=NULL){
        delete modal;
    }
}

void QBlock::enterEvent(QEvent *event){
    modal->show();
    modal->setGeometry(QRect(x()-50,y()-85,160,82));
    QWidget::enterEvent(event);
}

void QBlock::leaveEvent(QEvent *event){
    modal->hide();
    QWidget::leaveEvent(event);
}
