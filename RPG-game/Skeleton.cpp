#include "Skeleton.h"
#include <iostream>

Skeleton::Skeleton() : sprite(texture)
{
}

void Skeleton::Initialize() {
}

void Skeleton::Load(){
    if (texture.loadFromFile("Assets/Texture/skeleton/spritesheetskeleton.png")) {
        std::cout << "skeleton texture loaded sucessesfully!" << std::endl;
    }
    sprite.setTexture(texture);
    int xcordiS = 0;
    int ycordiS = 2;
    sprite.setTextureRect(sf::IntRect({ 64 * xcordiS,64 * ycordiS }, { 64,64 }));
    sprite.setPosition(sf::Vector2f(50, 50));
}

void Skeleton::Update(){
}

void Skeleton::Draw(sf::RenderWindow& window){
    window.draw(sprite);
}