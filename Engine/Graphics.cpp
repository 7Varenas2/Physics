#include "..\Engine\Graphics.h"
#include "..\Engine\Primitives.h"
#include <SDL.h>

Graphics::Graphics()
{
	// Initialize SDL
	SDL_Init(SDL_INIT_VIDEO);
}

Graphics::~Graphics()
{
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void Graphics::CreateWindow(const char* title, int width, int height, float size)
{
	m_width = width;
	m_height = height;
	float ratio = m_width / (float)m_height;
	m_extents = glm::vec2{ size * ratio, size };

	m_window = SDL_CreateWindow(title,
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		width, height,
		SDL_WINDOW_SHOWN);

	m_renderer = SDL_CreateRenderer(m_window, -1, 0);
}

void Graphics::Clear()
{
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 0);
	SDL_RenderClear(m_renderer);
}

void Graphics::Present()
{
	SDL_RenderPresent(m_renderer);
}


void Graphics::DrawPoint(const glm::ivec2& point, const glm::vec4& color)
{
	ConvertColor(color);
	SDL_RenderDrawPoint(m_renderer, point.x, point.y);
}

void Graphics::DrawLine(const glm::ivec2& start, const glm::ivec2& end, const glm::vec4& color)
{
	ConvertColor(color);
	SDL_RenderDrawLine(m_renderer, start.x, start.y, end.x, end.y);
}

void Graphics::DrawCircle(const glm::ivec2& point, int radius, const glm::vec4& color)
{
	glm::ivec4 iColor = ConvertColor(color);
	circleRGBA(m_renderer, point.x, point.y, radius, iColor.r, iColor.g, iColor.b, iColor.a);
}

void Graphics::DrawFilledCircle(const glm::ivec2& point, int radius, const glm::vec4& color)
{
	glm::ivec4 iColor = ConvertColor(color);
	filledCircleRGBA(m_renderer, point.x, point.y, radius, iColor.r, iColor.g, iColor.b, iColor.a);
}

glm::ivec4 Graphics::ConvertColor(const glm::vec4& color)
{
	glm::ivec4 iColor;
	iColor.r = (int)(color.r * 255);
	iColor.g = (int)(color.g * 255);
	iColor.b = (int)(color.b * 255);
	iColor.a = (int)(color.a * 255);

	return iColor;
}

glm::vec2 Graphics::ScreenToWorld(const glm::ivec2& screen)
{
	float x = screen.x / (float)m_width; // screen x (0 - 800) -> x (0 - 1)
	float y = (m_height - screen.y) / (float)m_height; // screen y (0 - 600) -> (0 - 1) flip

	glm::vec2 world;
	world.x = ((1 - x) * -m_extents.x) + (x * m_extents.x);
	world.y = ((1 - y) * -m_extents.y) + (y * m_extents.y);

	return world;
}

glm::ivec2 Graphics::WorldToScreen(const glm::vec2& world)
{
	float x = (world.x + m_extents.x) / (m_extents.x * 2); // world.x = 0 -> (0 + 6.66) / 13.33 -> 0.5
	float y = (world.y + m_extents.y) / (m_extents.y * 2); // world.y = 0 -> (0 + 5) / 10 = 0.5

	glm::vec2 screen;
	screen.x = x * m_width;
	screen.y = (1.0f - y) * m_height;

	return screen;
}

int Graphics::WorldToPixels(float world)
{
	return (int)(world * (m_height / (m_extents.y * 2)));
}
