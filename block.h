/** Block.h
 *
 *  Jakub Pagáè xpagac06
 *  Jan Novák xnovak1s
 */
#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include <algorithm>
#include <iostream>
#include "port.h"

/**< \brief Tøída Block  */
class Block
{
public:
    /// \brief Vytvoøí blok
    ///
    /// \param type Typ operace, kterou bude blok provádìt
    ///
    Block(int type);
    /// \brief Destruktor pro blok
    ///
    ~Block();
    /// \brief Získá ID bloku
    ///
    /// \return Vrací ID bloku
    ///
    int getId() const{return id;}
    /// \brief Získá operaci bloku
    ///
    /// \return Vrací operátor reprezentovaný øetìzcem
    ///
    std::string getOp() const{return op;}
    /// \brief Pøetìžení operátoru == pro objekty tøídy Block
    ///
    /// \param Blok pro porovnání
    /// \return Vrací true když bloky mají stejné ID
    ///
    bool operator==(const Block& other) const;
    /// \brief Pøetìžení operátoru < pro objekty tøídy Block
    ///
    /// \param Blok pro porovnání
    /// \return Vrací true když blok první blok má menší ID než druhý
    ///
    bool operator<(const Block& other) const;
    /// \brief Pøetìžení operátoru != pro objekty tøídy Block
    ///
    /// \param Blok pro porovnání
    /// \return Vrací true když bloky mají rùzné ID
    ///
    bool operator!=(const Block& other) const;
    /// \brief Pøiøadí port k bloku jako vstupní port
    ///
    /// \param Port pro pøidání
    ///
    void addInputPort(Port input){this->inputPorts.push_back(input);}
    /// \brief Pøiøadí port k bloku jako výstupní port
    ///
    /// \param Port pro pøidání
    ///
    void addOutputPort(Port output){this->outputPorts.push_back(output);}
    /// \brief Vyhledá port v bloku a smaže ho
    ///
    /// \param Port pro smazání
    ///
    void delPort(Port port);
    /// \brief Získá vector vstupních portù
    ///
    /// \return Vrací mìnitelný vector vstupních portù
    ///
    std::vector<Port> &getInputPorts() {return inputPorts;}
    /// \brief Získá vector výstupních portù
    ///
    /// \return Vrací mìnitelný vector výstupních portù
    ///
    std::vector<Port> &getOutputPorts() {return outputPorts;}
    /// \brief Získá vector vstupních portù
    ///
    /// \return Vrací vector vstupních portù
    ///
    std::vector<Port> getConstInputPorts() const{return inputPorts;}
    /// \brief Získá vector výstupních portù
    ///
    /// \return Vrací vector výstupních portù
    ///
    std::vector<Port> getConstOutputPorts() const{return outputPorts;}
    /// \brief Vypoèítá hodnotu bloku
    ///
    void calculate();
    /// \brief Pøetìžení operátoru <<
    ///
    friend std::ostream &operator<<(std::ostream &os, Block const &bl);
private:
    ///< /var Èítaè blokù
    static int cnt;
    ///< /brief ID bloku
    int id;
    ///< /brief Operátor bloku
    std::string op;
    ///< /brief Vector vstupních portù
    std::vector<Port> inputPorts;
    ///< /brief Vector výstupních portù
    std::vector<Port> outputPorts;
};

#endif // BLOCK_H
