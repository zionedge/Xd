/** Connection.h
 *
 *  Jakub Pagáč xpagac06
 *  Jan Novák xnovak1s
 */
#ifndef CONNECTION_H
#define CONNECTION_H

#include "block.h"
///< /brief Třída reprezentující spoj bloků
class Connection
{
public:
    /// \brief Vytvoři spoj dvou bloků
    ///
    /// \param Výstupní blok
    /// \param Výstupní port
    /// \param Vstupní blok
    /// \param Vstupní port
    ///
    Connection(Block bOut, Port pOut, Block bIn, Port pIn);
    /// \brief Přetšžení operátoru ==
    ///
    /// \param Spoj k porovnání
    /// \return Vrací true pokud spoje spojují stejné bloky
    ///
    bool operator==(const Connection& other) const;
    /// \brief Získá výstupní port spoje
    ///
    /// \return Vrací výstupní port spoje
    ///
    Port getPortOut()const{return portOut;}
    /// \brief Získá vstupní port spoje
    ///
    /// \return Vrací vstupní port spoje
    ///
    Port getPortIn()const{return portIn;}
    /// \brief Získá výstpuní blok spoje
    ///
    /// \return Vrací výstupní blok spoje
    ///
    Block getBlockOut()const{return blockOut;}
    /// \brief Získá vstupní blok spoje
    ///
    /// \return Vrací vstupní blok spoje
    ///
    Block getBlockIn()const{return blockIn;}
    /// \brief Přetšžení operátoru <<
    ///
    friend std::ostream &operator<<(std::ostream &os, Connection const &cn);
private:
    ///< /brief Čítač spojů
    static int cnt;
    ///< /brief ID spoje
    int id;
    ///< /brief Výstupní port
    Port portOut;
    ///< /brief Vstupní port
    Port portIn;
    ///< /brief Výstupní blok
    Block blockOut;
    ///< /brief Vstupní blok
    Block blockIn;
};

#endif // CONNECTION_H
