#pragma once
#include <vector>
#include <memory>
#include "Bullets.h"
#include "ThrownObjects.h"
#include "SpaceShip.h"
#include "Resources.h"
#include "Gift.h"
#include "Boss.h"
#include "colission.h"

class Resources;

class Board
{
public:
	Board();
	~Board();
	//create board inshialize veriabls
	void create(Resources&,sf::Vector2u);
	void playAll(Resources&, Animation*, sf::Time&);
	void moveAll(sf::Vector2f &, sf::Time&,sf::RenderWindow&, Resources&, sf::Time&);
	void updateAll(sf::Time&);
	void drawAll(sf::RenderWindow&, Resources&,sf::Time&);
	//fire from ship
	void shipFire(Resources&, sf::Vector2u, sf::Time&);
	//resest ship to default
	void resetShip(Resources& res) { m_ship.setAnimation(res.getShipAnimation(1)); }
	void checkColisions(Resources&,sf::RenderWindow&);
	//check if there are no more chickens
	bool noMoreChicken();
	bool getEnd() { return m_end; }
	bool getWin() { return m_win; }
	// change to boss mode
	void setBoss(Resources&, sf::Vector2u);
private:
	colission m_collisionMangment;
	std::vector<std::vector<std::unique_ptr<Enemy>>> m_chickens;
	std::vector<Bullets> m_bullets;
	std::vector<std::unique_ptr<ThrownObjects>> m_eggs;
	std::vector<std::unique_ptr<ThrownObjects>> m_giftsAndUpgrade;
	std::vector<sf::Vector2f> m_boomPlace;
	AnimatedSprite m_boomAnimation;//explosion animation
	SpaceShip m_ship;
	AnimatedSprite m_background;
	float m_stripLen = 0.f;
	unsigned m_chickensCol = 0;
	unsigned m_numOfChickenInRow = 4;
	bool m_bossMode = false;
	bool m_end = false;
	bool m_win = false;
};

