#pragma once
#include "..\Engine\Time.h"
#include "..\Engine\Graphics.h"
#include "..\Engine\Random.h"
#include "..\Tests\Test.h"
#include "..\Physics\Joint.h"
#include "..\Engine\Input.h"

class JointTest : public Test
{
public:
	virtual void Initialize() override;

	 virtual void Render() override;
	 virtual void FixedUpdate() override;
	 virtual void Update() override;

private:
	class Body* m_anchor{ 0 };
};