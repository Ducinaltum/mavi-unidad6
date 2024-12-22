#include "UniformBallTarget.h"
#include <iostream>

UniformBallTarget::UniformBallTarget(Vector2u winSize) : PhysicsTarget(winSize, "assets/rcircle.png")
{
	
}

void UniformBallTarget::Update(float dt)
{
	PhysicsTarget::Update(dt);
	Vector2f targetPos = m_sprite.getPosition();
	targetPos.x += m_velocity->x * dt;
	targetPos.y += m_velocity->y * dt;
	m_sprite.setPosition(targetPos);
}


void UniformBallTarget::Activate()
{
	std::cout << "Activate" << std::endl;
	PhysicsTarget::Activate();
	float maxWinSize = m_winSize->x > m_winSize->y ? m_winSize->x : m_winSize->y;
	float halfWinSize = maxWinSize / 2;
	float spawnAngle = (rand() % (2 * 314)) / 100.0f;
	std::cout << (spawnAngle) << std::endl;
	float xPosSpawn = std::sin(spawnAngle);
	float yPosSpawn = std::cos(spawnAngle);
	Vector2f startPos(0, 0);
	float forceMagnitude = 200;
	m_velocity->x = -xPosSpawn * forceMagnitude;
	m_velocity->y = -yPosSpawn * forceMagnitude;
	startPos.x = (xPosSpawn * halfWinSize) + halfWinSize;
	startPos.y = (yPosSpawn * halfWinSize) + halfWinSize;
	std::cout << xPosSpawn << " " << yPosSpawn << std::endl;
	std::cout << startPos.x << " " << startPos.y << std::endl;
	m_sprite.setPosition(startPos);
}

void UniformBallTarget::OnCollision()
{
	m_velocity->x *= -1;
	m_velocity->y *= -1;
}
/*
void UniformBallTarget::Deactivate()
{
	std::cout << "Deactivate" << std::endl;
	m_isActive = false;
}
*/