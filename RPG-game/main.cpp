
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Skeleton.h"

int main()
{
    //------------------------ INITIALIZE --------------------------------------
    sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "fuck me");
    Player player1;
    player1.Initialize();

    Skeleton skeleton1;
    skeleton1.Initialize();
    //------------------------ INITIALIZE --------------------------------------
    // 
    // -------------------------------------------- LOAD --------------------------------------------
    player1.Load();
    skeleton1.Load();
   // -------------------------------------------- LOAD --------------------------------------------
 
    while (window.isOpen()) {

        //---------------------------- UPDATE ----------------------------------
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        skeleton1.Update();
        player1.Update(skeleton1);
        //---------------------------- UPDATE ----------------------------------

        //---------------------------- DRAW ------------------------------------
        window.clear(sf::Color::Black);
        player1.Draw(window);
        skeleton1.Draw(window);
        window.display();
        //---------------------------- DRAW ------------------------------------
    }
}

 