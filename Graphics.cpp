#include "Graphics.h"
#include "Primitives.h"
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

void Graphics::CreateWindow(const char* title, int x, int y)
{
	m_window = SDL_CreateWindow(title,
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		x, y,
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

//void Graphics::SetColor(const glm::vec4& color)
//{
//	glm::ivec4 iColor;
//	iColor.r = (int)(color.r * 255);
//	iColor.g = (int)(color.g * 255);
//	iColor.b = (int)(color.b * 255);
//	iColor.a = (int)(color.a * 255);
//	SDL_SetRenderDrawColor(m_renderer, iColor.r, iColor.g, iColor.b, iColor.a);
//}

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