/** Widget.h
 *
 *  Jakub Pagáč xpagac06
 *  Jan Novák xnovak1s
 */
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
///< \brief Hlavní okno programu
class Widget : public QWidget
{
    Q_OBJECT

public:
    ///< \brief Vytvoří okno
    explicit Widget(QWidget *parent = 0);
    ///< \brief Destruktor
    ~Widget();
    /// \brief Zjistí, zda se ve schématu vyskytuje cyklus
    /// \return Vrací true, pokud byl nalezen cyklus
    ///
    bool detectCycle();
    /// \brief Vypočítá hodnoty všech bloků
    ///
    /// \param Určuje, zda se bude jednat o výpočet s krokováním
    ///
    void calculateAll(unsigned int step);
    ///< \brief Vykresluje spoje mezi bloky
    void paintEvent(QPaintEvent *);
    ///<  \brief Získá hodnoty pro nezapojené porty
    void getValues();

protected:
    ///< \brief Přesouvání bloků, vytváření a mazání spojů
    void mousePressEvent(QMouseEvent *event);
    ///< \brief Mazání bloků
    void keyPressEvent(QKeyEvent *event);
private slots:
    ///< \brief Tlačítko pro vytvoření bloku
    void on_create_clicked();
    ///< \brief
    void on_pushButton_clicked();
    ///< \brief
    void on_pushButton_3_clicked();
    ///< \brief
    void on_pushButton_4_clicked();
    ///< \brief
    void on_pushButton_5_clicked();
    ///< \brief Ukládání schématu
    void saveFile(QString);
    ///< \brief Načítání schématu
    void loadFile(QString);

private:
    Ui::Widget *ui;
    ///< \brief Udržuje schéma
    Board board;
    ///< \brief Blok označený myší
    QBlock* chosen=NULL;
    ///< \brief Použito při krokování na překreslování bloků
    QBlock* draw=NULL;
    ///< \brief Udržuje zda byli nastaveny nespojené porty
    bool valSet;
    ///< \brief Udržuje stav při krokování
    unsigned int state;
};

#endif // WIDGET_H
