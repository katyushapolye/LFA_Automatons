#include <SFML/Graphics.hpp>
#include "headers/Automaton.hpp"
int main()
{
    State s1 = State(0,"0",false,true);
    
    State s2 = State(1,"1",true,false);

    Transition t1 = Transition(0,1,'a');

    std::vector<State> states;
    states.push_back(s1);
    states.push_back(s2);

    std::vector<Transition> transitions;
    transitions.push_back(t1);

    Automaton M = Automaton(states,transitions);

    M.printAutomaton();
    


    /*  
    sf::RenderWindow window(sf::VideoMode(800, 600), "LFA - Automaton");
    while (window.isOpen())
    {
        // Event handling
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window
        window.clear();State

        // Draw everything here...

        // Display the window
        window.display();
    }
    */

    return 0;
}