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
