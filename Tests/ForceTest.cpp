#include "..\Tests\ForceTest.h"
#include "..\Engine\Graphics.h"
#include "..\Engine\Input.h"
#include "..\Engine\Time.h"
#include "..\Engine\Random.h"
#include "..\Physics\CircleShape.h"
#include "..\Engine\Body.h"
#include "..\Physics\GravitationalForce.h"

void ForceTest::Initialize()
{
	Test::Initialize();
	auto forceGenerator = new GravitationalForce(400);
	m_world->AddForceGenerator(forceGenerator);
	//World::gravity = { 4.0f, 9.8f };
}

void ForceTest::FixedUpdate()
{
	m_world->Step(m_time->GetFixedDeltaTime());

}

void ForceTest::Render()
{
	m_graphics->DrawCircle(m_input->GetMousePosition(), 30, { randomf(), randomf(), randomf(), 1 });
	m_world->Draw(m_graphics);
}

void ForceTest::Update()
{
	Test::Update();

	if (m_input->GetMouseButton(0))
	{
		glm::vec2 velocity{ 0,0 };

		float size = randomf(1, 8);
		
		velocity = randomUnitCircle() * randomf(100, 200);
		auto body = new Body(new CircleShape(random(5, 30), { randomf(1),randomf(1),randomf(1),1 }), m_input->GetMousePosition(), velocity);
		body->damping = 1;
		body->gravityScale = 30;

		m_world->AddBody(body);

	}
}