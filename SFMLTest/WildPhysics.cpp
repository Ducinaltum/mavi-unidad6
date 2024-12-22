#include "WildPhysics.h"
#include "PhysicsTarget.h"
#include "UniformBallTarget.h"
#include "UniformVariatedBallTarget.h"
#include <iostream>



WildPhysics::WildPhysics(RenderWindow* rw)
{
	pWnd = rw;
	m_timeBetweenShots = 0;
	m_timeBetweenTargets = 1;
	m_eTime = 0;
	m_hasShot = false;
	m_croshairTarget = NULL;
	m_crosshairSize = 32;
	m_maxObjectsInScene = 3;
	Texture* crosshairTexture = new Texture();
	crosshairTexture->loadFromFile("assets/crosshair.png");
	float sizeRatio = m_crosshairSize / crosshairTexture->getSize().x;
	m_crosshairSprite.setTexture(*crosshairTexture);
	m_crosshairSprite.setScale(sizeRatio, sizeRatio);
	m_crosshairSprite.setOrigin(crosshairTexture->getSize().x / 2, crosshairTexture->getSize().y / 2);

	for (int i = 0; i < 10; i++)
	{
		if (i < 5)
		{
			m_targetSprites.push_back(
				new UniformBallTarget(rw->getSize())
			);
		}
		else
		{
			m_targetSprites.push_back(
				new UniformVariatedBallTarget(rw->getSize())
			);
		}
	}
	m_targetSprites[0]->Activate();
}

void WildPhysics::ProcessEvent(Event& evt)
{
	if (evt.type == sf::Event::MouseButtonPressed)
	{
		if (evt.key.code == sf::Mouse::Left)
		{
			m_hasShot = true;
		}
	}
}

void WildPhysics::ProcessCollisions()
{
	for (int i = 0; i < m_targetSprites.size(); i++)
	{
		if (m_targetSprites[i]->IsActive())
		{
			for (int j = i + 1; j < m_targetSprites.size(); j++)
			{
				m_targetSprites[i]->ProcessCollisions(m_targetSprites[j]);
			}
		}
	}
}

void WildPhysics::UpdateGame(float dt)
{
	m_eTime += dt;
	m_crosshairSprite.setPosition(sf::Mouse::getPosition(*pWnd).x, sf::Mouse::getPosition(*pWnd).y);
	for (int i = 0; i < m_targetSprites.size(); i++)
	{
		PhysicsTarget* target = m_targetSprites[i];
		if (target->IsActive())
		{
			if (m_hasShot)
			{
				float sqrRad = target->GetRadious() * target->GetRadious();
				float xDist = m_crosshairSprite.getPosition().x - target->GetSprite()->getPosition().x;
				float yDist = m_crosshairSprite.getPosition().y - target->GetSprite()->getPosition().y;
				if (sqrRad > (xDist * xDist) + (yDist * yDist))
				{
					std::cout << "Collision" << endl;
					target->Deactivate();
				}
			}
			m_targetSprites[i]->Update(dt);
		}
	}
	PhysicsTarget* newTarget = CheckNumberOfActiveObjectsAndPickTarget();
	if (newTarget != NULL)
	{
		newTarget->Activate();
	}

	m_hasShot = false;
}

void WildPhysics::DrawGame()
{
	for (int i = 0; i < m_targetSprites.size(); i++)
	{
		if (m_targetSprites[i]->IsActive())
		{
			pWnd->draw(*m_targetSprites[i]->GetSprite());
		}
	}
	pWnd->draw(m_crosshairSprite);
}


PhysicsTarget* WildPhysics::CheckNumberOfActiveObjectsAndPickTarget()
{
	std::vector<PhysicsTarget*> m_freeTargets;
	for (int i = 0; i < m_targetSprites.size(); i++)
	{
		if (!m_targetSprites[i]->IsActive())
		{
			m_freeTargets.push_back(m_targetSprites[i]);
		}
	}
	int activeObjects = m_targetSprites.size() - m_freeTargets.size();
	if (m_freeTargets.size() > 0 && activeObjects < m_maxObjectsInScene)
	{
		int index = rand() % m_freeTargets.size();
		return m_freeTargets[index];
	}
	return NULL;
}
