#include "headers/Transition.hpp"

void Transition::printTransition(){

    std::cout << "t: " << this->tSourceUID << " -" << this->tLabel << "- " << this->tTargetUID << std::endl;
}

Transition::Transition(unsigned int tSourceUID,unsigned int tTargetUID,unsigned char tLabel){
    this->tSourceUID = tSourceUID;
    this->tTargetUID = tTargetUID;
    this->tLabel = tLabel;
    
}