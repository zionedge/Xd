#ifndef PORT_H
#define PORT_H

#include <string>
#include <cmath>
#include <iostream>

class Port
{
public:
    Port(std::string nam);
    Port(std::string nam, double val);
    ~Port();
    double getValue() const {return value;}
    std::string getName() const {return name;}
    int getId() const {return id;}
    void setValue(double val){value=val;}
    void setName(std::string nam){name=nam;}
    bool operator==(const Port& other) const{
        if(this->id==other.id)
            return true;
        else
            return false;
    }
    friend std::ostream &operator<<(std::ostream &os, Port const &port);
private:
    static int cnt;

    int id;
    std::string name;
    double value;
};

#endif // PORT_H
