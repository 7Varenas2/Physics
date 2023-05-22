#include "..\Physics\PhysicsObject.h"

PhysicsObject::~PhysicsObject()
{
	// delete body and shape
	delete m_body;
	delete m_shape;
}

void PhysicsObject::Step(float dt)
{
	// Call step on the body

	m_body->Step(dt);
	
}

void PhysicsObject::Draw(Graphics* m_graphics)
{
	// Call draw on the shape (pass in the graphics and body position)
	m_shape->Draw(m_graphics, m_body->position);
}

