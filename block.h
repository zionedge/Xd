#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include <algorithm>
#include <iostream>
#include "port.h"

class Block
{
public:
    Block();
    ~Block();
    int getId() const{return id;}
    bool operator==(const Block& other) const;
    void addInputPort(Port input){this->inputPorts.push_back(input);}
    void addOutputPort(Port output){this->outputPorts.push_back(output);}
    void delPort(Port port);
    std::vector<Port> &getInputPorts() {return inputPorts;}
    std::vector<Port> &getOutputPorts() {return outputPorts;}
private:
    static int cnt;

    int id;
    std::vector<Port> inputPorts;
    std::vector<Port> outputPorts;
};

#endif // BLOCK_H
