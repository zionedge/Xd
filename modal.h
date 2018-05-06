/** Modal.h
 *
 *  Jakub Pagáč xpagac06
 *  Jan Novák xnovak1s
 */
#ifndef MODAL_H
#define MODAL_H

#include <QWidget>

namespace Ui {
class Modal;
}
///< /brief Třída pro zobrazení stavu bloku
class Modal : public QWidget
{
    Q_OBJECT

public:
    ///< /brief Vytvoří okno se stavem
    explicit Modal(QWidget *parent = 0);
    ///< /brief Zruší okno
    ~Modal();
    ///< /brief Nastaví hodnoty z bloku
    void setLabels(QString in, QString in2, QString out, QString op);

private:
    Ui::Modal *ui;
};

#endif // MODAL_H
