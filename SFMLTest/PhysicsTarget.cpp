#include "PhysicsTarget.h"
#include <iostream>

PhysicsTarget::PhysicsTarget(Vector2u winSize, std::string path)
{
	m_isActive = false;
	m_velocity = new Vector2f(0, 0);
	m_winSize = new Vector2f(winSize.x, winSize.y);
	m_radious = (float)(rand() % 32) + 32;
	Texture* ballTexture = new Texture();
	ballTexture->loadFromFile(path);
	float targetSize = (m_radious * 2) / ballTexture->getSize().x;
	m_sprite.setTexture(*ballTexture);
	m_sprite.setScale(targetSize, targetSize);
	m_sprite.setOrigin(ballTexture->getSize().x / 2, ballTexture->getSize().y / 2);
}

void PhysicsTarget::ProcessCollisions(PhysicsTarget* m_targetSprite)
{
	if (m_targetSprite->IsActive() && m_targetSprite != this)
	{
		float minDist = m_targetSprite->GetRadious() + m_radious;
		float xDist = m_sprite.getPosition().x - m_targetSprite->GetSprite()->getPosition().x;
		float yDist = m_sprite.getPosition().y - m_targetSprite->GetSprite()->getPosition().y;
		if ((minDist * minDist) < (xDist * xDist) + (yDist * yDist))
		{
			OnCollision();
			m_targetSprite->OnCollision();
		}
	}
}

void PhysicsTarget::Update(float dt)
{
	if (m_sprite.getPosition().x < -800 || m_sprite.getPosition().x > 1600 ||
		m_sprite.getPosition().y < -800 || m_sprite.getPosition().y > 1600)
	{
		Deactivate();
	}

}

Sprite* PhysicsTarget::GetSprite()
{
	return &m_sprite;
}

bool PhysicsTarget::IsActive()
{
	return m_isActive;
}

void PhysicsTarget::Activate()
{

	m_isActive = true;
}

void PhysicsTarget::Deactivate()
{
	std::cout << "Parent" << std::endl;
	m_isActive = false;
}

void PhysicsTarget::OnCollision()
{
	m_velocity->x *= -1;
	m_velocity->y *= -1;
}

int PhysicsTarget::GetRadious()
{
	return m_radious;
}


