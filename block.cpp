/** Block.cpp
 *
 *  Jakub Pag·Ë xpagac06
 *  Jan Nov·k xnovak1s
 */

#include "block.h"

int Block::cnt=1;

Block::Block(int type)
{
    id=Block::cnt++;
    switch(type){
    case 1:
        op="+";
        break;
    case 2:
        op="*";
        break;
    case 3:
        op="max";
        break;
    case 4:
        op="min";
        break;
    case 5:
        op="pyth";
        break;
    }
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
    } else if(op=="*"){
        res=1.0;
        for(std::vector<Port>::iterator it=inputPorts.begin();it!=inputPorts.end();++it){
            res *= it->getValue();
        }
    } else if(op=="max"){
        if(inputPorts[0].getValue()>inputPorts[1].getValue())
            res=inputPorts[0].getValue();
        else
            res=inputPorts[1].getValue();
    } else if(op=="min"){
        if(inputPorts[0].getValue()<inputPorts[1].getValue())
            res=inputPorts[0].getValue();
        else
            res=inputPorts[1].getValue();
    } else {
        res=sqrt(inputPorts[0].getValue()*inputPorts[0].getValue()+(inputPorts[1].getValue()*inputPorts[1].getValue()));
    }
    for(std::vector<Port>::iterator it=outputPorts.begin();it!=outputPorts.end();++it){
        it->setValue(res);
    }
}

std::ostream &operator<<(std::ostream &os, Block const &bl) {
    os << bl.getId() << " " << bl.op;
    for(Port port: bl.getConstInputPorts()){
        os << " " << port;
    }
    for(Port port: bl.getConstOutputPorts()){
        os << " " << port;
    }
    return os;
}

