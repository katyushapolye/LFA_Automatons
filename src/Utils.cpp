#include "headers/Utils.hpp"
sf::Font* defaultFont = nullptr;  // Define it here

void drawArrow(sf::RenderWindow* window, const sf::Vector2f& start, const sf::Vector2f& end,char label) {
    // Calculate the direction and length of the arrow
    sf::Vector2f direction = end - start;
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    float angle = std::atan2(direction.y, direction.x);

    // Draw the shaft of the arrow (a rectangle)
    sf::RectangleShape shaft(sf::Vector2f(length, -3));  // Length and width of the shaft
    shaft.setOrigin(-1.5,-1.5);
    shaft.setPosition(start);  // Position it at the start point
    shaft.setRotation(angle * 180 / 3.14159f);  // Convert from radians to degrees
    shaft.setFillColor(sf::Color::Black);

    

    window->draw(shaft);

    // Find the midpoint of the line
    sf::Vector2f midpoint = (start + end) / 2.0f;

    // Draw the arrowhead (triangle) at the midpoint
    sf::ConvexShape arrowHead;
    arrowHead.setPointCount(3);
    arrowHead.setPoint(0, midpoint); // Place the tip of the arrow at the midpoint
    arrowHead.setPoint(1, sf::Vector2f(midpoint.x - 15 * std::cos(angle - 0.5f), midpoint.y - 15 * std::sin(angle - 0.5f)));
    arrowHead.setPoint(2, sf::Vector2f(midpoint.x - 15 * std::cos(angle + 0.5f), midpoint.y - 15 * std::sin(angle + 0.5f)));
    arrowHead.setFillColor(sf::Color::Black);

    window->draw(arrowHead);

    sf::Text text(label, *defaultFont, 24);
    text.setFillColor(sf::Color::Black);

    // Set the text position right above the midpoint (adjust vertical position as needed)
text.setPosition(midpoint.x - text.getLocalBounds().width / 2,
                 midpoint.y - 30 * std::cos(angle));  // Correct offset based on rotation

    // Apply the same rotation to the text as the arrow
    text.setRotation(angle * 180 / 3.14159f);  // Convert radians to degrees

    if(start.x > end.x){
        text.setScale(-1,-1);
    }

    // Draw the text
    window->draw(text);
}
