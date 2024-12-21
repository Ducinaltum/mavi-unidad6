#include "Bounce.h"

Bounce::Bounce(RenderWindow* rw) : Game()
{
	pWnd = rw;
	m_acceleration = 0.005;
	m_maxSpeed = 5;
	m_friction = 0.001;
	m_gravity = 9.8;
	m_velocity = new Vector2f(0, 0);
	Texture* ballTexture = new Texture();
	ballTexture->loadFromFile("assets/rcircle.png");
	m_ballSprite.setTexture(*ballTexture);
	m_ballSprite.setPosition((rw->getSize().x / 2) - (m_ballSprite.getLocalBounds().width/2), 0);
}

void Bounce::ProcessCollisions()
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

void Bounce::UpdateGame(float dt)
{
	Vector2f ballPos = m_ballSprite.getPosition();
	m_velocity->y += m_gravity * m_acceleration * dt;
	m_velocity->y *= 1 - m_friction;
	ballPos.y += m_velocity->y * dt;
	m_ballSprite.setPosition(ballPos);
}

void Bounce::DrawGame()
{
	pWnd->draw(m_ballSprite);
}
