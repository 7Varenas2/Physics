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

void ParticleTest::Run()
{
	UpdateEvents();

	m_input->Update();
	m_time->Update();

	if (m_input->GetMouseButton(0))
	{
		glm::vec2 velocity = randomUnitCircle() * randomf(10,100);
		auto po = new PhysicsObject(new Body(m_input -> GetMousePosition(), velocity), new CircleShape(random(5,30), { randomf(1),randomf(1),randomf(1),1}));
		m_world->AddPhysicsObject(po);

	}
	m_world->Step(m_time->TimeDelta());
	

	m_graphics->ConvertColor({ 1, 1, 1,0});
	m_graphics->Clear();

	m_graphics->DrawCircle(m_input->GetMousePosition(), 30, { randomf(), randomf(), randomf(), 1 });
	m_world->Draw(m_graphics);

	m_graphics->Present();
}
