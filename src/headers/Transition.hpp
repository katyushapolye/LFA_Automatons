#ifndef TRANSITION_H
#define TRANSITION_H
#include <iostream>
class Transition{
    unsigned int tSourceUID;
    unsigned int tTargetUID;
    unsigned char tLabel;


    public:
    Transition();
    Transition(unsigned int tSourceUID,unsigned int tTargetUID,unsigned char tLabel);

    void printTransition();

};
#endif