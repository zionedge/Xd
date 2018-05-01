#include "board.h"

Board::Board(std::string nam)
{
    name=nam;
}

void Board::delBlock(Block block){
    for(std::vector<Connection>::iterator it=connections.begin();it!=connections.end();++it){
        if(it->getBlockIn()==block or it->getBlockOut()==block){
            this->delConnection(it);
        }
    }
    std::vector<Block>::iterator it=std::find(blocks.begin(),blocks.end(),block);
    if(it!=blocks.end()){
        blocks.erase(it);
        std::cout << "blocks "<< blocks.size() << std::endl;
    }
}

void Board::delConnection(Connection con){
    std::vector<Connection>::iterator it=std::find(connections.begin(),connections.end(),con);
    if(it!=connections.end()){
        connections.erase(it);
        std::cout << connections.size() << std::endl;
    }
}

void Board::delConnection(std::vector<Connection>::iterator it){
    connections.erase(it);
}

