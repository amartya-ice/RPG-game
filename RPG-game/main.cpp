
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    //------------------------ INITIALIZE --------------------------------------
    sf::RenderWindow window(sf::VideoMode({ 800, 800 }), "fuck me");

    //------------------------ INITIALIZE --------------------------------------

    //------------------------ LOAD --------------------------------------------
    sf::Texture playerTexture; 
    if (playerTexture.loadFromFile("Assets/Texture/player/spritesheetskeleton.png")) {
        std::cout << "texture loaded sucessesfully!" << std::endl;
    }
    sf::Sprite playerSprite(playerTexture);
    int xcordi = 0;
    int ycordi = 0;
    playerSprite.setTextureRect(sf::IntRect({0* xcordi,0*ycordi}, {64,64}));
    playerSprite.setScale(sf::Vector2f(1, 1));
    playerSprite.setPosition(sf::Vector2f(50, 50));
    
    //------------------------ LOAD --------------------------------------------

    while (window.isOpen()) {

        //---------------------------- UPDATE ----------------------------------
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            
            if (event->is<sf::Event::KeyPressed>())
            {
                // Get the key press event info
                auto keyEvent = event->getIf<sf::Event::KeyPressed>();

                // Check if it was the 'W' key
                
                /*
                float speed = 5;
                if (keyEvent->scancode == sf::Keyboard::Scancode::W)
                {
                    playerSprite.move(sf::Vector2f(0, -speed));
                }
                if (keyEvent->scancode == sf::Keyboard::Scancode::A)
                {
                    playerSprite.move(sf::Vector2f( -speed, 0));
                }
                if (keyEvent->scancode == sf::Keyboard::Scancode::S)
                {
                    playerSprite.move(sf::Vector2f(0, speed));
                }
                if (keyEvent->scancode == sf::Keyboard::Scancode::D)
                {
                    playerSprite.move(sf::Vector2f( speed,0));
                }*/
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W)) 
            playerSprite.move(sf::Vector2f(0, -1));

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A))
            playerSprite.move(sf::Vector2f(-1, 0));

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S))
            playerSprite.move(sf::Vector2f(0, 1));

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D))
            playerSprite.move(sf::Vector2f(1, 0));
        //---------------------------- UPDATE ----------------------------------



        //---------------------------- DRAW ------------------------------------
        window.clear(sf::Color::Black);
        window.draw(playerSprite);
        window.display();
        //---------------------------- DRAW ------------------------------------


    }
}