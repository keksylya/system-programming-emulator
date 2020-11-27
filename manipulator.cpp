//
//  manipulator.cpp
//  Egor Emulator
//
//  Created by  Кирилл Ильичев on 11/17/20.
//

#include "manipulator.hpp"
#include "common.hpp"

Manipulator::Manipulator() {
    this->trayState = new bool*[traySize];
    
    for (int i = 0; i < traySize; i++) {
        trayState[i] = new bool[traySize];
    }
    
    this->grabberX = 0;
    this->grabberY = 0;
    this->isGrabbed = false;
}

void Manipulator::move(int8_t deltaX, int8_t deltaY) {
    grabberX += deltaX;
    grabberY += deltaY;
    
    if (grabberX < -10 || grabberX > 10 ||
        grabberY < -10 || grabberY > 10) {
        error("INCORRECT GRAB POSITION");
    }
}

uint8_t Manipulator::checkComponentUnderGrab() {
    return trayState[grabberX][grabberY] ? 1 : 0;
}

void Manipulator::grab() {
    if (isGrabbed) {
        error("GRAB IS NOT FREE");
    }
    
    if (!checkComponentUnderGrab()) {
        error("THERE IS NO COMPONENT IN TRAY");
    }
    
    isGrabbed = true;
}

void Manipulator::drop() {
    if (!isGrabbed) {
        error("THERE IS NO COMPONENT IN GRAB");
    }
    
    if (checkComponentUnderGrab()) {
        error("TRAY IS NOT FREE");
    }
    
    isGrabbed = false;
}
