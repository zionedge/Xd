#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMimeData>
#include <QLabel>
#include <QtWidgets>
#include <QToolBar>
#include "qblock.h"
#include "board.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);
    void mousePressEvent(QMouseEvent *event);
private slots:
    void on_create_clicked();

private:
    Ui::Widget *ui;
    Board board;
    QBlock* chosen=NULL;
};

#endif // WIDGET_H
