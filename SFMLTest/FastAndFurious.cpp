#include "FastAndFurious.h"

FastAndFurious::FastAndFurious(RenderWindow* rw) : Game()
{
	pWnd = rw;
	m_startSpeed = 0.1f;
	m_currentSpeed = m_startSpeed;
	m_endSpeed = 1.0f;
	m_incrementStep = 0.01f;
	Texture * ballTexture = new Texture();
	ballTexture->loadFromFile("assets/rcircle.png");
	m_ballSprite.setTexture(*ballTexture);
}

void FastAndFurious::UpdateGame(float dt)
{
	Vector2f pos = m_ballSprite.getPosition();
	pos.x += m_currentSpeed;
	if (pos.x > pWnd->getSize().x)
	{
		pos.x = (float)-m_ballSprite.getTextureRect().width;
		m_currentSpeed += m_incrementStep;
		if (m_currentSpeed > m_endSpeed)
		{
			m_currentSpeed = m_endSpeed;
		}
	}
	m_ballSprite.setPosition(pos);
}

void FastAndFurious::DrawGame()
{
	pWnd->draw(m_ballSprite);
}


