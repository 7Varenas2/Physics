#include "World.h"

World::~World()
{
	// Delete all the objects
	// Clear the objects from the list clear()
	for (auto& i : m_objects)
	{
		delete i;
	}
	m_objects.clear();
	
}

void World::Step(float dt)
{
	// Call step() on all the objects
	for (auto& i : m_objects)
	{
		i->Step(dt);
	}
}

void World::Draw(Graphics* graphics)
{
	// Call Draw() on all objects
	for (auto& i : m_objects)
	{
		i->Draw(graphics);
	}
}

void World::AddPhysicsObject(PhysicsObject* po)
{
	// Push back the po onto the objects list
	m_objects.push_back(po);
}

void World::RemovePhysicsObject(PhysicsObject* po)
{
	// Remove po from the objects list
	m_objects.remove(po);
}
