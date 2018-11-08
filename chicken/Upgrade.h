#pragma once
#include "ThrownObjects.h"
class Upgrade :
	public ThrownObjects
{
public:
	Upgrade(Resources&, const sf::Vector2f&);
	~Upgrade();
};

