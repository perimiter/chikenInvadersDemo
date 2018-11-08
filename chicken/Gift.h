#pragma once
#include "ThrownObjects.h"
#include <SFML/Graphics.hpp>


class Gift :
	public ThrownObjects
{
public:
	Gift(Resources&, const sf::Vector2f&);
	~Gift();
};

