
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Skeleton.h"
#include "FrameRate.h"
#include "Map.h"
#include <iostream>

int main()
{
    //------------------------ INITIALIZE --------------------------------------
    sf::RenderWindow window(sf::VideoMode({ 1920,1080 }), "fuck me");
    window.setFramerateLimit(60);

    Map map;
    map.Initialize();

    FrameRate framerate;
    framerate.Initialize();

    Player player1;
    player1.Initialize();

    Skeleton skeleton1;
    skeleton1.Initialize();
    sf::Clock clock;

   
    //------------------------ INITIALIZE --------------------------------------
 
    // -------------------------------------------- LOAD -------------------------------------------
    map.Load();
    framerate.Load();
    player1.Load();
    skeleton1.Load();
   // -------------------------------------------- LOAD --------------------------------------------
 
    while (window.isOpen()) {

        sf::Time deltatimeTimer = clock.restart();
        double deltatime = deltatimeTimer.asMicroseconds()/1000;
    
        //---------------------------- UPDATE ----------------------------------
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        sf::Vector2f mouseposition = sf::Vector2f(sf::Mouse::getPosition(window));
       
        map.Update();
        framerate.Update(deltatime);
        skeleton1.Update(deltatime);
        player1.Update(skeleton1,deltatime,mouseposition);
        //---------------------------- UPDATE ----------------------------------

        //---------------------------- DRAW ------------------------------------
        window.clear(sf::Color::Black);
        map.Draw(window);
        player1.Draw(window);
        skeleton1.Draw(window);
        framerate.Draw(window);
        window.display();
        //---------------------------- DRAW ------------------------------------
    }
}