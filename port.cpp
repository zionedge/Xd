#include "port.h"

int Port::cnt=1;

Port::Port(std::string nam)
{
    name=nam;
    value=NAN;
    id=Port::cnt++;
}

Port::Port(std::string nam,double val)
{
    name=nam;
    value=val;
    id=Port::cnt++;
}

Port::~Port(){

}

std::ostream& operator<<(std::ostream &os, Port const &port) {
    return os << port.name << " " << port.value << std::endl;
}
