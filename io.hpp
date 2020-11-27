//
//  io.hpp
//  Egor Emulator
//
//  Created by  Кирилл Ильичев on 11/16/20.
//

#ifndef io_hpp
#define io_hpp

#include <vector>
#include "manipulator.hpp"

void ioInitState(Manipulator * value);
void ioWrite(uint8_t opCode);
int8_t ioRead();


#endif /* io_hpp */
