/** Qblock.cpp
 *
 *  Jakub Pagáè xpagac06
 *  Jan Novák xnovak1s
 */
#include "qblock.h"

QBlock::QBlock(QWidget *parent, Block bl, int blockType) :
    QLabel(parent),block(blockType)
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
    delete modal;
}

void QBlock::enterEvent(QEvent *event){
    QString in = QString::number(block.getInputPorts()[0].getValue());
    QString in2 = QString::number(block.getInputPorts()[1].getValue());
    QString out = QString::number(block.getOutputPorts()[0].getValue());
    QString op = QString::fromStdString(block.getOp());
    modal->show();
    modal->setLabels(in,in2,out,op);
    if(x()<50 and y()<120){
       modal->setGeometry(QRect(x()+50,y()+50,160,120));
    } else if(y()<120){
       modal->setGeometry(QRect(x(),y()+50,160,120));
    } else if(x()<50){
       modal->setGeometry(QRect(x()+50,y(),160,120));
    } else {
        modal->setGeometry(QRect(x()-50,y()-120,160,120));
    }
    modal->raise();
    QWidget::enterEvent(event);
}

void QBlock::leaveEvent(QEvent *event){
    modal->hide();
    QWidget::leaveEvent(event);
}
