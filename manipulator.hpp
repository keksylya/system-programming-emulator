//
//  manipulator.hpp
//  Egor Emulator
//
//  Created by  Кирилл Ильичев on 11/17/20.
//

#ifndef manipulator_hpp
#define manipulator_hpp

#include <stdint.h>
#include <stdlib.h>

const size_t traySize = 21;

class Manipulator {
public:
    bool ** trayState;
    int8_t grabberX, grabberY;
    bool isGrabbed;

    Manipulator();
    
    void move(int8_t deltaX, int8_t deltaY);
    uint8_t checkComponentUnderGrab();
    void grab();
    void drop();
};

#endif /* manipulator_hpp */
