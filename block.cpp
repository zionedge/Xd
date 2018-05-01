#include "block.h"

int Block::cnt=1;

Block::Block()
{
    id=Block::cnt++;
}

Block::~Block()
{
    inputPorts.clear();
    outputPorts.clear();
}

bool Block::operator==(const Block& other) const{
    if(id==other.id)
        return true;
    else
        return false;

}

void Block::delPort(Port port)
{
    std::vector<Port>::iterator it=std::find(inputPorts.begin(),inputPorts.end(),port);
    if(it!=inputPorts.end()){
        inputPorts.erase(it);
        std::cout << inputPorts.size() << std::endl;
    } else if((it=std::find(outputPorts.begin(),outputPorts.end(),port))!=outputPorts.end()){
        outputPorts.erase(it);
        std::cout << "there" << std::endl;
    } else {
        std::cout << "tu" << std::endl;
    }

}

