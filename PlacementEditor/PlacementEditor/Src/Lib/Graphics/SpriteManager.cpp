#include"SpriteManager.h"

void SpriteManager::Entry(std::string sprite_name, std::string texture_key_word, float x, float y, Size size)
{
	m_SpriteList[texture_key_word][sprite_name] = new Sprite(sprite_name, texture_key_word, x, y, size);
}

void SpriteManager::Delete(std::string sprite_name, std::string texture_key_word)
{
	if (m_SpriteList.count(texture_key_word) == 0)
	{
		return;
	}

	Sprite* sprite = m_SpriteList[texture_key_word][sprite_name];
	delete (sprite);
	m_SpriteList[texture_key_word].erase(sprite_name);
}

void SpriteManager::AllDelete()
{
	for (auto entry_texture : m_SpriteList)
	{
		for (auto entry_sprite : entry_texture.second)
		{
			delete (entry_sprite.second);
		}
	}
	m_SpriteList.clear();
}

Sprite* SpriteManager::Find(std::string texture_key_word, std::string sprite_name)
{
	if (m_SpriteList.count(texture_key_word) == 0)
	{
		return nullptr;
	}

	if (m_SpriteList[texture_key_word].count(sprite_name) == 0)
	{
		return nullptr;
	}

	return m_SpriteList[texture_key_word][sprite_name];
}
