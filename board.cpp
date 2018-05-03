#include "board.h"

Board::Board(std::string nam)
{
    name=nam;
}

void Board::delBlock(Block block){
    for(Connection it: connections){
        if(it.getBlockIn()==block or it.getBlockOut()==block){
            delConnection(it);
        }
        std::cerr << "easaeqw" << std::endl;
    }
    std::cerr << getConnections().size() << std::endl;
    std::vector<Block>::iterator ite=std::find(blocks.begin(),blocks.end(),block);
    if(ite!=blocks.end()){
        blocks.erase(ite);
        std::cout << "blocks "<< blocks.size() << std::endl;
    }
}

void Board::delConnection(Connection con){
    std::cerr << "ae" << std::endl;
    std::vector<Connection>::iterator it=std::find(connections.begin(),connections.end(),con);
    if(it!=connections.end()){

        connections.erase(it);
    }
}

