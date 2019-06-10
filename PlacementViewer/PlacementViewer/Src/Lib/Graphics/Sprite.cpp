#include "Sprite.h"
#include "../File/Texture/TextureManager.h"

Sprite::Sprite(std::string name, std::string texture_key_word, float x, float y, Size sprite_size) :
	m_Name(name),
	m_TextureKeyWord(texture_key_word),
	m_Size(sprite_size)
{
	Lib::TextureBase* texture = Lib::TextureManager::Instance()->Find(m_TextureKeyWord);
	if (texture != nullptr)
	{
		Size texture_size = texture->GetSize();
		m_NormalizePosX = x / texture_size.Width;
		m_NormalizePosY = y / texture_size.Height;
		m_NormalizeSize = Size(sprite_size.Width / texture_size.Width, sprite_size.Height / texture_size.Height);
	}
	else
	{
		m_NormalizePosX = 0.0f;
		m_NormalizePosY = 0.0f;
		m_NormalizeSize = Size(1.0f, 1.0f);
	}
}

void Sprite::ReflectOnVertex(Lib::CustomVertex2D vertex_list[4])
{
	float tu_tv_list[4][2] =
	{
		{ m_NormalizePosX, m_NormalizePosY },
		{ m_NormalizePosX + m_NormalizeSize.Width, m_NormalizePosY },
		{ m_NormalizePosX + m_NormalizeSize.Width, m_NormalizePosX + m_NormalizeSize.Height },
		{ m_NormalizePosX, m_NormalizePosX + m_NormalizeSize.Height },
	};

	float pos_list[4][2] = 
	{
		{ 0.0f, 0.0f },
		{ m_Size.Width, 0.0f },
		{ m_Size.Width, m_Size.Height },
		{ 0.0f, m_Size.Height }
	};

	for (int i = 0; i < 4; i++)
	{
		vertex_list[i].X += pos_list[i][0];
		vertex_list[i].Y += pos_list[i][1];

		vertex_list[i].Tu = tu_tv_list[i][0];
		vertex_list[i].Tv = tu_tv_list[i][1];
	}
}
