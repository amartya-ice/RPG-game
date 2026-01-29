#include "Map.h"
#include <iostream>

Map::Map() : tilewidth(16) , tileheight(16) , TotaltilesX(0) , TotaltilesY(0) , totaltiles(0) 
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

        TotaltilesX = TileSheetTexture.getSize().x / tilewidth;
        TotaltilesY = TileSheetTexture.getSize().y / tileheight;

        totaltiles = TotaltilesX * TotaltilesY;
        
        tiles = new Tiles[totaltiles];

        for (int y = 0; y < TotaltilesY; y++) {

            for (int x = 0; x < TotaltilesX; x++) {

                int i = x + (y * TotaltilesX);
                tiles[i].id = i;
                tiles[i].position = sf::Vector2i({ x * tilewidth, y * tileheight });

               //tiles[i].texture = &TileSheetTexture;
               //tiles[i].rect = sf::IntRect({ x * tilewidth, y * tileheight }, { tilewidth ,tileheight });
               // tiles[i].sprite.setTexture(TileSheetTexture);
               // tiles[i].sprite.setTextureRect(sf::IntRect({ x * tilewidth, y * tileheight }, { tilewidth ,tileheight }));
               // tiles[i].sprite.setScale(sf::Vector2f(1, 1));
               // tiles[i].sprite.setPosition(sf::Vector2f(100 + x * tileheight * 1, 100 + y * tileheight * 1));

            }
        }

        mapsprites.reserve(6);

        for (size_t y = 0; y < 2; y++) {

            for (size_t x = 0; x < 3; x++) {

                int i = x + y * 3;
                int index = mapnumbers[i];
                mapsprites.emplace_back(TileSheetTexture);
                mapsprites[i].setTexture(TileSheetTexture);
                mapsprites[i].setTextureRect(sf::IntRect({tiles[i].position.x, tiles[i].position.y}, {tilewidth ,tileheight}));
                mapsprites[i].setScale(sf::Vector2f{ 5,5 });
                mapsprites[i].setPosition(sf::Vector2f{x * 16.f * 5.f , y * 16.f * 5.f });

            }
        }


    }
    else {
        std::cout << "Map failed to load" << std::endl;
    }

   /* sprite.setTexture(TileSheetTexture);
    sprite.setTextureRect(sf::IntRect({ 0*tilewidth, 0*tileheight }, {tilewidth, tileheight }));
    sprite.setPosition(sf::Vector2f(100.f,100.f));
    sprite.setScale(sf::Vector2f{ 5.0f,5.0f});*/
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
    //window.draw(sprite);

    for (size_t i = 0; i < 6; i++) {
        window.draw(mapsprites[i]);

    }
}
