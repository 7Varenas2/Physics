#include "..\Tests\Test.h"
#include "..\Engine\Graphics.h"
#include "..\Engine\Input.h"
#include "..\Engine\Time.h"
#include "..\Engine\Random.h"
#include "..\Engine\World.h"
#include "..\Physics\CircleShape.h"

Test::Test()
{
	//
}

Test::~Test()
{
	if (m_world) delete m_world;
	if (m_input) delete m_input;
	if (m_time) delete m_time;
	if (m_graphics) delete m_graphics;
}

void Test::Initialize()
{
	m_graphics = new Graphics();
	m_graphics->CreateWindow("Physics", 800, 600);
	m_input = new Input();
	m_time = new Time();
	m_time->SetFixedDeltaTime(1 / 60.0f);
	m_world = new World();

#if defined(POINT_FORCE)
	auto body = new Body(new CircleShape(200, { 1, 1, 1, 0.2f }), { 400, 300 }, { 0, 0 }, 0, Body::STATIC)
		;
	ForceGenerator* forceGenerator = new PointForce(body, 2000);
	m_world->AddForceGenerator(forceGenerator);
#elif defined(AREA_FORCE)
	auto body = new Body(new CircleShape(200, { 1, 1, 1, 0.2f }), { 400, 300 }, { 0, 0 }, 0, Body::STATIC)
		;
	ForceGenerator* forceGenerator = new AreaForce(body, 2000, -90);
	m_world->AddForceGenerator(forceGenerator);
#elif defined(DRAG_FORCE)
	auto body = new Body(new CircleShape(200, { 1, 1, 1, 0.2f }), { 400, 300 }, { 0, 0 }, 0, Body::STATIC)
		;
	ForceGenerator* forceGenerator = new DragForce(body, 0.5f);
	m_world->AddForceGenerator(forceGenerator);
#endif

}

void Test::Run()
{
	// Game loop
	Update();
	// Fixed time update
	m_fixedTime += m_time->TimeDelta();
	while (m_fixedTime >= m_time->GetFixedDeltaTime())
	{
		FixedUpdate();
		m_fixedTime -= m_time->GetFixedDeltaTime();
	}

	// Render
	PreRender();
	Render();
	PostRender();

	//m_graphics->DrawCircle(m_input->GetMousePosition(), 30, { randomf(), randomf(), randomf(), 1 });

}

void Test::Update()
{
	UpdateEvents();

	m_input->Update();
	m_time->Update();
}

void Test::PreRender()
{
	m_graphics->ConvertColor({ 1, 1, 1, 1 });
	m_graphics->Clear();
}


void Test::PostRender()
{
	m_graphics->Present();
}

void Test::UpdateEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			m_quit = true;
		}
		if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
		{
			m_quit = true;
		}
	}
}
