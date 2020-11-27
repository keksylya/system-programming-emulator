//
//  alu.hpp
//  Egor Emulator
//
//  Created by  Кирилл Ильичев on 11/16/20.
//

#ifndef alu_hpp
#define alu_hpp

#include <stdint.h>

enum class Instruction {
    movValue,
    movMemory,
    movIfZeroValue,
    movIfZeroMemory,
    movIfGreaterThanZeroValue,
    movIfGreaterThanZeroMemory,
    add,
    sub,
    read,
    write,
    checkCommand,
    incorrect,
};

Instruction recognizeAluInstruction(uint8_t operation);

void movValue(uint8_t address, uint8_t value);
void movMemory(uint8_t address1, uint8_t address2);
void movIfZeroValue(uint8_t address1, uint8_t value, uint8_t address2);
void movIfZeroMemory(uint8_t address1, uint8_t address2, uint8_t address3);
void movIfGreaterThanZeroValue(uint8_t address1, uint8_t value, uint8_t address2);
void movIfGreaterThanZeroMemory(uint8_t address1, uint8_t address2, uint8_t address3);
void add(uint8_t address1, uint8_t address2);
void sub(uint8_t address1, uint8_t address2);
void read();
void write(uint8_t value);

#endif /* alu_hpp */
