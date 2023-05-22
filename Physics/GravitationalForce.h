#pragma once
#include "..\Physics\ForceGenerator.h"

class GravitationalForce :  public ForceGenerator
{
public:
	GravitationalForce(float strength) : m_strength{ strength } {}
	virtual void Apply(std::vector<class Body*> body) override;

private:
	float m_strength{ 0 };

};