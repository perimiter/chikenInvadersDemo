#include "Enemy.h"



Enemy::Enemy(float left, float right, Resources &res, unsigned lives)
	:m_leftBand(left), m_rightBand(right), m_movementChiken(0, 0), m_lives(lives)
{
}


Enemy::~Enemy()
{
}

//decrese the lives of the object
void Enemy::decreaseLife()
{
	m_lives--;
	if (m_lives == 0)
		m_available = false;
}



