#include "multiplicationblock.h"

MultiplicationBlock::MultiplicationBlock():
    Block()
{

}

void MultiplicationBlock::calculate(){
    double res=1.0;
    for(std::vector<Port>::iterator it=Block::getInputPorts().begin();it!=Block::getInputPorts().end();++it){
        res *= it->getValue();
    }
    for(std::vector<Port>::iterator it=Block::getOutputPorts().begin();it!=Block::getOutputPorts().end();++it){
        it->setValue(res);
    }
}

