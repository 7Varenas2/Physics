#include "Test.h"
#include "Graphics.h"
#include "Input.h"
#include "Time.h"
#include "Random.h"
#include "World.h"
#include "CircleShape.h"

Test::Test()
{
	//
}

Test::~Test()
{
	if (m_world) delete m_world;
	if (m_graphics) delete m_graphics;
	if (m_input) delete m_input;
	if (m_time) delete m_time;
}

void Test::Initialize()
{
	m_graphics = new Graphics();
	m_graphics->CreateWindow("Physics", 800, 600);
	m_input = new Input();
	m_time = new Time();
	m_world = new World();

}

void Test::Run()
{
	Update();
	m_fixedTime += m_time->TimeDelta();
	FixedUpdate();

	// Render
	PreRender();
	Render();
	PostRender();

	m_graphics->DrawCircle(m_input->GetMousePosition(), 30, { randomf(), randomf(), randomf(), 1 });

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
