#include "headers/State.hpp"

void State::printState(){
    std::cout << "s: " << this->sUID << "--" << this->sName << "(F/S) = (" << this->sIsFinal << "/" << this->sIsInitial << ") "<< std::endl;
}

State::State(unsigned int sUID,std::string sName,bool sIsFinal,bool sIsInitial){
    this->sUID = sUID;
    this->sName = sName;

    this->sIsFinal = sIsFinal;
    this->sIsInitial = sIsInitial;
}
