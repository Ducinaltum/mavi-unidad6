#pragma once
#include "Game.h"
class Space :
    public Game
{
private:

	float m_acceleration;
	float m_maxSpeed;
	float m_friction;
	Vector2f * m_velocity;
	Vector2f * m_input;
	Sprite m_ballSprite;
public:
	Space(RenderWindow* rw);
	void ProcessEvent(Event& evt) override;
	void ProcessCollisions() override;
	void UpdateGame(float dt) override;
	void DrawGame() override;
};

