#pragma once
#include <SFML/Graphics.hpp> 
#include "Tiles.h"

class Map
{
private:
	sf::Texture TileSheetTexture;
	Tiles* tiles;
	int totaltiles;
	int tilewidth;
	int tileheight;
	int TotaltilesX;
	int TotaltilesY;  

	int mapnumbers[6] = {1,1,1,4,6,1};

	std::vector<sf::Sprite> mapsprites;
	//sf::Sprite  mapsprites[6];

public:
	

public:
	Map();
	~Map();
	void Initialize();
	void Load();
	void Update ();
	void Draw(sf::RenderWindow& window);
};

