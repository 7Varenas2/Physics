#include "Body.h"
#include "Integrator.h"
#include "World.h"
#include "Shape.h"

void Body::ApplyForce(const glm::vec2& force)
{
	this->force += force;
}

void Body::Step(float dt)
{
	//glm::vec2 acceleration = (force * invMass);
	//velocity += (force / invMass) * dt;
	//position += velocity * dt;

	if (type != DYNAMIC) return;

	// Gravity 
	ApplyForce(World::gravity * gravityScale * mass);
	// Damping
	velocity = velocity * 1.0f / (1.0f + (3.0f * dt));
	Integrator::ExplicitEuler(*this, dt);
	ClearForce();

}

void Body::Draw(Graphics* graphics)
{
	shape->Draw(graphics, position);
}

