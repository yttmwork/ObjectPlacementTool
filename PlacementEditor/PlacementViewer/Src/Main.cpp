#include <windowsx.h>
#include "Socket/ServerSocket.h"
#include <Windows.h>
#include <crtdbg.h>
#include "Utility/Size.h"
#include "Lib/Lib.h"
#include "Lib/Graphics/Graphics.h"
#include "Lib/File/Texture/TextureManager.h"
#include "Lib/Graphics/SpriteManager.h"
#include "Object/SpriteObject.h"
#include "Object/CreateParameter/CreateParameterBase.h"
#include "Object/CreateParameter/SpriteObjectCreateParameter.h"
#include "Object/CreateParameter/PlacementObjectCreateParameter.h"
#include "Object/ObjectFactory.h"
#include "Object//ObjectManager.h"
#include "Lib/Input/Input.h"
#include "Collision/CollisionManager.h"
#include "Object/MouseObject.h"
#include "Editor/Editor.h"

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmpLine,
	INT       nCmdShow)
{
	// メモリリーク検出
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	if (Lib::Initialize("オブジェクト配置画面", 1280, 720) == false)
	{
		return 0;
	}

	ServerSocket::Instance()->Start(2000);

	std::map<std::string, std::string> file_name_list =
	{
		{ "Object01", "Res/Texture/Object01.png" },
		{ "Object02", "Res/Texture/Object02.png" },
		{ "Object03", "Res/Texture/Object03.png" },
		{ "Object04", "Res/Texture/Object04.png" },
		{ "Object05", "Res/Texture/Object05.png" },
	};

	for (auto itr = file_name_list.begin(); itr != file_name_list.end(); itr++)
	{
		if (Lib::TextureManager::Instance()->Load(itr->first, itr->second) == false)
		{
			return 0;
		}
	}

	SpriteManager::Instance()->Entry("Object01", "Object01", 0.0f, 0.0f, Size(128.0f, 128.0f));
	SpriteManager::Instance()->Entry("Object02", "Object02", 0.0f, 0.0f, Size(128.0f, 128.0f));
	SpriteManager::Instance()->Entry("Object03", "Object03", 0.0f, 0.0f, Size(128.0f, 128.0f));
	SpriteManager::Instance()->Entry("Object04", "Object04", 0.0f, 0.0f, Size(128.0f, 128.0f));
	SpriteManager::Instance()->Entry("Object05", "Object05", 0.0f, 0.0f, Size(128.0f, 128.0f));

	CollisionObjectCreateParameter parameter(
		Collision::CollisionGroup::Mouse,
		"",
		0.0f,
		0.0f);
	ObjectFactory::CreateMouse(parameter);

	Editor::Instance()->Initialize("Object01");

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
			Lib::Input::Instance()->Update();
		
			Collision::CollisionManager::Instance()->Clear();

			ObjectManager::Instance()->Update();

			Collision::CollisionManager::Instance()->Update();

			Lib::Graphics::Instance()->StartRendering();

			ObjectManager::Instance()->Draw();

			Lib::Graphics::Instance()->FinishRendering();

			ObjectManager::Instance()->Delete();

			ObjectManager::Instance()->Register();
		}
	}

	ServerSocket::Instance()->CleanUp();
	Lib::Exit();

	return 0;
}
