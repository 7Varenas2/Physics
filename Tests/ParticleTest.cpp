#include "..\Tests\ParticleTest.h"
#include "..\Engine\Graphics.h"
#include "..\Engine\Input.h"
#include "..\Engine\Time.h"
#include "..\Engine\Random.h"
#include "..\Physics\CircleShape.h"
#include "..\Engine\Body.h"

void ParticleTest::Initialize()
{
	Test::Initialize();
}

void ParticleTest::FixedUpdate()
{
	m_world->Step(m_time->GetFixedDeltaTime());

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
		auto body = new Body(new CircleShape(random(5, 30), { randomf(1),randomf(1),randomf(1),1 }), m_input->GetMousePosition(), velocity);
		body->damping = 1;
		m_world->AddBody(body);

	}
}
