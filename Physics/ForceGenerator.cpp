#include "..\Physics\ForceGenerator.h"


void ForceGenerator::Draw(Graphics* graphics)
{
	if (m_body) m_body->Draw(graphics);
}
