#include <Windows.h>
#include "Lib/Lib.h"
#include "Lib/Graphics/Graphics.h"
//#include "DirectX.h"

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmpLine,
	INT       nCmdShow)
{
	if (Lib::Initialize("オブジェクト配置画面", 1280, 720) == false)
	{
		return 0;
	}

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

			Lib::Graphics::Instance()->FinishRendering();
		}
	}

	Lib::Exit();

	return 0;
}
