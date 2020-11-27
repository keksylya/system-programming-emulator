//
//  mem.hpp
//  Egor Emulator
//
//  Created by  Кирилл Ильичев on 11/16/20.
//

#ifndef mem_hpp
#define mem_hpp

#include <stdint.h>

void memWrite(uint8_t address, uint8_t value);
uint8_t memRead(uint8_t address);

#endif /* mem_hpp */
