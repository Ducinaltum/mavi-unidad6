#pragma once
#include <vector>
#include "Game.h"
#include "PhysicsTarget.h"

class WildPhysics :
    public Game
{
private:
	float m_timeBetweenShots;
	float m_timeBetweenTargets;
	float m_eTime;
	float m_crosshairSize;
	int m_maxObjectsInScene;
	Sprite m_crosshairSprite;
	std::vector<PhysicsTarget*> m_targetSprites;
	PhysicsTarget * m_croshairTarget;
	bool m_hasShot;

	PhysicsTarget* CheckNumberOfActiveObjectsAndPickTarget();

public:
	WildPhysics(RenderWindow* rw);
	void ProcessEvent(Event& evt) override;
	void ProcessCollisions() override;
	void UpdateGame(float dt) override;
	void DrawGame() override;
	
};
