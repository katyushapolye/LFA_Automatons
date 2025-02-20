#include <SFML/Graphics.hpp>
#include "headers/Automaton.hpp"
#include "headers/Utils.hpp"
void drawAutomaton(Automaton *M, sf::RenderWindow *window);
void handleInput(sf::RenderWindow* window);
bool isDragging = false;
sf::Vector2i lastMousePos;
sf::View view;
float zoomLevel = 1.0f;


int main()
{

    //init font

    defaultFont = new sf::Font();
    if (!defaultFont->loadFromFile("Resources/JetBrainsMono-Medium.ttf")) {
        std::cout << "ERROR LOADING FONT!" << std::endl;
    }

    State s1 = State(0, "Q1", false, true);
    State s2 = State(1, "Q2", true, false);
    State s3 = State(2, "Q3", false, false);
    Transition t1 = Transition(0, 1, 'a');
    Transition t2 = Transition(1, 2, 'b');
    Transition t3 = Transition(1,1, 'a');

    std::vector<State> states;
    states.push_back(s1);
    states.push_back(s2);
    states.push_back(s3);

    std::vector<Transition> transitions;
    transitions.push_back(t1);
    transitions.push_back(t2);
    transitions.push_back(t3);
    Automaton M = Automaton(states, transitions);

    M.printAutomaton();

    sf::RenderWindow window(sf::VideoMode(800, 800), "LFA - Automaton");

    while (window.isOpen())
    {
        // Event handling
        handleInput(&window);

        // Clear the window
        window.clear(sf::Color::White);

        // Draw everything here...
        drawAutomaton(&M, &window);

        // Display the window
        window.display();
    }

    return 0;
}


void handleInput(sf::RenderWindow* window){
        sf::Event event;
        while (window->pollEvent(event))
        {
            window->getDefaultView();

            if (event.type == sf::Event::Closed)
                window->close();
            else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                isDragging = true;
                lastMousePos = sf::Mouse::getPosition(*window);
            }
            else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
            {
                isDragging = false;
            }
            else if (event.type == sf::Event::MouseMoved && isDragging)
            {
                sf::Vector2i currentPos = sf::Mouse::getPosition(*window);
                sf::Vector2i delta = lastMousePos - currentPos;
                view.move(delta.x, delta.y);
                window->setView(view);
                lastMousePos = currentPos;
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Equal)
                {                      // Plus key
                    zoomLevel *= 0.9f; // Zoom in
                    view.zoom(0.9f);
                }
                else if (event.key.code == sf::Keyboard::Dash)
                {                      // Minus key
                    zoomLevel *= 1.1f; // Zoom out
                    view.zoom(1.1f);
                }
                window->setView(view);
            }
        }


}
void drawAutomaton(Automaton *M, sf::RenderWindow *window)
{

        //ineficinte, mas mais facil de pensar
    for(auto t = M->aTransitions.begin(); t != M->aTransitions.end();t++){
        //achar onde o src esta
        unsigned int tSourceId = t->tSourceUID;
        auto src = std::find_if(M->aStates.begin(),M->aStates.end(),[&tSourceId](const State& s){return s.sUID == tSourceId;});
        unsigned int tDestinationId = t->tTargetUID;
        auto dst = std::find_if(M->aStates.begin(),M->aStates.end(),[&tDestinationId](const State& s){return s.sUID == tDestinationId;});

        if(src == M->aStates.end() || dst == M->aStates.end() ){
            std::cout << "INVALID TRANSITION - STATE NOT FOUND!";
            t->printTransition();
            exit(-1);
        }

        if(src == dst){
            //trick
            sf::CircleShape circle = sf::CircleShape(80,32);
            circle.setOutlineThickness(3.0f);
            circle.setOutlineColor(sf::Color::Black);
            circle.setFillColor(sf::Color::Transparent);

            circle.setPosition(src->sPosition.x+50,src->sPosition.y-40);


            window->draw(circle);

            sf::Text text((char)t->tLabel, *defaultFont, 24);
            text.setFillColor(sf::Color::Black);
            text.setPosition(src->sPosition.x + 150,src->sPosition.y - 70);
            window->draw(text);


        }
        else{
        drawArrow(window,sf::Vector2f(src->sPosition.x+100.0f,src->sPosition.y+100.0f),sf::Vector2f(dst->sPosition.x+100.0f,dst->sPosition.y+100.0f),t->tLabel);
        }
        
    }
    for (auto s = M->aStates.begin(); s != M->aStates.end(); s++)
    {
        //default drawing
        s->sShape.setPosition(s->sPosition);
        window->draw(s->sShape);
        s->sNameText.setPosition(
            s->sPosition.x + 100.0f - (s->sNameText.getLocalBounds().width/2.0f),    // x center
            s->sPosition.y + 100.0f - (s->sNameText.getLocalBounds().height/2.0f)    // y center
        );
        window->draw(s->sNameText);

        if(s->sIsFinal){
            sf::CircleShape outline = sf::CircleShape(110.0f,32);
            outline.setOrigin(-110.0f,-110.0f);
            outline.setPosition(s->sPosition.x-120.0f,s->sPosition.y - 120.0f);
            outline.setFillColor(sf::Color::Transparent);
            outline.setOutlineColor(sf::Color::Black);
            outline.setOutlineThickness(3.0f);

            window->draw(outline);
        }
        if(s->sIsInitial){
            
            drawArrow(window,sf::Vector2f(s->sPosition.x -50,s->sPosition.y + 100.0f),sf::Vector2f(s->sPosition.x,s->sPosition.y + 100.0f));

        }
    }


        



    return;
}