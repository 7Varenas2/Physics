#include "..\Engine\Body.h"
#include "..\Engine\Integrator.h"
#include "..\Engine\World.h"
#include "..\Engine\Shape.h"
#include "..\Physics\CircleShape.h"
#include "..\Physics\Collision\Contact.h"

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

bool Body::Intersects(Body* body)
{
	glm::vec2 direction = body->position - position;
	float distance = glm::length(direction);
	float radius = dynamic_cast<CircleShape*>(shape)->radius + dynamic_cast<CircleShape*>(body->shape)->radius;


	return distance <= radius;
}

