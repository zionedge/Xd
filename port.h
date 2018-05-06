/** Port.h
 *
 *  Jakub Pagáč xpagac06
 *  Jan Novák xnovak1s
 */
#ifndef PORT_H
#define PORT_H

#include <string>
#include <cmath>
#include <iostream>

///< /brief Třída reprezentující port bloku
class Port
{
public:
    ///< /brief Vytvoří port s defaultní hodnotou NAN
    Port(std::string nam);
    ///< /brief Vytovří port a přiřadí mu hodnotu
    Port(std::string nam, double val);
    /// \brief Získá hodnotu portu
    ///
    /// \return Vrací hodnotu portu
    ///
    double getValue() const {return value;}
    /// \brief Získá jméno portu
    ///
    /// \return Vrací jméno portu
    ///
    std::string getName() const {return name;}
    /// \brief Získá ID portu
    ///
    /// \return Vrací ID portu
    ///
    int getId() const {return id;}
    /// \brief Nastaví hodnotu portu
    ///
    /// \param Požadovaná hodnota
    ///
    void setValue(double val){value=val;}
    /// \brief Nastaví jméno portu
    ///
    /// \return Požadované jméno
    ///
    void setName(std::string nam){name=nam;}
    /// \brief Přetížení operátoru ==
    ///
    /// \param Druhý port
    /// \return Vrací true, jestli se ID portů shodují
    ///
    bool operator==(const Port& other) const{
        if(this->id==other.id)
            return true;
        else
            return false;
    }
    /// \brief Přetížení operátoru <<
    ///
    friend std::ostream &operator<<(std::ostream &os, Port const &port);
private:
    ///< \brief Čítač portů
    static int cnt;
    ///< \brief ID portu
    int id;
    ///< \brief Jméno portu
    std::string name;
    ///< \brief Hodnota portu
    double value;
};

#endif // PORT_H
