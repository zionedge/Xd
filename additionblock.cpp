#include "additionblock.h"

AdditionBlock::AdditionBlock():
    Block()
{

}

void AdditionBlock::calculate(){
    double res=0.0;
    std::vector<Port> ports = Block::getInputPorts();
    for(std::vector<Port>::iterator it=ports.begin();it!=ports.end();++it){
        res += it->getValue();
    }
    ports=Block::getOutputPorts();
    for(std::vector<Port>::iterator it=ports.begin();it!=ports.end();++it){
        it->setValue(res);
    }
    //TODO prenos pres spoj uzlu
}

