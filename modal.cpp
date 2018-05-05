#include "modal.h"
#include "ui_modal.h"

Modal::Modal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Modal)
{
    ui->setupUi(this);
}

Modal::~Modal()
{
    delete ui;
}

void Modal::setLabels(QString in, QString out, QString op){
    ui->label_2->setText(in);
    ui->label_4->setText(out);
    ui->label_6->setText(op);
}
