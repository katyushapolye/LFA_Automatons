#include <SFML/Graphics.hpp>
#include <cmath>
#ifndef UTILS_H
#define UTILS_H
extern sf::Font* defaultFont;

void drawArrow(sf::RenderWindow* window, const sf::Vector2f& start, const sf::Vector2f& end,char label = ' ');
#endif