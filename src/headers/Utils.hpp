#include <SFML/Graphics.hpp>
#include <cmath>
#ifndef UTILS_H
#define UTILS_H
extern sf::Font* defaultFont;

void drawArrow(sf::RenderWindow* window, const sf::Vector2f& start, const sf::Vector2f& end, float passThroughOffsetx = 0.0f,float passThroughOffsety = 0.0f ,char label = ' ');
#endif