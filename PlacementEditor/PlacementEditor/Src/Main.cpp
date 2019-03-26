#include <Windows.h>
#include <crtdbg.h>
#include "Lib/Lib.h"
#include "Lib/Graphics/Graphics.h"
#include "Utility/Size.h"
#include "Lib/File/Texture/TextureManager.h"
#include "Lib/Graphics/SpriteManager.h"

//#include "DirectX.h"

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmpLine,
	INT       nCmdShow)
{
	// メモリリーク検出
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Size size01;
	Size size02(100, 200);
	Size size03(size02);

	if (Lib::Initialize("オブジェクト配置画面", 1280, 720) == false)
	{
		return 0;
	}

	if (Lib::TextureManager::Instance()->Load("Character", "Res/Texture/Character.png") == false)
	{
		return 0;
	}

	SpriteManager::Instance()->Entry("Character", "Character", 0.0f, 0.0f, Size(128.0f, 128.0f));

	while (true)
	{
		MSG msg;

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				break;
			}
			else 
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else 
		{
			Lib::Graphics::Instance()->StartRendering();

			Lib::Graphics::Instance()->Draw("Character", "Character", 0.0f, 0.0f, 0.0f);

			Lib::Graphics::Instance()->FinishRendering();
		}
	}

	Lib::Exit();

	return 0;
}
