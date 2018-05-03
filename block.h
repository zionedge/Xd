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
    std::string getOp() const{return op;}
    bool operator==(const Block& other) const;
    bool operator<(const Block& other) const;
    bool operator!=(const Block& other) const;
    void addInputPort(Port input){this->inputPorts.push_back(input);}
    void addOutputPort(Port output){this->outputPorts.push_back(output);}
    void delPort(Port port);
    std::vector<Port> &getInputPorts() {return inputPorts;}
    std::vector<Port> &getOutputPorts() {return outputPorts;}
    std::vector<Port> getConstInputPorts() const{return inputPorts;}
    std::vector<Port> getConstOutputPorts() const{return outputPorts;}
    void calculate();
    friend std::ostream &operator<<(std::ostream &os, Block const &bl);
private:
    static int cnt;

    int id;
    std::string op;
    std::vector<Port> inputPorts;
    std::vector<Port> outputPorts;
};

#endif // BLOCK_H
