#ifndef STATE_H
#define STATE_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Utils.hpp"
class State{

    

    public:
    unsigned int sUID;
    bool sIsFinal = 0;
    bool sIsInitial = 0;

    std::string sName;
    //string as a name
    void printState();

    State();
    State(unsigned int sUID,std::string sName,bool isFinal = 0,bool isInitial = 0);



    //Visualization Stuff

    //position
    //size
    //renderer
    
    public:
    bool operator<(const State& other) const {
        return sUID < other.sUID;  // Compare based on sUID, or whatever makes sense for your application
    }
    sf::Vector2f sPosition;
    sf::CircleShape sShape;
    sf::Text sNameText;

};
#endif