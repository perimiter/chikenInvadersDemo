#pragma once
// ReSharper disable CppUnusedIncludeDirective
#include <string>
#include <map>
#include "Chickens.h"
#include "Bullets.h"
#include "Boss.h"
#include "SpaceShip.h"
#include "Eggs.h"
#include "Upgrade.h"
#include "Gift.h"
// ReSharper restore CppUnusedIncludeDirective

class GameObject;


class colission
{
public:
	colission();
	~colission();
	void processCollision(GameObject& object1,
		GameObject& object2);
};


