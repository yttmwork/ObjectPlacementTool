#include "../../Graphics/Graphics.h"
#include "TextureManager.h"

namespace Lib
{
	bool TextureManager::Load(std::string key_word, std::string file_name)
	{
		if (m_TextureList.count(key_word) > 0)
		{
			return true;
		}

		TextureBase* texture = Graphics::Instance()->LoadTexture(file_name);
		if (texture == nullptr)
		{
			return false;
		}
		m_TextureList[key_word] = texture;

		return true;
	}

	void TextureManager::Release(std::string key_word)
	{
		if (m_TextureList.count(key_word) == 0)
		{
			return;
		}

		m_TextureList[key_word]->DecCount();
		if (m_TextureList[key_word]->CanRelease() == true)
		{
			TextureBase *data = m_TextureList[key_word];
			m_TextureList.erase(key_word);
			delete(data);
		}
	}

	void TextureManager::AllRelease()
	{
		for (auto itr = m_TextureList.begin(); itr != m_TextureList.end(); itr++)
		{
			TextureBase* texture = m_TextureList[itr->first];
			texture->Release();
			delete (texture);
		}
		m_TextureList.clear();
	}

	TextureBase* TextureManager::Find(std::string key_word)
	{
		if (m_TextureList.count(key_word) == 0)
		{
			return nullptr;
		}

		return m_TextureList[key_word];
	}
}
