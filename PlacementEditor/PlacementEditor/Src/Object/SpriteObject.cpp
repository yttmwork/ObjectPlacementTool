#include "SpriteObject.h"
#include "../Lib/Graphics/Graphics.h"

void SpriteObject::Update()
{
	m_Degree += 1.0f;
}

void SpriteObject::Draw()
{
	Lib::Graphics::Instance()->Draw("Character", "Character", m_PosX, m_PosY, m_PosZ, m_Degree);
}