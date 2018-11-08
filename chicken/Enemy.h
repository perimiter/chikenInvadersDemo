#pragma once
#include <SFML/Audio/Sound.hpp>
#include "GameObject.h"
#include "ThrownObjects.h"

class Enemy:public GameObject
{
public:
	Enemy(float, float, Resources&, unsigned);
	virtual ~Enemy();
	virtual void move(sf::Time&, sf::Vector2u&, sf::Time&) = 0;
	//decrese the lives of the object
	void decreaseLife();
	//play sound of hit 
	void playPakPak()const { m_pakpak->play(); }
	//mange ship fire
	virtual void fire(std::vector<std::unique_ptr<ThrownObjects>>&, Resources&, unsigned, sf::Time&) = 0;
	// is upgrade recived
	auto getHoldUpgrade()const { return m_holdUpgrade; }
	//set upgrade status
	void setHoldUpgrade(unsigned i) { m_holdUpgrade = i; }
	virtual void play (Resources&) = 0;
	virtual void show(sf::Time) = 0;
	auto getDoneShow() { return m_doneShow; }
protected:
	float m_leftBand;
	float m_rightBand;
	bool m_right = true;
	//is the enemny done with preview
	bool m_doneShow = false;
	unsigned m_lives;
	unsigned m_fire;
	unsigned m_holdUpgrade = 0;
	sf::Vector2f m_movementChiken;
	//sound for the hit
	sf::Sound* m_pakpak = nullptr;
};

