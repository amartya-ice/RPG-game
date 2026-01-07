#include "Math.h"

sf::Vector2f Math::Normalization(sf::Vector2f vector)
{
    
    float z = std::sqrt(vector.x * vector.x + vector.y * vector.y);
    vector.x = vector.x / z;
    vector.y = vector.y / z;
    return vector;
}

bool Math::Diditcollide(const sf::FloatRect& rect1, const sf::FloatRect& rect2)
{
    std::optional<sf::Rect<float>> x = rect1.findIntersection(rect2);
    return rect1.findIntersection(rect2).has_value();
}


