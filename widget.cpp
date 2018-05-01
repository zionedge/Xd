#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget), board("New Board")
{
    ui->setupUi(this);
    setAcceptDrops(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        QBlock *child = static_cast<QBlock*>(childAt(event->pos()));
        if (!child)
            return;

        QPixmap pixmap = *child->pixmap();

        QByteArray itemData;
        QDataStream dataStream(&itemData, QIODevice::WriteOnly);
        dataStream << pixmap << QPoint(event->pos() - child->pos());

        QMimeData *mimeData = new QMimeData;
        mimeData->setData("application/x-dnditemdata", itemData);

        QDrag *drag = new QDrag(this);
        drag->setMimeData(mimeData);
        drag->setPixmap(pixmap);
        drag->setHotSpot(event->pos() - child->pos());

        child->hide();

        if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction) {
            child->close();
        } else {
            child->show();
            child->setPixmap(pixmap);
        }
    }
    else if(event->button() == Qt::RightButton){
        if(chosen==NULL){
            chosen = static_cast<QBlock*>(childAt(event->pos()));
        } else {
            QBlock *second = static_cast<QBlock*>(childAt(event->pos()));
            if(chosen!=second){
                second->move(55,55);
                chosen=NULL;
            }
        }
    }
}

void Widget::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void Widget::dragMoveEvent(QDragMoveEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void Widget::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        QPixmap pixmap;
        QPoint offset;
        dataStream >> pixmap >> offset;

        QBlock *newIcon = new QBlock(this);
        newIcon->setPixmap(pixmap);
        newIcon->move(event->pos() - offset);
        newIcon->show();
        newIcon->setAttribute(Qt::WA_DeleteOnClose);
        newIcon->setMouseTracking(true);

        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void Widget::on_create_clicked()
{
    QBlock *lab= new QBlock(this);
    lab->move(150,150);
}
