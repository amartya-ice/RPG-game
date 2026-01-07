#pragma once
#include <SFML/Graphics.hpp>

class Math
{
public:
	static sf::Vector2f Normalization(sf::Vector2f vector);
	static bool Diditcollide(const sf::FloatRect& rect1,const sf::FloatRect& rect2 );
};
