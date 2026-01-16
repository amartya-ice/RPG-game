#include "Map.h"
#include <iostream>

Map::Map() : sprite(TileSheetTexture)
{
}

Map::~Map()
{
}


void Map::Initialize()
{
    
    if (TileSheetTexture.loadFromFile("Assets/World/Prison/Tileset.png")) {
        std::cout << "Map tileset texture loaded sucessesfully!" << std::endl;
        std::cout << "Tile size:"
            << TileSheetTexture.getSize().x << "x   "
            << TileSheetTexture.getSize().y << "y" << std::endl;

    }
    else {
        std::cout << "Map failed to load" << std::endl;
    }

    sprite.setTexture(TileSheetTexture);

    sprite.setPosition(sf::Vector2f(0.f,0.f));
    sprite.setScale(sf::Vector2f{ 2.0f,2.0f});
}

void Map::Load()
{

}

void Map::Update()
{

}

void Map::Draw(sf::RenderWindow& window)
{
    /*sf::RectangleShape debug(sf::Vector2f(256, 256));
    debug.setFillColor(sf::Color::Red);
    debug.setPosition(sf::Vector2f(0, 0));
    window.draw(debug);*/
    window.draw(sprite);
}
