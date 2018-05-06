/** Board.h
 *
 *  Jakub Pag�� xpagac06
 *  Jan Nov�k xnovak1s
 */
#ifndef BOARD_H
#define BOARD_H

#include "connection.h"
#include <set>
///< /brief T��da reprezentuj�c� sch�ma
class Board
{
public:
    /// \brief Vytvo�� sch�ma
    ///
    /// \param Jm�no sch�matu
    ///
    Board(std::string nam);
    /// \brief Z�sk� jm�no sch�matu
    ///
    /// \return Vrac� jm�no sch�matu
    ///
    std::string getName(){return name;}
    /// \brief Z�sk� bloky ve sch�matu
    ///
    /// \return Vrac� vector blok� v sch�matu
    ///
    std::vector<Block> &getBlocks() {return blocks;}
    /// \brief Z�ska vector spoj� v sch�matu
    ///
    /// \return Vrac� vector spoj� v sch�matu
    ///
    std::vector<Connection> &getConnections() {return connections;}
    /// \brief Nastav� jm�no sch�matu
    ///
    /// \param Jm�no sch�matu
    ///
    void setName(std::string nam){name=nam;}
    /// \brief P�id� blok do sch�matu
    ///
    /// \param Blok, kter� m� b�t p�id�n
    ///
    void addBlock(Block block){blocks.push_back(block);}
    /// \brief P�id� spoj do sch�matu
    ///
    /// \param Spoj, kter� m� b�t p�id�n
    ///
    void addConnection(Connection con){connections.push_back(con);}
    /// \brief Sma�e spoj ze sch�matu
    ///
    /// \param Spoj, kter� m� b�t smaz�n
    ///
    void delConnection(Connection con);
    /// \brief Sma�e blok a spoje jejich� byl sou��st�
    ///
    /// \param Blok, kter� m� b�t smaz�n
    ///
    void delBlock(Block block);
    /// \brief Vy�ist� sch�m� od blok� a spoj�
    ///
    void clearBoard(){blocks.clear(); connections.clear();name="new Board";}
    /// \brief Sma�e bloky ze sch�matu
    ///
    void clearBlocks(){blocks.clear();}
    /// \brief Zjist�, kter� porty jsou nenapojen�
    ///
    void setupOrder();
    /// \brief Z�sk� vektor nenapojen�ch port�
    ///
    /// \return Vrac� vektor nenapojen�ch port�
    ///
    std::vector<Port> getInputPorts(){return forInput;}
private:
    ///< /brief Jm�no sch�matu
    std::string name;
    ///< /brief Bloky ve sch�matu
    std::vector<Block> blocks;
    ///< /brief Spoje ve sch�matu
    std::vector<Connection> connections;
    ///< /brief Nenapojen� porty
    std::vector<Port> forInput;
};

#endif // BOARD_H
