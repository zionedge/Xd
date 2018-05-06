/** Port.cpp
 *
 *  Jakub Pag·Ë xpagac06
 *  Jan Nov·k xnovak1s
 */
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

std::ostream& operator<<(std::ostream &os, Port const &port) {
    return os << port.name << " " << port.value;
}
