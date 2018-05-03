#include "block.h"

int Block::cnt=1;

Block::Block()
{
    id=Block::cnt++;
    op="+";
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

bool Block::operator <(const Block& other) const{
    if(id<other.id)
        return true;
    else
        return false;
}

bool Block::operator !=(const Block& other) const{
    if(id!=other.id)
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

void Block::calculate(){
    double res=0.0;
    if(op=="+"){
       for(std::vector<Port>::iterator it=inputPorts.begin();it!=inputPorts.end();++it){
           res += it->getValue();
       }
    } else {

    }
    for(std::vector<Port>::iterator it=outputPorts.begin();it!=outputPorts.end();++it){
        it->setValue(res);
    }
}

std::ostream &operator<<(std::ostream &os, Block const &bl) {
    os << bl.op << " ";
    for(Port port: bl.getConstInputPorts()){
        os << port;
    }
    for(Port port: bl.getConstOutputPorts()){
        os << port;
    }
    return os;
}

