#include "GraphicsDeviceFactory.h"
#include "DirectGraphics9.h"

namespace Lib
{
	GraphicsDeviceBase* GraphicsDeviceFactory::CreateDevice(GraphicsDevice graphics_device)
	{
		switch (graphics_device)
		{
		case GraphicsDevice::DirectX9:
			return new DirectGraphics9();
			break;
		}

		return nullptr;
	}
}
