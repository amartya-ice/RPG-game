#include "Player.h"
#include<iostream>
#include "Skeleton.h"
#include "Math.h"

// Ensure sprite is constructed with the texture so a default constructor is not required
Player::Player() : sprite(texture)
{
}

void Player::Initialize()
{
}

void Player::Load()
{
    if (texture.loadFromFile("Assets/Texture/player/spritesheetskeleton.png")) {
        std::cout << "player texture loaded sucessesfully!" << std::endl;
    }
    sprite.setTexture(texture);
    int xcordi = 0;
    int ycordi = 0;
    sprite.setTextureRect(sf::IntRect({ 0 * xcordi,0 * ycordi }, { 64,64 }));
    sprite.setScale(sf::Vector2f{ 1,1 });
    sprite.setPosition(sf::Vector2f(800, 800));
}

void Player::Update(Skeleton skeleton)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W))
        sprite.move(sf::Vector2f(0, -1));

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A))
        sprite.move(sf::Vector2f(-1, 0));

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S))
        sprite.move(sf::Vector2f(0, 1));

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D))
        sprite.move(sf::Vector2f(1, 0));

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        bullets.push_back(sf::RectangleShape(sf::Vector2f(10, 50)));

        int i = bullets.size() - 1;
        bullets[i].setPosition(sprite.getPosition());
    }

    for (size_t i = 0; i < bullets.size(); i++) {
        sf::Vector2f bulletDirection = skeleton.sprite.getPosition() - bullets[i].getPosition();
        bulletDirection = Math::Normalization(bulletDirection);
        bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
    }
}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
    for (size_t i = 0; i < bullets.size(); i++) {
        window.draw(bullets[i]);
    }
}
