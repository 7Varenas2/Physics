#pragma once
#include "..\Physics\ForceGenerator.h"

class GravitationalField :  public ForceGenerator
{
public:
	void GravitationalGenerator(float strength) : m_strength{ strength } {}
	void Apply(std::vector<class Body*);

private:
	float m_strength{ 0 };

};