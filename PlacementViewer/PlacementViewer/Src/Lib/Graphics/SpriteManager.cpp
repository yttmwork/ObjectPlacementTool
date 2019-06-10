#include"SpriteManager.h"

void SpriteManager::Entry(std::string sprite_name, std::string texture_key_word, float x, float y, Size size)
{
	m_SpriteList[sprite_name] = new Sprite(sprite_name, texture_key_word, x, y, size);
}

void SpriteManager::Delete(std::string sprite_name)
{
	if (m_SpriteList.count(sprite_name) == 0)
	{
		return;
	}

	Sprite* sprite = m_SpriteList[sprite_name];
	delete (sprite);
	m_SpriteList.erase(sprite_name);
}

void SpriteManager::AllDelete()
{
	for (auto entry_sprite : m_SpriteList)
	{
		delete (entry_sprite.second);
	}
	m_SpriteList.clear();
}

Sprite* SpriteManager::Find(std::string sprite_name)
{
	if (m_SpriteList.count(sprite_name) == 0)
	{
		return nullptr;
	}

	return m_SpriteList[sprite_name];
}
