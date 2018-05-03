#include "widget.h"
#include "ui_widget.h"
#include <Windows.h>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget), board("New Board")
{
    ui->setupUi(this);
    setAcceptDrops(true);
    setAutoFillBackground(true);
    cycle=false;
    state=1;
}

Widget::~Widget()
{
    if(chosen!=NULL){
        delete chosen;
    }
    delete ui;
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        if(chosen==NULL){
            chosen = static_cast<QBlock*>(childAt(event->pos()));
        } else {
            chosen->move(event->pos());
            chosen=NULL;
            update();
        }

    }
    else if(event->button() == Qt::RightButton){
        if(chosen==NULL){
            chosen = static_cast<QBlock*>(childAt(event->pos()));
        } else {
            QBlock *second = static_cast<QBlock*>(childAt(event->pos()));
            if(chosen!=second){
                second->block.calculate();
                chosen->block.calculate();
                std::cerr << second->block.getOutputPorts()[0].getValue() << std::endl;
                std::cerr << chosen->block.getOutputPorts()[0].getValue() << std::endl;
                chosen=NULL;
            }
        }
    }
}

void Widget::on_create_clicked()
{
    Block block;
    Port port("nam",1.0);
    Port port1("val");
    block.addInputPort(port);
    block.addOutputPort(port1);
    board.addBlock(block);
    QBlock *lab= new QBlock(this,block);
    lab->move(150,150);
    std::cerr << block;
}

void Widget::on_pushButton_2_clicked()
{
    bool ok;
    double d = QInputDialog::getDouble(this, tr("QInputDialog::getDouble()"),
                                       tr("Amount:"), 37.56, -10000, 10000, 2, &ok);
    if(d){

    }
}

void Widget::keyPressEvent(QKeyEvent *event){
    if(chosen and (event->key()==Qt::Key_Delete or event->key()==Qt::Key_D)){
        board.delBlock(chosen->block);
        std::cerr << "new " << std::endl;
        delete chosen;
        chosen=NULL;
        update();
    }
}

void Widget::on_pushButton_clicked()
{
    try{
        Connection con(board.getBlocks()[0],board.getBlocks()[0].getOutputPorts()[0],board.getBlocks()[1],board.getBlocks()[1].getInputPorts()[0]);
        for(Connection save:board.getConnections()){
            if(save==con){
                board.delConnection(save);
                std::cerr << board.getConnections().size();
                update();
                return;
            }
        }
        board.addConnection(con);
        std::cerr << board.getConnections().size();
    } catch(int n){
        if(n==1){
            QMessageBox::information(this, tr("QMessageBox::information()"), "Nelze spojit blok sám se sebou.");
        }
    }
}

void Widget::on_pushButton_3_clicked()
{
    bool tf = detectCycle();
    cycle=tf;
    std::cerr << tf << std::endl;
    calculateAll(0);
}

bool Widget::detectCycle(){
    std::set<Block> set;
    std::vector<Connection> cons = board.getConnections();
    for(std::vector<Connection>::iterator s=cons.begin();s!=cons.end();++s){
        if(set.count(s->getBlockOut())){
            return true;
        } else {
            set.insert(s->getBlockIn());
        }
    }
    return false;
}

void Widget::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.fillRect(this->rect(),Qt::white);

    QList<QBlock *> blocks = findChildren<QBlock *>(QString(),Qt::FindDirectChildrenOnly);

    std::cerr << blocks.size() << std::endl;
    for(Connection con : board.getConnections()){
        for(QBlock *bl : blocks){
            if(con.getBlockOut()==bl->block){
                if(draw!=NULL){
                    painter.drawLine(draw->x(),draw->y(),bl->x(),bl->y());
                    std::cerr << draw->x() << draw->y() << " " << bl->x() << bl->y() << std::endl;
                }
            } else if(con.getBlockIn()==bl->block){
                std::cerr << "de" << std::endl;
                draw=bl;
            } else {

            }
        }
    }
}

void Widget::calculateAll(int step){
    if(step){
        if(step>board.getBlocks().size()){
            state=1;
            count->setGeometry(count->x(),count->y(),50,50);
            count->repaint();
            count=NULL;
            return;
        }
        Block b =board.getBlocks()[state-1];
        QList<QBlock *> blocks = findChildren<QBlock *>(QString(),Qt::FindDirectChildrenOnly);
        for(QBlock *bl : blocks){
            if(bl->block==b){
                if(count!=NULL){
                    count->setGeometry(count->x(),count->y(),50,50);
                    count->repaint();
                }
                count = bl;
                bl->setGeometry(bl->x(),bl->y(),25,25);
                bl->repaint();
                break;
            }
        }
        b.calculate();
        state++;
    } else {
        count = NULL;
        for(Block b : board.getBlocks()){
            QList<QBlock *> blocks = findChildren<QBlock *>(QString(),Qt::FindDirectChildrenOnly);
            for(QBlock * bl: blocks){
                if(bl->block==b){
                    if(count){
                        count->setGeometry(count->x(),count->y(),50,50);
                        count->repaint();
                    }
                    count = bl;
                    bl->setGeometry(bl->x(),bl->y(),25,25);
                    bl->repaint();
                    Sleep(500);
                }
            }
            b.calculate();
            //TODO prenos
        }
        count->setGeometry(count->x(),count->y(),50,50);
    }
}

void Widget::on_pushButton_4_clicked()
{
    calculateAll(state);
}
