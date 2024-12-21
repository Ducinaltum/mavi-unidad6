#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Game.h"
using namespace sf;
#pragma once

class FastAndFurious : public Game
{
private:
	float m_startSpeed;
	float m_currentSpeed;
	float m_endSpeed;
	float m_incrementStep;
	Sprite m_ballSprite;

public:
	FastAndFurious(RenderWindow* rw);
	void UpdateGame(float dt) override;
	void DrawGame() override;
};

