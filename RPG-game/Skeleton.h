#pragma once
#include <SFML/Graphics.hpp> 


class Skeleton
{
private:
	sf::Texture texture;
	sf::Vector2i size;
	sf::Vector2i scale;
	sf::RectangleShape boundingrectangle;
	float speed = 1.0f;
	

public:
	sf::Sprite sprite;
	int health;
	sf::Font font;
	sf::Text Healthtext;

public:
	Skeleton();
	~Skeleton();
	void Changehealth(int hp);
	void Initialize();
	void Load();
	void Update(float deltatime);
	void Draw(sf::RenderWindow& window);
};
