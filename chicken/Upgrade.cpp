#include "Upgrade.h"



Upgrade::Upgrade(Resources& res, const sf::Vector2f& chickenPosition)
{
	m_sprite.setAnimation(res.getUpgradeAnimation());
	m_sprite.setPosition({ chickenPosition.x + 50, chickenPosition.y + 120 });
}


Upgrade::~Upgrade()
{
}
