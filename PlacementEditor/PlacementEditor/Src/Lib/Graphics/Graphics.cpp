#include <Windows.h>
#include <string>
#include "GraphicsRelatedDefinitions.h"
#include "Graphics.h"
#include "DirectX9DeviceFactory.h"

namespace Lib
{
	bool Graphics::Initialize(unsigned int width, unsigned int height, bool is_window_mode, HWND window_handle)
	{
#if GRAPHICS_DEVICE_TYPE == GRAPHICS_DEVICE_TYPE_DIRECTX9
		DirectX9DeviceFactory factory;
#endif

		m_Device = factory.CreateDevice();

		if (m_Device->Initialize(width, height, is_window_mode, window_handle) == false)
		{
			return false;
		}

		return true;
	}

	void Graphics::Release()
	{
		if (m_Device != nullptr)
		{
			delete (m_Device);
			m_Device = nullptr;
		}
	}

	void Graphics::StartRendering()
	{
		m_Device->StartRendering();
	}

	void Graphics::FinishRendering()
	{
		m_Device->FinishRendering();
	}

	void Graphics::Draw(float pos_x, float pos_y, float pos_z, float width, float height, float degree)
	{
		m_Device->Draw(pos_x, pos_y, pos_z, width, height, degree);
	}

	void Graphics::Draw(std::string texture_key_word, std::string sprite_name, float pos_x, float pos_y, float pos_z, float degree)
	{
		m_Device->Draw(texture_key_word, sprite_name, pos_x, pos_y, pos_z, degree);
	}

	TextureBase* Graphics::LoadTexture(std::string file_name)
	{
		return m_Device->LoadTexture(file_name);
	}

}
