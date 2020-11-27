//
//  io.cpp
//  Egor Emulator
//
//  Created by  Кирилл Ильичев on 11/16/20.
//

#include "io.hpp"
#include "common.hpp"

#include <iostream>

Manipulator * manipulator;
int8_t result;
bool hasData;

void ioInitState(Manipulator * value) {
    manipulator = value;
}

void setResult(int8_t res) {
    hasData = true;
    result = res;
}

void printState() {
    std::cout << manipulator->grabberX << manipulator->grabberY << manipulator->isGrabbed << std::endl;
    
    for (size_t x = 0; x < traySize; x++) {
        for (size_t y = 0; y < traySize; y++) {
            std::cout << manipulator->trayState[x][y] << " ";
        }
        
        std::cout << std::endl;
    }
}

void ioWrite(uint8_t opCode) {
    if (hasData) {
        error("REQUESTED VALUE WAS NOT RETRIEVED FROM MANIPULATOR");
    }
    
    switch (opCode) {
        case 1: setResult(manipulator->grabberX); break;
        case 2: setResult(manipulator->grabberY); break;
        case 3: setResult(manipulator->checkComponentUnderGrab()); break;
        case 4: manipulator->move(-1, 0); break;
        case 5: manipulator->move(1, 0); break;
        case 6: manipulator->move(0, -1); break;
        case 7: manipulator->move(0, 1); break;
        case 8: manipulator->grab(); break;
        case 9: manipulator->drop(); break;
        case 10: setResult(manipulator->isGrabbed ? 1 : 0); break;
        default: error("INCORRECT OPERATION NUMBER"); break;
    }
    
    printState();
}

int8_t ioRead() {
    if (!hasData) {
        error("THERE IS NO REQUESTED VALUE IN MANIPULATOR");
    }
    
    return result;
}
