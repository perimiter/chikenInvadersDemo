#include "Chickens.h"


//-------------------------
Chickens::Chickens(Resources&res, float left, float right, unsigned row)
	:Enemy{ left, right, res, 3 }
{
	m_fire = res.RandomizeVal(1, 1200);//randomize fire time
	m_position = res.RandomizeVal(m_leftBand + 10, m_rightBand - 110);//randomize position
	m_sprite.setPosition(sf::Vector2f(-100, row * 85));
	m_sprite.setAnimation(res.getChickenAnimation(0));
	m_pakpak = res.getSound(1);//set the sound of the hit
}

Chickens::~Chickens()
{
}



void Chickens::move(sf::Time& frameTime, sf::Vector2u& screenSize, sf::Time& showTime)
{
	//preview manegment
	if (!m_doneShow) {
		show(frameTime);
		return;
	}
	//moving right
	if (m_right)
		m_movementChiken.x += 50.f;
	else
		m_movementChiken.x -= 50.f;
	//set if movment is right
	if (abs(m_sprite.getPosition().x - m_leftBand) < 5.f)
		m_right = true;
	//set if movment is not right
	if (abs(m_sprite.getPosition().x + 100 - m_rightBand) < 5.f)
		m_right = false;
	//move down
	if (showTime.asSeconds() > 7)
		m_movementChiken.y += 25;
	//move
	m_sprite.move(m_movementChiken * frameTime.asSeconds());
	//reset direction vector
	m_movementChiken.x = 0;
	m_movementChiken.y = 0;
	//get the chiken back to the top
	if (m_sprite.getPosition().y > screenSize.y + 0)
		m_sprite.setPosition(m_sprite.getPosition().x, -90.f);
}
//fire eggs
void Chickens::fire(std::vector<std::unique_ptr<ThrownObjects>>& eggs, Resources &res, unsigned fire, sf::Time&)
{
	if (m_doneShow && fire == m_fire)
		eggs.emplace_back(std::make_unique <Eggs>(res, m_sprite.getGlobalBounds(), m_sprite.getPosition()));
}
//chickens show up from the left
void Chickens::show(sf::Time deltaTime)
{
	m_movementChiken.x += 2;
	m_sprite.move(m_movementChiken * deltaTime.asSeconds());
	if (abs(m_sprite.getPosition().x + 100 - m_position) < 10.f)
		m_doneShow = true;
}