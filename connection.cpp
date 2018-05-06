/** Connection.cpp
 *
 *  Jakub Pagבט xpagac06
 *  Jan Novבk xnovak1s
 */
#include "connection.h"

int Connection::cnt=1;

Connection::Connection(Block bOut, Port pOut, Block bIn, Port pIn):
    portOut(pOut),portIn(pIn),blockOut(bOut),blockIn(bIn)
{
    if(bOut!=bIn){
        id=Connection::cnt++;
    } else {
        throw 1;
    }
}

bool Connection::operator==(const Connection &other) const{
    if(getBlockIn()==other.getBlockIn() and getBlockOut()==other.getBlockOut()){
        return true;
    } else {
        return false;
    }
}

std::ostream &operator<<(std::ostream &os, Connection const &cn) {
    os << cn.getBlockOut().getId() << " " << cn.getBlockIn().getId();
    return os;
}

