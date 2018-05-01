#include "connection.h"

int Connection::cnt=1;

Connection::Connection(Block bOut, Port pOut, Block bIn, Port pIn):
    blockIn(),blockOut(),portIn(""),portOut("")
{
    id=Connection::cnt++;
    blockIn=bIn;
    blockOut=bOut;
    portIn=pIn;
    portOut=pOut;
}

Connection::~Connection()
{

}

bool Connection::operator==(const Connection &other) const{
    if(id==other.id){
        return true;
    } else {
        return false;
    }
}

