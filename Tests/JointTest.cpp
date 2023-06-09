#include "..\Tests\JointTest.h"
#include "..\Engine\Body.h"
#include "..\Physics\CircleShape.h"

#define SPRING_STIFFNESS 200
#define SPRING_LENGTH 50
#define BODY_DAMPING 10
#define CHAIN_SIZE 6

void JointTest::Initialize()
{
	Test::Initialize();

	m_anchor = new Body(new CircleShape(1, { 1, 1, 1, 1 }), { 0, 0 }, { 0, 0 }, 0, Body::KINEMATIC); // was 400 100
	m_world->AddBody(m_anchor);

	auto prevBody = m_anchor;

	auto body = new Body(new CircleShape(0.5, { 1, 1, 1, 1 }), { 0, 0 }, { 0, 0 }, 1, Body::DYNAMIC);
	body->gravityScale = 250;
	body->damping = BODY_DAMPING;
	m_world->AddBody(body);

	auto joint = new Joint(prevBody, body, SPRING_STIFFNESS, SPRING_LENGTH);
	m_world->AddJoint(joint);

	// SECOND BODY
	prevBody = body;

	body = new Body(new CircleShape(20, { 1, 1, 1, 1 }),  { 0, 0 });
	body->gravityScale = 250;
	body->damping = BODY_DAMPING;
	m_world->AddBody(body);

	joint = new Joint(body, prevBody, SPRING_STIFFNESS, SPRING_LENGTH);
	m_world->AddJoint(joint);
}

void JointTest::Update()
{
	Test::Update();
	m_anchor->position = m_input->GetMousePosition();
}

void JointTest::FixedUpdate()
{
	m_world->Step(m_time->GetFixedDeltaTime());
}

void JointTest::Render()
{
	m_world->Draw(m_graphics);
	m_graphics->DrawCircle(m_input->GetMousePosition(), 10, { randomf(), randomf(), randomf(), 1 });
}
