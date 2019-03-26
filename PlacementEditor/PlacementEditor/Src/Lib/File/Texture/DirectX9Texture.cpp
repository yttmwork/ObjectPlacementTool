#include "DirectX9Texture.h"
#include "../../Graphics/Graphics.h"
#include "../../Graphics/DirectX9Graphics.h"

namespace Lib
{
	void DirectX9Texture::Release()
	{
		if (m_Texture != nullptr)
		{
			m_Texture->Release();
			m_Texture = nullptr;
		}
		m_Device = nullptr;
	}

	void DirectX9Texture::SetToGraphicsDevice(DWORD stage_id)
	{
		m_Device->SetTexture(stage_id, m_Texture);
	}
}
