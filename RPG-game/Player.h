#pragma once
#include <SFML/Graphics.hpp> 
#include "vector"
#include "Skeleton.h"
#include "Bullet.h"



class Player
{
private:
	sf::Texture texture;
	std::vector<Bullet> bullets;

	float bulletSpeed = 0.1f;
	sf::RectangleShape boundingrectangle;
	sf::Vector2i size;
	sf::Vector2i scale;
	float maxfirerate = 0.f;
	float fireratetimer = 0.f;
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

