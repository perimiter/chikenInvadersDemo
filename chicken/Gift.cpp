#include "Gift.h"




Gift::Gift(Resources &res, const sf::Vector2f &chickenPosition)
{
	m_sprite.setAnimation(res.getGiftAnimation());
	m_sprite.setPosition({ chickenPosition.x + 50, chickenPosition.y + 120 });
}


Gift::~Gift()
{
}


