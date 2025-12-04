
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>


sf::Vector2f Normalization(sf::Vector2f vector)  {
    float z = std::sqrt(vector.x * vector.x + vector.y * vector.y);
    vector.x = vector.x / z;
    vector.y = vector.y / z;
    return vector;
}



int main()
{
    //------------------------ INITIALIZE --------------------------------------
    sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "fuck me");

    //------------------------ INITIALIZE --------------------------------------


    // -------------------------------------------- LOAD --------------------------------------------
    sf::RectangleShape Bullet({ 10,20 }); 
    


    //------------------- SKELETON -------------------
    sf::Texture skeletonTexture;
    if (skeletonTexture.loadFromFile("Assets/Texture/skeleton/spritesheetskeleton.png")) {
        std::cout << "skeleton texture loaded sucessesfully!" << std::endl;
    }
    sf::Sprite skeletonSprite(skeletonTexture);
    int xcordiS = 0;
    int ycordiS = 2;
    skeletonSprite.setTextureRect(sf::IntRect({ 64 * xcordiS,64 * ycordiS }, { 64,64 }));
    skeletonSprite.setPosition(sf::Vector2f(50,50));
    //------------------- SKELETON -------------------
    
    
    //------------------- PLAYER -------------------
    sf::Texture playerTexture; 
    if (playerTexture.loadFromFile("Assets/Texture/player/spritesheetskeleton.png")) {
        std::cout << "player texture loaded sucessesfully!" << std::endl;
    }
    sf::Sprite playerSprite(playerTexture);
    int xcordi = 0;
    int ycordi = 0;
    playerSprite.setTextureRect(sf::IntRect({0* xcordi,0*ycordi}, {64,64}));
    playerSprite.setScale(sf::Vector2f{1,1});
    playerSprite.setPosition(sf::Vector2f(800, 800));
    //------------------- PLAYER -------------------


   // -------------------------------------------- LOAD --------------------------------------------
    //Bullet.setPosition(playerSprite.getPosition());

    //sf::Vector2f direction = skeletonSprite.getPosition() - playerSprite.getPosition();
    //direction = Normalization(direction);

    //float speed = 1.0f;

    std::vector<sf::RectangleShape> bullets;
    float bulletSpeed = 0.1f;



    while (window.isOpen()) {

        //---------------------------- UPDATE ----------------------------------
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }


        //Bullet.setPosition(Bullet.getPosition() + direction * speed);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W)) 
            playerSprite.move(sf::Vector2f(0, -1));

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A))
            playerSprite.move(sf::Vector2f(-1, 0));

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S))
            playerSprite.move(sf::Vector2f(0, 1));

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D))
            playerSprite.move(sf::Vector2f(1, 0));
        

        if ( sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
            bullets.push_back(sf::RectangleShape(sf::Vector2f(10, 50)));

            int i = bullets.size() - 1;
            bullets[i].setPosition(playerSprite.getPosition());
           


        }

        for (size_t i =0 ; i < bullets.size(); i++) {
            sf::Vector2f bulletDirection = skeletonSprite.getPosition() - bullets[i].getPosition();
            bulletDirection = Normalization(bulletDirection);
            bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
        }
        //---------------------------- UPDATE ----------------------------------



        //---------------------------- DRAW ------------------------------------
        window.clear(sf::Color::Black);
        window.draw(playerSprite);
        for (size_t i = 0; i < bullets.size(); i++) {
            window.draw(bullets[i]);
        }
        window.draw(skeletonSprite);
        window.display();
        //---------------------------- DRAW ------------------------------------


    }
}


/*if (event->is<sf::Event::KeyPressed>())
{
    // Get the key press event info
    auto keyEvent = event->getIf<sf::Event::KeyPressed>();

    // Check if it was the 'W' key


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
    }
}*/
 