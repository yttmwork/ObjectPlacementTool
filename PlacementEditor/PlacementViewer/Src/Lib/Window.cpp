#include <windowsx.h>
#include "../Socket/ServerSocket.h"
#include "../Socket/SocketRelatedDefinitions.h"
#include <Windows.h>
#include "Window.h"

namespace Lib
{
	LRESULT CALLBACK Window::WindowProc(HWND window_handle, UINT message_id, WPARAM wparam, LPARAM lparam)
	{
		switch (message_id)
		{
		case WM_CLOSE:
			PostQuitMessage(0);
			break;
			// 非同期通信イベント
		case WmAsync:
			switch (WSAGETSELECTEVENT(lparam))
			{
				// 通信許可
			case FD_ACCEPT:
				if (ServerSocket::Instance()->Accept() == false)
				{
					ServerSocket::Instance()->CleanUp();
				}
				break;
				// 受信
			case FD_READ:
				if (ServerSocket::Instance()->Receive(wparam) == true)
				{
					
				}
				break;
				// 終了
			case FD_CLOSE:
				ServerSocket::Instance()->CleanUp();
				break;
			default:
				return FALSE;
				break;
			}
			break;
		default:
			return DefWindowProc(window_handle, message_id, wparam, lparam);
			break;
		}

		return 0;
	}

	bool Window::Create(std::string title, unsigned int width, unsigned int height)
	{
		WNDCLASSEX window_class = {
			sizeof(WNDCLASSEX),									// 構造体のサイズ
			CS_HREDRAW | CS_VREDRAW,							// クラスのスタイル
			WindowProc,											// ウィンドウプロシージャ
			0,													// 補助メモリ
			0,													// 補助メモリ
			GetModuleHandle(nullptr),							// このプログラムのインスタンスハンドル
			LoadIcon(NULL, MAKEINTRESOURCE(IDI_APPLICATION)),	// アイコン画像
			LoadCursor(NULL, IDC_ARROW),						// カーソル画像
			nullptr,											// 背景ブラシ(背景色)
			nullptr,											// メニュー名
			Lib::WindowClassName.c_str(),						// クラス名									
			nullptr												// 小さいアイコン
		};

		// 構造体の登録
		if (RegisterClassEx(&window_class) == 0)
		{
			return false;
		}

		// ウィンドウ作成
		HWND window_handle = CreateWindow(
				Lib::WindowClassName.c_str(),
				title.c_str(),
				(WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME) | WS_VISIBLE,
				CW_USEDEFAULT,
				0,
				width,
				height,
				nullptr,
				nullptr,
				GetModuleHandle(nullptr),
				nullptr);

		if (window_handle == nullptr)
		{
			return false;
		}

		RECT window_rect;
		RECT client_rect;

		GetWindowRect(window_handle, &window_rect);
		GetClientRect(window_handle, &client_rect);

		int frame_size_x = (window_rect.right - window_rect.left) - (client_rect.right - client_rect.left);
		int frame_size_y = (window_rect.bottom - window_rect.top) - (client_rect.bottom - client_rect.top);

		SetWindowPos(window_handle, nullptr, CW_USEDEFAULT, 0, frame_size_x + width, frame_size_y + height, SWP_NOMOVE);

		ShowWindow(window_handle, SW_SHOW);
		UpdateWindow(window_handle);

		return true;
	}
}
