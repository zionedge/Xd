#ifndef CONNECTION_H
#define CONNECTION_H

#include "block.h"

class Connection
{
public:
    Connection(Block bOut, Port pOut, Block bIn, Port pIn);
    ~Connection();
    bool operator==(const Connection& other) const;
    Port getPortOut()const{return portOut;}
    Port getPortIn()const{return portIn;}
    Block getBlockOut()const{return blockOut;}
    Block getBlockIn()const{return blockIn;}
private:
    static int cnt;

    int id;
    Port portOut;
    Port portIn;
    Block blockOut;
    Block blockIn;
};

#endif // CONNECTION_H
