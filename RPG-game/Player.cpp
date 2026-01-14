#include "Player.h"
#include<iostream>

#include "Math.h"

// Ensure sprite is constructed with the texture so a default constructor is not required
Player::Player() : sprite(texture) , maxfirerate(150) , fireratetimer(0)
{
}

void Player::Initialize()
{
    size = sf::Vector2i(64, 64);
    scale = sf::Vector2i(1, 1);
 
    boundingrectangle.setFillColor(sf::Color::Transparent);
    boundingrectangle.setOutlineColor(sf::Color::Red);
    boundingrectangle.setOutlineThickness(2);

   
}

void Player::Load()
{
    if (texture.loadFromFile("Assets/Texture/player/spritesheetskeleton.png")) {
        std::cout << "player texture loaded sucessesfully!" << std::endl;
    }
    sprite.setTexture(texture);
    int xcordi = 0;
    int ycordi = 0;
    sprite.setTextureRect(sf::IntRect({ size.x * xcordi,size.y * ycordi }, { size.x,size.y }));
    sprite.setScale(sf::Vector2f{ scale});
    sprite.setPosition(sf::Vector2f(600, 600));
    boundingrectangle.setSize(sf::Vector2f(size.x*scale.x, size.y*scale.y));

}

void Player::Update(Skeleton& skeleton,float deltatime, sf::Vector2f mouseposition)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W))
        sprite.move(sf::Vector2f(0, -1) * deltatime * speed);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A))
        sprite.move(sf::Vector2f(-1, 0) * deltatime * speed);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S))
        sprite.move(sf::Vector2f(0, 1) * deltatime * speed);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D))
        sprite.move(sf::Vector2f(1, 0) * deltatime * speed);

    fireratetimer += deltatime;
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && fireratetimer > maxfirerate) {
        bullets.push_back(sf::RectangleShape(sf::Vector2f(10, 50)));
        bulletDirection.push_back(sf::Vector2f(1,1) )   ;

        int i = bullets.size() - 1;
        bullets[i].setPosition(sprite.getPosition());
        fireratetimer = 0;
        bulletDirection[i] = mouseposition - bullets[i].getPosition();
        bulletDirection[i] = Math::Normalization(bulletDirection[i]);
    }
    

    for (size_t i = 0; i < bullets.size(); i++ ) {
       
        bullets[i].setPosition(bullets[i].getPosition() + bulletDirection[i] * bulletSpeed * deltatime);
        
        if (skeleton.health > 0) {

            if (Math::Diditcollide(bullets[i].getGlobalBounds(), skeleton.sprite.getGlobalBounds())) {
                skeleton.Changehealth(-10);
                bullets.erase(bullets.begin() + i);
                // std::cout << "Skeleton health:" << skeleton.health << std::endl;
            }
        }
       
    }

    boundingrectangle.setPosition(sprite.getPosition());

}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(boundingrectangle);
    window.draw(sprite);
    for (size_t i = 0; i < bullets.size(); i++) {
        window.draw(bullets[i]);
    }
    
    
}
