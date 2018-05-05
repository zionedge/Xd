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
            if(chosen==NULL)
                return;
            QPixmap map;
            map.load(":/chosenplus.png");
            chosen->setPixmap(map);
        } else {
            chosen->move(event->pos());
            QPixmap map;
            map.load(":/plus.png");
            chosen->setPixmap(map);
            chosen=NULL;
            update();
        }
    }
    else if(event->button() == Qt::RightButton){
        if(chosen==NULL){
            chosen = static_cast<QBlock*>(childAt(event->pos()));
            if(chosen==NULL)
                return;
            QPixmap map;
            map.load(":/chosenplus.png");
            chosen->setPixmap(map);
        } else {
            QBlock *second = static_cast<QBlock*>(childAt(event->pos()));
            if(second==NULL)
                return;
            if(chosen!=second){
                int chosenPorts = chosen->block.getConstOutputPorts().size();
                int secondPorts = second->block.getConstInputPorts().size();
                int chosencount = 0;
                int secondcount = 0;
                for(Connection con:board.getConnections()){
                    if(con.getBlockOut()==chosen->block){
                        chosencount++;
                    } else if(con.getBlockIn()==second->block){
                        secondcount++;
                    }
                }
                if(chosencount>=chosenPorts or secondcount>=secondPorts){
                    return;
                }
                std::cerr << chosen->block.getId() << " " << second->block.getId() << std::endl;
                Connection con(chosen->block,chosen->block.getOutputPorts()[chosencount],second->block,second->block.getInputPorts()[secondcount]);
                board.addConnection(con);
                if(detectCycle()){
                   QMessageBox::information(this, tr("Chyba při spojovani"), "Byl detekovan cyklus. Posledni spoj byl zrušen");
                   board.getConnections().pop_back();
                }
                std::cerr << board.getConnections().size() << std::endl;
                QPixmap map;
                map.load(":/plus.png");
                chosen->setPixmap(map);
                chosen=NULL;
                update();
            }
        }
    }
}

void Widget::on_create_clicked()
{
    Block block;
    Port port("nam");
    Port port1("val");
    Port port2("val");
    block.addInputPort(port);
    block.addInputPort(port2);
    block.addOutputPort(port1);
    board.addBlock(block);
    QBlock *lab= new QBlock(this,block,1);
    lab->move(150,150);
    update();
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
    } catch(int n){
        if(n==1){
            QMessageBox::information(this, tr("Chyba při spojovani"), "Nelze spojit blok sám se sebou.");
        }
    }
}

void Widget::on_pushButton_3_clicked()
{
    /*
    bool tf = detectCycle();
    cycle=tf;
    std::cerr << tf << std::endl;
    calculateAll(0);
    */
    QFileDialog *log = new QFileDialog(this);
    log->show();
    connect(log,SIGNAL(fileSelected(QString)),this,SLOT(saveFile(QString)));
}

void Widget::saveFile(QString file){

    //std::string file='\"'+fileName.toStdString()+'\"';
    //std::cerr << file << std::endl;
    //std::replace(file.begin(),file.end(),'/','\\');
    std::ofstream myfile(file.toStdString(), std::ios::out | std::ios::binary);
    if(!myfile.is_open()){
        std::cerr << "F" << std::endl;
        return;
    }
    //std::cerr << file << std::endl;
    myfile << "Hello world";
    myfile.close();

}

bool Widget::detectCycle(){
    std::set<Block> setIn;
    std::set<Block> setOut;
    std::vector<Connection> cons = board.getConnections();
    for(std::vector<Connection>::iterator s=cons.begin();s!=cons.end();++s){
        if(setOut.count(s->getBlockIn())){
            return true;
        } else {
            setOut.insert(s->getBlockOut());
            setIn.insert(s->getBlockIn());
        }
    }
    return false;
}

void Widget::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.fillRect(this->rect(),Qt::white);

    QList<QBlock *> blocks = findChildren<QBlock *>(QString(),Qt::FindDirectChildrenOnly);

    for(Connection con : board.getConnections()){
        for(QBlock *bl : blocks){
            if(con.getBlockOut()==bl->block){
                if(draw!=NULL){
                    painter.drawLine(draw->x()+25,draw->y()+25,bl->x()+25,bl->y()+25);
                    draw = NULL;
                } else {
                    draw=bl;
                }
            } else if(con.getBlockIn()==bl->block){
                if(draw!=NULL){
                    painter.drawLine(draw->x()+25,draw->y()+25,bl->x()+25,bl->y()+25);
                    draw = NULL;
                } else {
                    draw=bl;
                }
            } else {

            }
        }
    } 
}

void Widget::calculateAll(int step){
    if(step){
        if(step>board.getBlocks().size()){
            state=1;
            QPixmap map;
            map.load(":/plus.png");
            count->setPixmap(map);
            count->repaint();
            count=NULL;
            return;
        }
        Block b =board.getBlocks()[state-1];
        QList<QBlock *> blocks = findChildren<QBlock *>(QString(),Qt::FindDirectChildrenOnly);
        for(QBlock *bl : blocks){
            if(bl->block==b){
                if(count!=NULL){
                    QPixmap map;
                    map.load(":/plus.png");
                    count->setPixmap(map);
                    count->repaint();
                }
                count = bl;
                QPixmap map;
                map.load(":/highlightplus.png");
                bl->setPixmap(map);
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
                        QPixmap map;
                        map.load(":/plus.png");
                        count->setPixmap(map);
                        count->repaint();
                    }
                    count = bl;
                    QPixmap map;
                    map.load(":/highlightplus.png");
                    bl->setPixmap(map);
                    bl->repaint();
                    Sleep(500);
                }
            }
            b.calculate();
            //TODO prenos
        }
        QPixmap map;
        map.load(":/plus.png");
        count->setPixmap(map);
        count->repaint();
    }
}

void Widget::on_pushButton_4_clicked()
{
    calculateAll(state);
}
