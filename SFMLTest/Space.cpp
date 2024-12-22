#include "Space.h"
#include <iostream>

Space::Space(RenderWindow* rw) : Game()
{
	pWnd = rw;
	m_acceleration = 5000;
	m_maxSpeed = 10000;
	m_friction = 0.0025;
	m_velocity = new Vector2f(0, 0);
	m_input = new Vector2f(0, 0);
	Texture* ballTexture = new Texture();
	ballTexture->loadFromFile("assets/rcircle.png");
	m_ballSprite.setTexture(*ballTexture);
}

void Space::ProcessEvent(Event& evt)
{
	m_input->x = 0;
	m_input->y = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		m_input->x -= 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		m_input->x += 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		m_input->y -= 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		m_input->y += 1;
}

void Space::ProcessCollisions()
{
	Vector2f ballPos = m_ballSprite.getPosition();
	if (ballPos.x < 0)
	{
		ballPos.x = 0;
		m_velocity->x *= -1;
	}
	else if (ballPos.x + m_ballSprite.getGlobalBounds().width > pWnd->getSize().x)
	{
		ballPos.x = pWnd->getSize().x - m_ballSprite.getGlobalBounds().width;
		m_velocity->x *= -1;
	}
	if (ballPos.y < 0)
	{
		ballPos.y = 0;
		m_velocity->y *= -1;
	}
	else if (ballPos.y + m_ballSprite.getGlobalBounds().height > pWnd->getSize().y)
	{
		ballPos.y = pWnd->getSize().y - m_ballSprite.getGlobalBounds().height;
		m_velocity->y *= -1;
	}
	m_ballSprite.setPosition(ballPos);
}

void Space::UpdateGame(float dt)
{
	Vector2f ballPos = m_ballSprite.getPosition();

	m_velocity->x += m_input->x * m_acceleration * dt;
	m_velocity->y += m_input->y * m_acceleration * dt;

	m_velocity->x *= 1 - m_friction;
	m_velocity->y *= 1 - m_friction;

	if (m_velocity->x > m_maxSpeed)
	{
		m_velocity->x = m_maxSpeed;
	}
	if (m_velocity->y > m_maxSpeed)
	{
		m_velocity->y = m_maxSpeed;
	}

	ballPos.x += m_velocity->x * dt;
	ballPos.y += m_velocity->y * dt;

	m_ballSprite.setPosition(ballPos);
}

void Space::DrawGame()
{
	pWnd->draw(m_ballSprite);
}
