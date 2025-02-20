#include "headers/Automaton.hpp"

void Automaton::printAutomaton(){

    std::cout << "States in automaton: " << std::endl;
    for(auto s = this->aStates.begin();s != this->aStates.end();s++){
        s->printState();
    }

    std::cout << "Transitions in automaton: " << std::endl;
    for(auto t = this->aTransitions.begin();t != this->aTransitions.end();t++){
        t->printTransition();
    }

}

void Automaton::setLayout(Automaton::LAYOUT layout){
    unsigned int c = 0;
    unsigned int MaxLenght = 4;
    switch (layout)
    {
    case LAYOUT::Matrix:

        for(auto s = this->aStates.begin();s != this->aStates.end();s++){
            s->sPosition = sf::Vector2f(400.0 * (c%MaxLenght), 400.0*(c/MaxLenght));
            c++;
        }
        break;
    
    default:
        break;
    }

}

Automaton::Automaton(std::vector<State> aStates,std::vector<Transition> aTransitions){

    this->aStates = aStates;
    this->aTransitions = aTransitions;

    //set default display layout
    this->setLayout(LAYOUT::Matrix);



}