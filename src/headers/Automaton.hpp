#ifndef AUTOMATON_H
#define AUTOMATON_H
#include<iostream>
#include <vector>
#include "State.hpp"
#include "Transition.hpp"
class Automaton{

    private:
    std::vector<State> aStates;
    std::vector<Transition> aTransitions;

    public:
    void printAutomaton();
    Automaton(std::vector<State> aStates, std::vector<Transition> aTransitions);

    


};
#endif