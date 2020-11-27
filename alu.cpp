//
//  alu.cpp
//  Egor Emulator
//
//  Created by  Кирилл Ильичев on 11/16/20.
//

#include "common.hpp"
#include "alu.hpp"
#include "mem.hpp"
#include "io.hpp"

Instruction recognizeAluInstruction(uint8_t operation) {
    switch (operation) {
        case 1: return Instruction::movValue;
        case 2: return Instruction::movMemory;
        case 3: return Instruction::movIfZeroValue;
        case 4: return Instruction::movIfZeroMemory;
        case 5: return Instruction::movIfGreaterThanZeroValue;
        case 6: return Instruction::movIfGreaterThanZeroMemory;
        case 7: return Instruction::add;
        case 8: return Instruction::sub;
        case 9: return Instruction::read;
        case 10: return Instruction::write;
        default: return Instruction::incorrect;
    }
}

void movValue(uint8_t address, uint8_t value) {
    memWrite(address, value);
}

void movMemory(uint8_t address1, uint8_t address2) {
    memWrite(address1, memRead(address2));
}

void movIfZeroValue(uint8_t address1, uint8_t value, uint8_t address2) {
    if (memRead(address2) == 0) {
        memWrite(address1, value);
    }
}

void movIfZeroMemory(uint8_t address1, uint8_t address2, uint8_t address3) {
    if (memRead(address3) == 0) {
        memWrite(address1, memRead(address2));
    }
}

void movIfGreaterThanZeroValue(uint8_t address1, uint8_t value, uint8_t address2) {
    if ((int8_t)memRead(address2) > 0) {
        memWrite(address1, value);
    }
}

void movIfGreaterThanZeroMemory(uint8_t address1, uint8_t address2, uint8_t address3) {
    if ((int8_t)memRead(address3) > 0) {
        memWrite(address1, memRead(address2));
    }
}

void add(uint8_t address1, uint8_t address2) {
    uint8_t sum = memRead(address1) + memRead(address2);
    memWrite(address1, sum);
}

void sub(uint8_t address1, uint8_t address2) {
    uint8_t sub = memRead(address1) - memRead(address2);
    memWrite(address1, sub);
}

void read() {
    memWrite(255, ioRead());
}

void write(uint8_t value) {
    ioWrite(value);
}
