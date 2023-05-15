#include "World.h"
#include "Body.h"
#include "ForceGenerator.h" 

glm::vec2 World::gravity{ 0,9.8 };

World::~World()
{
	// Delete all the objects
	// Clear the objects from the list clear()
	for (auto body : m_bodies)
	{
		delete body;
	}
	m_bodies.clear();

}

void World::Step(float dt)
{
	if (!m_bodies.empty() && !m_forceGenerators.empty())
	{
		std::vector<Body*> bodies(m_bodies.begin(), m_bodies.end());
		for (auto forceGenerator : m_forceGenerators)
		{
			forceGenerator->Apply(bodies);
		}
	}
	// Call step() on all the objects
	for (auto body : m_bodies) body->Step(dt);

}

void World::Draw(Graphics* graphics)
{
	// Call Draw() on all objects
	for (auto body : m_bodies)
	{
		body->Draw(graphics);
	}
}

void World::AddBody(Body* body)
{
	// Push back the po onto the objects list
	m_bodies.push_back(body);
}

void World::RemoveBody(Body* body)
{
	// Remove po from the objects list
	m_bodies.remove(body);
}

void World::AddForceGenerator(ForceGenerator* forceGenerator)
{
	m_forceGenerators.push_back(forceGenerator);
}
