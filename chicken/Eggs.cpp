#include "Eggs.h"



Eggs::Eggs(Resources& res, const sf::FloatRect& chikenGlobalBounds, const sf::Vector2f& chickenPosition)
{
	m_sprite.setAnimation(res.getEggAnimation(0));
	res.getSound(2)->play();//play egg sound
	m_sprite.setPosition({ chickenPosition.x + chikenGlobalBounds.width / 2 ,chickenPosition.y + chikenGlobalBounds.height + 0 });
}

Eggs::~Eggs()
{
}

void Eggs::setBrokenAnimation(Resources& res, sf::Time& tm)
{
	m_brokenTime = m_endAnimaition += tm;
	m_sprite.setAnimation(res.getEggAnimation(1));
	res.getSound(3)->play();//play broken egg sound
	m_isBroken = true;
}


