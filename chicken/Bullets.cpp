#include "Bullets.h"



Bullets::Bullets(Resources& res, const sf::Vector2f& shipPosition)
{
	m_sprite.setAnimation(res.getBulletsAnimations(0));
	m_sprite.setPosition({ shipPosition.x + 12, shipPosition.y - 15 });
}


Bullets::~Bullets()
{
}



void Bullets::move()
{
	m_sprite.move(sf::Vector2f{ 0, -5 });
	if (m_sprite.getPosition().y < -10)
		m_available = false;
}
//get col of chiken reletive to the bullet
unsigned Bullets::getChickensCol(float stripLen, int numOfCol)
{
	float x = m_sprite.getPosition().x;
	
	for(unsigned i = 0; i< numOfCol; i++)
	{
		if (x >= i*stripLen && x < (i + 1)* stripLen) {
			return i;
		}
	}
}


