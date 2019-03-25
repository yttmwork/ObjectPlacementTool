#include <Windows.h>
#include "GraphicsRelatedDefinitions.h"
#include "Graphics.h"
#include "GraphicsDeviceFactory.h"

namespace Lib
{
	bool Graphics::Initialize(unsigned int width, unsigned int height, bool is_window_mode, GraphicsDevice select_device, HWND window_handle)
	{
		m_SelectedDevice = select_device;

		if (m_Factory == nullptr)
		{
			m_Factory = new GraphicsDeviceFactory();
		}

		m_Device = m_Factory->CreateDevice(m_SelectedDevice);

		if (m_Device->Initialize(width, height, is_window_mode, window_handle) == false)
		{
			return false;
		}

		return true;
	}

	void Graphics::Release()
	{
		if (m_Factory != nullptr)
		{
			delete (m_Factory);
			m_Factory = nullptr;
		}

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
}
