//
//  control.cpp
//  Egor Emulator
//
//  Created by  Кирилл Ильичев on 11/16/20.
//

#include "control.hpp"

#include <fstream>

#include "common.hpp"
#include "mem.hpp"
#include "alu.hpp"
#include "io.hpp"

void copyToMem(const char* buffer, size_t length) {
    for (size_t i = 0; i < length; i++) {
        memWrite(i, (uint8_t)buffer[i]);
    }
}

void loader(std::string codeFile) {
    std::ifstream file(codeFile);
    
    if (file.is_open()) {
        error("");
    }
    
    file.seekg(0, std::ios::end);
    size_t length = file.tellg();
    file.seekg(0, std::ios::beg);
        
    char* buffer = new char[length];
    file.read(buffer, length);
    
    copyToMem(buffer, length);
    
    file.close();
}

void loadState(std::string stateFile) {
    Manipulator* manipulator = new Manipulator();
    
    std::ifstream file(stateFile);
    
    if (file.is_open()) {
        error("");
    }
    
    for (size_t x = 0; x < traySize; x++) {
        for (size_t y = 0; y < traySize; y++) {
            int temp;
            file >> temp;
            manipulator->trayState[x][y] = temp == 1;
        }
    }
    
    ioInitState(manipulator);
    file.close();
}

size_t getInstructionSize(Instruction instruction) {
    switch (instruction) {
        case Instruction::movValue: return 3;
        case Instruction::movMemory: return 3;
        case Instruction::movIfZeroValue: return 4;
        case Instruction::movIfZeroMemory: return 4;
        case Instruction::movIfGreaterThanZeroValue: return 4;
        case Instruction::movIfGreaterThanZeroMemory: return 4;
        case Instruction::add: return 3;
        case Instruction::sub: return 3;
        case Instruction::read: return 1;
        case Instruction::write: return 2;
        
        default: return 0;
    }
}

void executeInstruction(Instruction instruction, uint8_t offset) {
    size_t opCount = getInstructionSize(instruction) - 1;
    uint8_t * op = new uint8_t[opCount];
    
    for (int i = 0; i < opCount; i++) {
        op[i] = memRead(offset + i + 1);
    }
    
    switch (instruction) {
        case Instruction::movValue:
            movValue(op[0], op[1]);
            break;
        case Instruction::movMemory:
            movMemory(op[0], op[1]);
            break;
        case Instruction::movIfZeroValue:
            movIfZeroValue(op[0], op[1], op[2]);
            break;
        case Instruction::movIfZeroMemory:
            movIfZeroMemory(op[0], op[1], op[2]);
            break;
        case Instruction::movIfGreaterThanZeroValue:
            movIfGreaterThanZeroValue(op[0], op[1], op[2]);
            break;
        case Instruction::movIfGreaterThanZeroMemory:
            movIfGreaterThanZeroMemory(op[0], op[1], op[2]);
            break;
        case Instruction::add:
            add(op[0], op[1]);
            break;
        case Instruction::sub:
            sub(op[0], op[1]);
            break;
        case Instruction::read:
            read();
            break;
        case Instruction::write:
            write(op[0]);
            break;
        default:
            break;
    }
}

void mainLoop() {
    uint8_t offset = 0;
    uint8_t code = memRead(offset);
    
    while (code) {
        auto instruction = recognizeAluInstruction(code);
        
        if (instruction == Instruction::incorrect) {
            error("INCORRECT INSTRUCTION CODE " + std::to_string(code) +  " ON ADDRESS " + std::to_string(offset));
        }
        
        executeInstruction(instruction, offset);
        
        offset += getInstructionSize(instruction);
        code = memRead(offset);
    }
}


void init(std::string codeFile, std::string stateFile) {
    loader(codeFile);
    loadState(stateFile);
    mainLoop();
}

