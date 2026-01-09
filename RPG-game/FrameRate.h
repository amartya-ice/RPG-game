#pragma once
#include <SFML/Graphics.hpp> 
class FrameRate
{
private:
	sf::Font font;
	sf::Text FPScounter;
	double timer;
	int FPSdisplay;
	
public:
	FrameRate();
	void Initialize();
	void Load();
	void Update(double deltatime);
	void Draw(sf::RenderWindow& window);
};

