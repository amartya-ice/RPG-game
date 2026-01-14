#pragma once
#include <SFML/Graphics.hpp> 
#include "vector"
#include "Skeleton.h"



class Player
{
private:
	sf::Texture texture;
	std::vector<sf::RectangleShape> bullets;
	std::vector<sf::Vector2f> bulletDirection;

	float bulletSpeed = 0.1f;
	sf::RectangleShape boundingrectangle;
	sf::Vector2i size;
	sf::Vector2i scale;
	float maxfirerate;
	float fireratetimer;
	int iterator = 0;
	float speed = 1.0f;
	

public:
	Player();
	sf::Sprite sprite;
	
public:
	void Initialize();
	void Load();
	void Update(Skeleton& skeleton,float deltatime , sf::Vector2f mouseposition);
	void Draw(sf::RenderWindow& window);
};

