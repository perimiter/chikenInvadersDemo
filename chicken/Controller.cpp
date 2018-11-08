#ifdef _DEBUG
#pragma comment(lib, "sfml-main-d.lib")
#pragma comment(lib, "sfml-system-d.lib")
#pragma comment(lib, "sfml-window-d.lib")
#pragma comment(lib, "sfml-graphics-d.lib")
#pragma comment(lib, "sfml-audio-d.lib")
#pragma comment(linker, "/SUBSYSTEM:CONSOLE")
#else
#pragma comment(lib, "sfml-main.lib")
#pragma comment(lib, "sfml-system.lib")
#pragma comment(lib, "sfml-window.lib")
#pragma comment(lib, "sfml-graphics.lib")
#pragma comment(lib, "sfml-audio-d.lib")
#pragma comment(linker, "/SUBSYSTEM:WINDOWS")
#endif



#include "Controller.h"
#include "Windows.h"


Controller::Controller()
{

}


Controller::~Controller()
{
}
void Controller::play()
{
	//create board
	m_board.create(m_resources, m_window.getSize());
	//create game clock
	sf::Clock gameClock;

	sf::Time shipFireTimer = sf::milliseconds(0);
	sf::Time bossFireTimer = sf::milliseconds(0);
	//time for chikens showing up 
	sf::Time showTime = sf::milliseconds(0);

	bool noKeyWasPressed = true;
	float speed = 250;//ship speed 
	Animation* currentShipAnimation = &m_resources.getShipAnimation(1);

	while (m_window.isOpen())
	{
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				m_window.close();
				exit(EXIT_SUCCESS);
			}
			if (event.key.code == sf::Keyboard::Escape)
			{
				m_window.close();
				exit(EXIT_SUCCESS);
			}
		}

		sf::Time deltaTime = gameClock.restart();
		//accumulate time
		shipFireTimer += deltaTime;
		bossFireTimer += deltaTime;
		showTime += deltaTime;

		// if a key was pressed set the correct animation and move correctly
		sf::Vector2f movement(0.f, 0.f);
		//--------------------fire-----------------------
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			m_board.shipFire(m_resources, m_window.getSize(), shipFireTimer);
		//-------------------ship direction-------------------
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			currentShipAnimation = &m_resources.getShipAnimation(0);
			movement.y -= speed;
			noKeyWasPressed = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			currentShipAnimation = &m_resources.getShipAnimation(1);
			movement.y += speed;
			noKeyWasPressed = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{

			currentShipAnimation = &m_resources.getShipAnimation(2);
			movement.x -= speed;
			noKeyWasPressed = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			currentShipAnimation = &m_resources.getShipAnimation(3);
			movement.x += speed;
			noKeyWasPressed = false;
		}
		//---------------play sprite------------
		m_board.playAll(m_resources, currentShipAnimation, bossFireTimer);
		m_resources.setPositionForCurser(m_window);
		//-------------move sprite--------------
		m_board.moveAll(movement, deltaTime, m_window, m_resources, showTime);
		m_board.checkColisions(m_resources, m_window);
		if (noKeyWasPressed)
			m_board.resetShip(m_resources);

		noKeyWasPressed = true;
		//-------------update-----------------
		m_board.updateAll(deltaTime);
		//-----------draw-----------------------
		m_board.drawAll(m_window, m_resources, deltaTime);
		m_window.display();
		//activate boss mode
		if (!m_bossMode && m_board.noMoreChicken()) {
			m_board.setBoss(m_resources, m_window.getSize());
			m_bossMode = true;
		}
		//activate game over mode
		if (m_board.getEnd())
		{
			endGame();
		}
	}
}

//---------------------------------------------------------------------------------
void Controller::endGame()
{
	sf::Sprite back;

	if (m_board.getWin()) {
		back.setTexture(*m_resources.getSpriteSheet(14));
	}
	else {
		m_resources.getSound(5)->play();
		back.setTexture(*m_resources.getSpriteSheet(13));
	}

	float ScaleX = (float)m_window.getSize().x / m_resources.getSpriteSheet(14)->getSize().x;
	float ScaleY = (float)m_window.getSize().y / m_resources.getSpriteSheet(14)->getSize().y;
	back.setScale(ScaleX, ScaleY);

	sf::Clock ck;

	while (ck.getElapsedTime().asSeconds() < 5)
	{
		m_window.clear();
		m_window.draw(back);
		m_window.display();
	}
	exit(EXIT_SUCCESS);
}


