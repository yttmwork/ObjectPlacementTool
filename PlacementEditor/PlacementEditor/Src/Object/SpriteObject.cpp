#include "SpriteObject.h"
#include "../Lib/Graphics/Graphics.h"
#include "CreateParameter/SpriteObjectCreateParameter.h"

SpriteObject::SpriteObject(SpriteObjectCreateParameter& parameter) :
		Object(	parameter.PosX, 
				parameter.PosY, 
				parameter.PosZ, 
				parameter.Degree, 
				parameter.ScaleX, 
				parameter.ScaleY),
		m_SpriteName(parameter.SpriteName)
{
}

void SpriteObject::Update()
{
}

void SpriteObject::Draw()
{
	Lib::Graphics::Instance()->Draw("Character", "Character", m_PosX, m_PosY, m_PosZ, m_Degree);
}

