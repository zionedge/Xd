/** Block.h
 *
 *  Jakub Pag�� xpagac06
 *  Jan Nov�k xnovak1s
 */
#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include <algorithm>
#include <iostream>
#include "port.h"

/**< \brief T��da Block  */
class Block
{
public:
    /// \brief Vytvo�� blok
    ///
    /// \param type Typ operace, kterou bude blok prov�d�t
    ///
    Block(int type);
    /// \brief Destruktor pro blok
    ///
    ~Block();
    /// \brief Z�sk� ID bloku
    ///
    /// \return Vrac� ID bloku
    ///
    int getId() const{return id;}
    /// \brief Z�sk� operaci bloku
    ///
    /// \return Vrac� oper�tor reprezentovan� �et�zcem
    ///
    std::string getOp() const{return op;}
    /// \brief P�et�en� oper�toru == pro objekty t��dy Block
    ///
    /// \param Blok pro porovn�n�
    /// \return Vrac� true kdy� bloky maj� stejn� ID
    ///
    bool operator==(const Block& other) const;
    /// \brief P�et�en� oper�toru < pro objekty t��dy Block
    ///
    /// \param Blok pro porovn�n�
    /// \return Vrac� true kdy� blok prvn� blok m� men�� ID ne� druh�
    ///
    bool operator<(const Block& other) const;
    /// \brief P�et�en� oper�toru != pro objekty t��dy Block
    ///
    /// \param Blok pro porovn�n�
    /// \return Vrac� true kdy� bloky maj� r�zn� ID
    ///
    bool operator!=(const Block& other) const;
    /// \brief P�i�ad� port k bloku jako vstupn� port
    ///
    /// \param Port pro p�id�n�
    ///
    void addInputPort(Port input){this->inputPorts.push_back(input);}
    /// \brief P�i�ad� port k bloku jako v�stupn� port
    ///
    /// \param Port pro p�id�n�
    ///
    void addOutputPort(Port output){this->outputPorts.push_back(output);}
    /// \brief Vyhled� port v bloku a sma�e ho
    ///
    /// \param Port pro smaz�n�
    ///
    void delPort(Port port);
    /// \brief Z�sk� vector vstupn�ch port�
    ///
    /// \return Vrac� m�niteln� vector vstupn�ch port�
    ///
    std::vector<Port> &getInputPorts() {return inputPorts;}
    /// \brief Z�sk� vector v�stupn�ch port�
    ///
    /// \return Vrac� m�niteln� vector v�stupn�ch port�
    ///
    std::vector<Port> &getOutputPorts() {return outputPorts;}
    /// \brief Z�sk� vector vstupn�ch port�
    ///
    /// \return Vrac� vector vstupn�ch port�
    ///
    std::vector<Port> getConstInputPorts() const{return inputPorts;}
    /// \brief Z�sk� vector v�stupn�ch port�
    ///
    /// \return Vrac� vector v�stupn�ch port�
    ///
    std::vector<Port> getConstOutputPorts() const{return outputPorts;}
    /// \brief Vypo��t� hodnotu bloku
    ///
    void calculate();
    /// \brief P�et�en� oper�toru <<
    ///
    friend std::ostream &operator<<(std::ostream &os, Block const &bl);
private:
    ///< /var ��ta� blok�
    static int cnt;
    ///< /brief ID bloku
    int id;
    ///< /brief Oper�tor bloku
    std::string op;
    ///< /brief Vector vstupn�ch port�
    std::vector<Port> inputPorts;
    ///< /brief Vector v�stupn�ch port�
    std::vector<Port> outputPorts;
};

#endif // BLOCK_H
