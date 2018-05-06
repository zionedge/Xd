#include "board.h"

Board::Board(std::string nam)
{
    name=nam;
}

void Board::delBlock(Block block){
    std::vector<Connection> con=connections;
    for(Connection it: con){
        if(it.getBlockIn()==block or it.getBlockOut()==block){
            delConnection(it);
        }
    }
    std::cerr << "cons" << getConnections().size() << std::endl;
    std::vector<Block>::iterator ite=std::find(blocks.begin(),blocks.end(),block);
    if(ite!=blocks.end()){
        blocks.erase(ite);
        std::cerr << "blocks "<< blocks.size() << std::endl;
    }
}

void Board::delConnection(Connection con){
    std::vector<Connection>::iterator it=std::find(connections.begin(),connections.end(),con);
    if(it!=connections.end()){

        connections.erase(it);
    }
}

void Board::setupOrder(){
    std::vector<Block> cpy = getBlocks();
    std::vector<Port> allInputPorts;
    std::vector<Connection> cons=getConnections();
    forInput.clear();
    clearBlocks();
    for(Connection con:cons){
        allInputPorts.push_back(con.getPortIn());
    }
    for(Block bl:cpy){
        for(Port pt:bl.getInputPorts()){
            if(std::find(allInputPorts.begin(),allInputPorts.end(),pt)==allInputPorts.end()){
                forInput.push_back(pt);
            }
        }
    }
    for(Block bl:cpy){
        if(std::find(forInput.begin(),forInput.end(),bl.getInputPorts()[0])!=forInput.end() and
           std::find(forInput.begin(),forInput.end(),bl.getInputPorts()[1])!=forInput.end()){
            addBlock(bl);
        }
    }
    while(!cpy.empty()){
        std::vector<Block> save=getBlocks();
        for(Connection con:cons){
            for(Block bl:save){
                if(con.getBlockOut()==bl){
                    if(std::find(getBlocks().begin(),getBlocks().end(),con.getBlockIn())==getBlocks().end()){
                        if(std::find(forInput.begin(),forInput.end(),con.getBlockIn().getInputPorts()[0])!=forInput.end() or
                           std::find(forInput.begin(),forInput.end(),con.getBlockIn().getInputPorts()[1])!=forInput.end()){
                            addBlock(con.getBlockIn());
                            if(std::find(cpy.begin(),cpy.end(),con.getBlockIn())!=cpy.end()){
                                cpy.erase(std::find(cpy.begin(),cpy.end(),con.getBlockIn()));
                            }
                        } else {
                            for(Connection c:cons){
                                if(con.getBlockIn()==c.getBlockIn() and con.getBlockOut()!=c.getBlockOut()){
                                    if(std::find(getBlocks().begin(),getBlocks().end(),c.getBlockOut())!=getBlocks().end()){
                                        addBlock(con.getBlockIn());
                                        if(std::find(cpy.begin(),cpy.end(),con.getBlockIn())!=cpy.end()){
                                            cpy.erase(std::find(cpy.begin(),cpy.end(),con.getBlockIn()));
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cpy.pop_back();
    }
}

