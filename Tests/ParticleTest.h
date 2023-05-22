#pragma once
#include "..\Tests\Test.h"

class ParticleTest : public Test
{
public:
	void Initialize() override;
	

	virtual void FixedUpdate() override;
	virtual void Render() override;
	void Update() override;

protected:
};