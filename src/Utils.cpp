#include "headers/Utils.hpp"
sf::Font *defaultFont = nullptr; // Define it here

void drawArrow(sf::RenderWindow *window, const sf::Vector2f &start, const sf::Vector2f &end, float passThroughOffset, char label)
{
    // Calculate the direction and length of the arrow
    sf::Vector2f direction = end - start;
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    float angle = std::atan2(direction.y, direction.x);

    // The midpoint of the arrow (this is fixed and the pass-through point is offset from it)
    sf::Vector2f midpoint = (start + end) / 2.0f;

    // Calculate the pass-through point by adding the vertical offset
    sf::Vector2f passThrough = midpoint + sf::Vector2f(0, passThroughOffset);

    // Draw the first shaft segment (from start to passThrough)
    sf::Vector2f direction1 = passThrough - start;
    float length1 = std::sqrt(direction1.x * direction1.x + direction1.y * direction1.y);
    float angle1 = std::atan2(direction1.y, direction1.x);

    sf::RectangleShape shaft1(sf::Vector2f(length1, -3)); // Length and width of the shaft
    shaft1.setOrigin(-1.5, -1.5);
    shaft1.setPosition(start);
    shaft1.setRotation(angle1 * 180 / 3.14159f); // Convert from radians to degrees
    shaft1.setFillColor(sf::Color::Black);
    window->draw(shaft1);

    // Draw the second shaft segment (from passThrough to end)
    sf::Vector2f direction2 = end - passThrough;
    float length2 = std::sqrt(direction2.x * direction2.x + direction2.y * direction2.y);
    float angle2 = std::atan2(direction2.y, direction2.x);

    sf::RectangleShape shaft2(sf::Vector2f(length2, -3)); // Length and width of the shaft
    shaft2.setOrigin(-1.5, -1.5);
    shaft2.setPosition(passThrough);
    shaft2.setRotation(angle2 * 180 / 3.14159f);
    shaft2.setFillColor(sf::Color::Black);
    window->draw(shaft2);

    // Draw the arrowhead at the end point
    // First arrowhead at the middle of the first segment (start to passThrough)
    sf::Vector2f midpoint1 = (start + passThrough) / 2.0f;
    sf::ConvexShape arrowHead1;
    arrowHead1.setPointCount(3);
    arrowHead1.setPoint(0, midpoint1);
    arrowHead1.setPoint(1, sf::Vector2f(midpoint1.x - 15 * std::cos(angle1 - 0.5f), midpoint1.y - 15 * std::sin(angle1 - 0.5f)));
    arrowHead1.setPoint(2, sf::Vector2f(midpoint1.x - 15 * std::cos(angle1 + 0.5f), midpoint1.y - 15 * std::sin(angle1 + 0.5f)));
    arrowHead1.setFillColor(sf::Color::Black);
    window->draw(arrowHead1);

    // Second arrowhead at the middle of the second segment (passThrough to end)
    sf::Vector2f midpoint2 = (passThrough + end) / 2.0f;
    sf::ConvexShape arrowHead2;
    arrowHead2.setPointCount(3);
    arrowHead2.setPoint(0, midpoint2);
    arrowHead2.setPoint(1, sf::Vector2f(midpoint2.x - 15 * std::cos(angle2 - 0.5f), midpoint2.y - 15 * std::sin(angle2 - 0.5f)));
    arrowHead2.setPoint(2, sf::Vector2f(midpoint2.x - 15 * std::cos(angle2 + 0.5f), midpoint2.y - 15 * std::sin(angle2 + 0.5f)));
    arrowHead2.setFillColor(sf::Color::Black);
    window->draw(arrowHead2);

    // Create the text label
    sf::Text text(label, *defaultFont, 24);
    text.setFillColor(sf::Color::Black);

    // Set the text position right above the midpoint, with a vertical offset (adjusted for rotation)
    text.setPosition(passThrough.x - text.getLocalBounds().width / 2,
                     passThrough.y - 30 * std::cos(angle1)); // Correct vertical offset based on rotation

    // Apply the same rotation to the text as the arrow
    text.setRotation(angle1 * 180 / 3.14159f);

    if (start.x > end.x)
    {
        text.setScale(-1, -1); // Flip the text horizontally
    }

    // Draw the text
    window->draw(text);
}
