//
//  mem.cpp
//  Egor Emulator
//
//  Created by  Кирилл Ильичев on 11/16/20.
//

#include "mem.hpp"
#include "common.hpp"

uint8_t memory[255];

void memWrite(uint8_t address, uint8_t value) {
    if (address > 255 || address < 0) {
        error("INCORRECT ADDRESS " + std::to_string(address));
    }
    
    if (value > 255 || value < 0) {
        error("INCORRECT NUMBER " + std::to_string(value));
    }
    
    memory[address] = value;
}

uint8_t memRead(uint8_t address) {
    if (address > 255 || address < 0) {
        error("INCORRECT ADDRESS " + std::to_string(address));
    }
    
    return memory[address];
}
