#pragma once
#include "PhysicsTarget.h"
class UniformVariatedBallTarget :
    public PhysicsTarget
{
private: 
	float m_acceleration;
	float m_friction;
public:
	UniformVariatedBallTarget(Vector2u winSize);
	void ProcessCollisions(PhysicsTarget* m_targetSprite) override;
	void Update(float dt) override;
	void Activate() override;
	//void Deactivate() override;
	void OnCollision() override;
};

