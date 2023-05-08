#include "ParticleTest.h"
#include "Graphics.h"
#include "Input.h"
#include "Time.h"
#include "Random.h"
#include "CircleShape.h"
#include "Body.h"

void ParticleTest::Initialize()
{
	Test::Initialize();
}

void ParticleTest::FixedUpdate()
{
	m_world->Step(m_time->TimeDelta());

}

void ParticleTest::Render()
{
	m_graphics->DrawCircle(m_input->GetMousePosition(), 30, { randomf(), randomf(), randomf(), 1 });
	m_world->Draw(m_graphics);
}

void ParticleTest::Update()
{
	Test::Update();

	if (m_input->GetMouseButton(0))
	{
		glm::vec2 velocity = randomUnitCircle() * randomf(10, 100);
		auto po = new PhysicsObject(new Body(m_input->GetMousePosition(), velocity, 3), new CircleShape(random(5, 30), { randomf(1),randomf(1),randomf(1),1 }));
		m_world->AddPhysicsObject(po);

	}
}
