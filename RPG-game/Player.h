#pragma once
#include <SFML/Graphics.hpp> 


class Player
{
private:
	sf::Texture texture;
	std::vector<sf::RectangleShape> bullets;
	float bulletSpeed = 0.1f;
	
public:
	Player();
	sf::Sprite sprite;
	
public:
	void Initialize();
	void Load();
	void Update(Skeleton skeleton);
	void Draw(sf::RenderWindow& window);
};

