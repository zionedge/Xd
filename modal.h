#ifndef MODAL_H
#define MODAL_H

#include <QWidget>

namespace Ui {
class Modal;
}

class Modal : public QWidget
{
    Q_OBJECT

public:
    explicit Modal(QWidget *parent = 0);
    ~Modal();

private:
    Ui::Modal *ui;
};

#endif // MODAL_H