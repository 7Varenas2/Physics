#include "Body.h"

void Body::ApplyForce(const glm::vec2& force)
{
	this->force += force;
}

void Body::Step(float dt)
{
	glm::vec2 acceleration = (force * invMass);
	velocity += (force / invMass) * dt;
	position += velocity * dt;

	velocity = velocity * 1.0f / (1.0f + (3.0f * dt));
	
}

