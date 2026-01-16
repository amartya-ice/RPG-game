#pragma once
#include <SFML/Graphics.hpp> 



class Map
{
private:
	sf::Texture TileSheetTexture;
	sf::Sprite sprite;
	bool textureLoaded = false;
public:

public:
	Map();
	~Map();
	void Initialize();
	void Load();
	void Update ();
	void Draw(sf::RenderWindow& window);
};

