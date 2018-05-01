#ifndef BOARD_H
#define BOARD_H

#include "connection.h"

class Board
{
public:
    Board(std::string nam);
    std::string getName(){return name;}
    std::vector<Block> &getBlocks() {return blocks;}
    std::vector<Connection> &getConnections() {return connections;}
    void setName(std::string nam){name=nam;}
    void addBlock(Block block){this->blocks.push_back(block);}
    void addConnection(Connection con){this->connections.push_back(con);}
    void delConnection(Connection con);
    void delConnection(std::vector<Connection>::iterator it);
    void delBlock(Block block);
    void clearBoard(){blocks.clear(); connections.clear();name="new Board";}
private:
    std::string name;
    std::vector<Block> blocks;
    std::vector<Connection> connections;
};

#endif // BOARD_H
