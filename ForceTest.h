#pragma once
#include "Test.h"

class ForceTest : public Test
{
public:
	void Initialize() override;


	virtual void FixedUpdate() override;
	virtual void Render() override;
	void Update() override;

protected:
};