/** Board.h
 *
 *  Jakub Pagáè xpagac06
 *  Jan Novák xnovak1s
 */
#ifndef BOARD_H
#define BOARD_H

#include "connection.h"
#include <set>
///< /brief Tøída reprezentující schéma
class Board
{
public:
    /// \brief Vytvoøí schéma
    ///
    /// \param Jméno schématu
    ///
    Board(std::string nam);
    /// \brief Získá jméno schématu
    ///
    /// \return Vrací jméno schématu
    ///
    std::string getName(){return name;}
    /// \brief Získá bloky ve schématu
    ///
    /// \return Vrací vector blokù v schématu
    ///
    std::vector<Block> &getBlocks() {return blocks;}
    /// \brief Získa vector spojù v schématu
    ///
    /// \return Vrací vector spojù v schématu
    ///
    std::vector<Connection> &getConnections() {return connections;}
    /// \brief Nastaví jméno schématu
    ///
    /// \param Jméno schématu
    ///
    void setName(std::string nam){name=nam;}
    /// \brief Pøidá blok do schématu
    ///
    /// \param Blok, který má být pøidán
    ///
    void addBlock(Block block){blocks.push_back(block);}
    /// \brief Pøidá spoj do schématu
    ///
    /// \param Spoj, který má být pøidán
    ///
    void addConnection(Connection con){connections.push_back(con);}
    /// \brief Smaže spoj ze schématu
    ///
    /// \param Spoj, který má být smazán
    ///
    void delConnection(Connection con);
    /// \brief Smaže blok a spoje jejichž byl souèástí
    ///
    /// \param Blok, který má být smazán
    ///
    void delBlock(Block block);
    /// \brief Vyèistí schémá od blokù a spojù
    ///
    void clearBoard(){blocks.clear(); connections.clear();name="new Board";}
    /// \brief Smaže bloky ze schématu
    ///
    void clearBlocks(){blocks.clear();}
    /// \brief Zjistí, které porty jsou nenapojené
    ///
    void setupOrder();
    /// \brief Získá vektor nenapojených portù
    ///
    /// \return Vrací vektor nenapojených portù
    ///
    std::vector<Port> getInputPorts(){return forInput;}
private:
    ///< /brief Jméno schématu
    std::string name;
    ///< /brief Bloky ve schématu
    std::vector<Block> blocks;
    ///< /brief Spoje ve schématu
    std::vector<Connection> connections;
    ///< /brief Nenapojené porty
    std::vector<Port> forInput;
};

#endif // BOARD_H
