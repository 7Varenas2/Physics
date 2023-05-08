#pragma once
#include "PhysicsObject.h"
#include <list>

// Act as container for PhysicsObjects. PhysicsObject can be added and removed from the world
class World
{
public:
	~World();

	void Step(float dt);
	void Draw(class Graphics* graphics);

	void AddPhysicsObject(PhysicsObject* po);
	void RemovePhysicsObject(PhysicsObject* po);
	
private:
	std::list<PhysicsObject*> m_objects;
};
