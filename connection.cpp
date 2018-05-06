#include "connection.h"

int Connection::cnt=1;

Connection::Connection(Block bOut, Port pOut, Block bIn, Port pIn):
    blockIn(bIn),blockOut(bOut),portIn(pIn),portOut(pOut)
{
    if(bOut!=bIn){
        id=Connection::cnt++;
        //blockIn=bIn;
       // blockOut=bOut;
       // portIn=pIn;
       // portOut=pOut;
    } else {
        throw 1;
    }
}

Connection::~Connection()
{

}

bool Connection::operator==(const Connection &other) const{
    if(getBlockIn()==other.getBlockIn() and getBlockOut()==other.getBlockOut()){
        return true;
    } else {
        return false;
    }
}

std::ostream &operator<<(std::ostream &os, Connection const &cn) {
   os << cn.getBlockOut().getId() << " " << cn.getBlockIn().getId() << " ";
    return os;
}

