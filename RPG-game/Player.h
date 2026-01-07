#pragma once
#include <SFML/Graphics.hpp> 
#include "vector"
#include "Skeleton.h"



class Player
{
private:
	sf::Texture texture;
	std::vector<sf::RectangleShape> bullets;
	float bulletSpeed = 0.1f;
	sf::RectangleShape boundingrectangle;
	sf::Vector2i size;
	sf::Vector2i scale;
	int iterator = 0;
	

public:
	Player();
	sf::Sprite sprite;
	
public:
	void Initialize();
	void Load();
	void Update(Skeleton skeleton);
	void Draw(sf::RenderWindow& window);
};

