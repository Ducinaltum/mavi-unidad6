#pragma once
#include "Game.h"
class Bounce :
    public Game
{
private:
	float m_acceleration;
	float m_maxSpeed;
	float m_friction;
	float m_gravity;
	Vector2f* m_velocity;
	Sprite m_ballSprite;

public:
	Bounce(RenderWindow* rw);
	void ProcessCollisions() override;
	void UpdateGame(float dt) override;
	void DrawGame() override;
};

