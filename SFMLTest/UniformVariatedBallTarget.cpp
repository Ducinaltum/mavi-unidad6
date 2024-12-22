#include "UniformVariatedBallTarget.h"
#include <iostream>

UniformVariatedBallTarget::UniformVariatedBallTarget(Vector2u winSize) : PhysicsTarget(winSize, "assets/bcircle.png")
{
	m_acceleration = 50.0f;
	m_friction = 0.001f;
}

void UniformVariatedBallTarget::ProcessCollisions(PhysicsTarget* m_targetSprite)
{
	PhysicsTarget::ProcessCollisions(m_targetSprite);
	Vector2f ballPos = m_sprite.getPosition();
	if (ballPos.y + m_radious > m_winSize->y)
	{
		ballPos.y = m_winSize->y - m_radious;
		m_velocity->y *= -1;
	}
	m_sprite.setPosition(ballPos);
}

void UniformVariatedBallTarget::Update(float dt)
{
	PhysicsTarget::Update(dt);
	Vector2f ballPos = m_sprite.getPosition();
	m_velocity->y += m_gravity * m_acceleration * dt;
	m_velocity->y *= 1 - m_friction;
	ballPos.y += m_velocity->y * dt;
	m_sprite.setPosition(ballPos);
}

void UniformVariatedBallTarget::Activate()
{
	PhysicsTarget::Activate();
	int xPosSpawn = rand() % 800;
	int yPosSpawn = -64;
	Vector2f startPos(xPosSpawn, yPosSpawn);
	m_sprite.setPosition(startPos);
}
/*
void UniformVariatedBallTarget::Deactivate()
{
	std::cout << "Deactivate" << std::endl;
	m_isActive = false;
}
*/
void UniformVariatedBallTarget::OnCollision()
{
	m_velocity->x *= -1;
	m_velocity->y *= -1;
}
