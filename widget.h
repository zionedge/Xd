#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMimeData>
#include <QLabel>
#include <QtWidgets>
#include <QToolBar>
#include <set>
#include <fstream>
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
    bool detectCycle();
    void calculateAll(int step);
    void paintEvent(QPaintEvent *);
    void getValues();

protected:
    void mousePressEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
private slots:
    void on_create_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void saveFile(QString);

private:
    Ui::Widget *ui;
    Board board;
    QBlock* chosen=NULL;
    QBlock* draw=NULL;
    QBlock* count=NULL;
    std::string mode;
    bool cycle;
    int state;
};

#endif // WIDGET_H
