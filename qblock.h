#ifndef QBLOCK_H
#define QBLOCK_H

#include <QLabel>
#include <QFrame>
#include <QtWidgets>
#include "block.h"
#include "modal.h"

class QBlock : public QLabel
{
public:
    QBlock(QWidget *parent, Block bl, int blockType);
    ~QBlock();
    Block block;
    Modal* modal;
protected:
    void enterEvent(QEvent * event);
    void leaveEvent(QEvent * event);
};

#endif // QBLOCK_H
