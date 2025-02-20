#include "headers/State.hpp"

void State::printState(){
    std::cout << "s: " << this->sUID << "--" << this->sName << "(F/S) = (" << this->sIsFinal << "/" << this->sIsInitial << ") "<< std::endl;
}

State::State(unsigned int sUID,std::string sName,bool sIsFinal,bool sIsInitial){
    this->sUID = sUID;
    this->sName = sName;

    this->sIsFinal = sIsFinal;
    this->sIsInitial = sIsInitial;

    this->sNameText = sf::Text();
    this->sNameText.setFont(*defaultFont);
    this->sNameText.setString(this->sName);
    this->sNameText.setCharacterSize(40);
    this->sNameText.setPosition(sf::Vector2f(0.0f,0.0f));
    this->sNameText.setFillColor(sf::Color::Black);
    this->sNameText.setOutlineColor(sf::Color::Black);

    this->sShape = sf::CircleShape(100.0f,32);
    this->sShape.setPosition(sf::Vector2f(0.0f,0.0f));
    this->sShape.setFillColor(sf::Color::White);
    this->sShape.setOutlineColor(sf::Color::Black);
    this->sShape.setOutlineThickness(5.0f);
    this->sPosition = sf::Vector2f(0.0f,0.0f);


}
