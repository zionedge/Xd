/** Qblock.h
 *
 *  Jakub Pagáč xpagac06
 *  Jan Novák xnovak1s
 */
#ifndef QBLOCK_H
#define QBLOCK_H

#include <QLabel>
#include <QFrame>
#include <QtWidgets>
#include "block.h"
#include "modal.h"
///< \brief Třída vizuálně reprezentující blok ve schématu
class QBlock : public QLabel
{
public:
    ///< \brief Vytvoří zobrazitelný blok
    QBlock(QWidget *parent, Block bl, int blockType);
    ///< \brief Destruktor
    ~QBlock();
    ///< \brief Blok, jež reprezentuje
    Block block;
    ///< \brief Okno pro stav bloku
    Modal* modal;
protected:
    ///< \brief Najetí myší na blok
    void enterEvent(QEvent * event);
    ///< \brief Vyjetí myší pryč z bloku
    void leaveEvent(QEvent * event);
};

#endif // QBLOCK_H
