#pragma once
#include "Chickens.h"


class Bullets:public GameObject
{
public:
	Bullets(Resources&,const sf::Vector2f&);
	~Bullets();
	void move();
	//get col of chiken reletive to the bullet
	unsigned getChickensCol(float, int);
};

