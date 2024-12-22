#pragma once
#include "PhysicsTarget.h"
class UniformBallTarget :
    public PhysicsTarget
{

public:
	UniformBallTarget(Vector2u winSize);
	void Update(float dt) override;
	void Activate() override;
	//void Deactivate() override;
	void OnCollision() override;
};

