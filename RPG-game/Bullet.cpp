#include "Bullet.h"
#include "Math.h"


Bullet::Bullet(): speed(0.f), direction(0.f, 0.f)
{
}

Bullet::~Bullet()
{
}


void Bullet::Initialize(const sf::Vector2f position , sf::Vector2f target , float speed)
{
	this->speed = speed;
	rectangleshape.setSize(sf::Vector2f(10, 50));
	rectangleshape.setPosition(position);
	direction = Math::Normalization(target - position);
}

void Bullet::Load()
{
}

void Bullet::Update(float deltatime)
{
	rectangleshape.setPosition(rectangleshape.getPosition() + direction * speed * deltatime);

}

void Bullet::Draw(sf::RenderWindow& window)
{
	window.draw(rectangleshape);
}
