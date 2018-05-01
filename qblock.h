#ifndef QBLOCK_H
#define QBLOCK_H

#include <QLabel>
#include <QFrame>
#include <QtWidgets>

class QBlock : public QLabel
{
public:
    QBlock(QWidget *parent);
protected:
    void mouseMoveEvent(QMouseEvent *event);
private:

};

#endif // QBLOCK_H
