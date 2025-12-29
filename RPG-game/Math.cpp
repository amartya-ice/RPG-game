#include "Math.h"

sf::Vector2f Math::Normalization(sf::Vector2f vector)
{
    
    float z = std::sqrt(vector.x * vector.x + vector.y * vector.y);
    vector.x = vector.x / z;
    vector.y = vector.y / z;
    return vector;
}
