#pragma once

#include "GameObject.h"
#include "Bullets.h"
class ThrownObjects;



class SpaceShip:public GameObject
{
public:
	SpaceShip();
	~SpaceShip();
	//calculate the colum of the chiken
	unsigned getChickensCol(float stripLen, int numOfCol) const;
	void move(sf::Vector2u&,sf::Vector2f& , float );
	//create a new ship
	void create( sf::Vector2u );
	//shoot bullets
	void fire(std::vector<Bullets>&, Resources&, sf::Vector2u, sf::Time&)const;
	AnimatedSprite& getExplosionAnimation() { return m_explosion; }
	//change the animation of the explosion
	void setExplositionAnimation(Animation&anim) { m_explosion.setAnimation(anim); }
	//decrease life of the ship
	void decreaseLive();
	//set if crashed status
	void setCrashed(bool val) { m_Crashed = val; }
	//get iscrashed status
	bool getCrashed()const { return m_Crashed; }
	//how many lives left
	unsigned getLives()const { return m_lives; }
	//set the fire speed
	void speedFire() { m_fireSpeed -= sf::seconds(0.085); }
	//set the level of the fire
	void setLevelUpFire() { m_fireLevel++; }
	// get the fire level
	bool getLevelUpFire()const { return  m_fireLevel; }
	//reset all ship data
	void resetShipWeapon();
	void show(sf::Vector2u& ,float);
private:
	unsigned m_fireLevel = 0;
	bool m_Crashed = false;
	bool m_doneShow = false;
	unsigned m_lives;
	sf::Vector2u m_screenSize;
	sf::Time m_fireSpeed = sf::seconds(0.36) ;
	AnimatedSprite m_explosion;
};

