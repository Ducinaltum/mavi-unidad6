#include <SFML/Window.hpp> 
#include <SFML/Graphics.hpp> 
using namespace sf;
#pragma once
class PhysicsTarget
{
protected:
	const float m_gravity = 9.8f;
	float m_radious;
	bool m_isActive;
	Vector2f* m_velocity;
	Sprite m_sprite;
	Vector2f * m_winSize;
public:
	PhysicsTarget(Vector2u winSize, std::string path);
	virtual void ProcessCollisions(PhysicsTarget* m_targetSprite);
	virtual void Update(float dt);
	Sprite* GetSprite();
	virtual void Activate();
	bool IsActive();
	virtual void Deactivate();
	virtual void OnCollision();
	int GetRadious();
};

