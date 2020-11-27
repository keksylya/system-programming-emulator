//
//  common.cpp
//  Egor Emulator
//
//  Created by  Кирилл Ильичев on 11/16/20.
//

#include "common.hpp"

#include <iostream>

void error(std::string errorText) {
    std::cout << errorText;
    exit(-1);
}
