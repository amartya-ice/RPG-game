#pragma once
#include <SFML/Graphics.hpp> 

class Bullet
{
private:
	float speed ;
	sf::Vector2i direction;
	float maxfirerate;
	float fireratetimer;
public:
	sf::RectangleShape bullet;

public:
	Bullet();
	~Bullet();
	void Initialize();
	void Load();
	void Update(float deltatime, sf::Vector2f mouseposition);
	void Draw(sf::RenderWindow& window);

};

