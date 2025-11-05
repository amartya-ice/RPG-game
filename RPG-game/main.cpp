
#include <SFML/Graphics.hpp>

int main()
{
    //------------------------ INITIALIZE --------------------------------------
    sf::RenderWindow window(sf::VideoMode({ 800, 800 }), "fuck me");

    //creating a circle
    sf::CircleShape shape(50);
    shape.setFillColor(sf::Color::Green);
    shape.setOutlineThickness(10.0f);
    shape.setOutlineColor(sf::Color::Blue);
    shape.setPosition(sf::Vector2f(100, 100));
    shape.setPointCount(100.0f);

    // create an empty shape
    sf::ConvexShape convex;
    convex.setPointCount(5);
    convex.setPoint(0, { 0.f, 0.f });
    convex.setPoint(1, { 150.f, 10.f });
    convex.setPoint(2, { 120.f, 90.f });
    convex.setPoint(3, { 30.f, 100.f });
    convex.setPoint(4, { 0.f, 50.f });
    convex.setPosition(sf::Vector2f(20, 20));

    //------------------------ INITIALIZE --------------------------------------
    while (window.isOpen()) {

        //---------------------------- UPDATE ----------------------------------
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

        }
        //---------------------------- UPDATE ----------------------------------



        //---------------------------- DRAW ------------------------------------
        window.clear(sf::Color::Black);
        window.draw(shape);
        window.draw(convex);
        window.display();
        //---------------------------- DRAW ------------------------------------


    }
}