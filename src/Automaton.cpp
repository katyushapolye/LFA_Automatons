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

Automaton::Automaton(std::vector<State> aStates,std::vector<Transition> aTransitions){

    this->aStates = aStates;
    this->aTransitions = aTransitions;
}