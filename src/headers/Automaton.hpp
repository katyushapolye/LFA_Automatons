#ifndef AUTOMATON_H
#define AUTOMATON_H
#include<iostream>
#include <vector>
#include "State.hpp"
#include "Transition.hpp"
class Automaton{





    public:
    enum LAYOUT{
        Matrix,
        ZigZag,
    };

    void printAutomaton();
    void setLayout(LAYOUT layout);
    Automaton(std::vector<State> aStates, std::vector<Transition> aTransitions);

    std::vector<State> aStates;
    std::vector<Transition> aTransitions;

    


};
#endif