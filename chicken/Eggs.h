#pragma once
#include "ThrownObjects.h"
#include<SFML\Graphics\Rect.hpp>

class Eggs :
	public ThrownObjects
{
public:
	Eggs(Resources& ,const sf::FloatRect&,const sf::Vector2f& );
	~Eggs();
	//is egg broken status
	bool getBroken()const { return  m_isBroken; }
	//change the animation to a broken egg
	void setBrokenAnimation(Resources&res, sf::Time& tm);
	void sumBrokenTime(sf::Time &tm) { m_endAnimaition += tm; }
	//dilay time for broken egg
	bool endBrokenAnimation()const { return m_endAnimaition.asSeconds() - m_brokenTime.asSeconds() > 1.5; }
private:
	sf::Time m_brokenTime=sf::seconds(0),
	m_endAnimaition = sf::seconds(0) ;
	bool m_isBroken = false;
};

