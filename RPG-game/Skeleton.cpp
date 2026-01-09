#include "Skeleton.h"
#include <iostream>

Skeleton::Skeleton() : sprite(texture)
{
}

void Skeleton::Initialize() {
    size = sf::Vector2i(64, 64);
    scale = sf::Vector2i(1, 1);

    boundingrectangle.setFillColor(sf::Color::Transparent);
    boundingrectangle.setOutlineColor(sf::Color::Red);
    boundingrectangle.setOutlineThickness(2);
}

void Skeleton::Load(){
    if (texture.loadFromFile("Assets/Texture/skeleton/spritesheetskeleton.png")) {
        std::cout << "skeleton texture loaded sucessesfully!" << std::endl;
    }
    sprite.setTexture(texture);
    int xcordiS = 0;
    int ycordiS = 2;
    sprite.setTextureRect(sf::IntRect({ size.x * xcordiS,size.y * ycordiS }, { size.x ,size.y }));
    sprite.setPosition(sf::Vector2f(50, 50));
    sprite.setScale(sf::Vector2f{ scale });
    boundingrectangle.setSize(sf::Vector2f(size.x * scale.x, size.y * scale.y));


}

void Skeleton::Update(float deltatime){
    boundingrectangle.setPosition(sprite.getPosition());
}

void Skeleton::Draw(sf::RenderWindow& window){
    window.draw(sprite);
    window.draw(boundingrectangle);
}