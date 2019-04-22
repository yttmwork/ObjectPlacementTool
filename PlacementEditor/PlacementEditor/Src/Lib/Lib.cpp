#include <string>
#include "Lib.h"
#include "Window.h"
#include "File/Texture/TextureManager.h"
#include "Graphics/Graphics.h"
#include "Input/Input.h"

namespace Lib
{
	bool Initialize(std::string title, unsigned int width, unsigned int height)
	{
		if (Window::Instance()->Create(title.c_str(), width, height) == false)
		{
			return false;
		}

		if (Graphics::Instance()->Initialize(width, height) == false)
		{
			return false;
		}

		if (Input::Instance()->Initialize() == false)
		{
			return false;
		}

		return true;
	}

	void Exit()
	{
		TextureManager::Instance()->AllRelease();
		Graphics::Instance()->Release();
		Input::Instance()->Release();
	}
}
