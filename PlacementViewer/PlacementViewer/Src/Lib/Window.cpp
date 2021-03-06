﻿#include <windowsx.h>
#include "../Socket/ClientSocket.h"
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
				// 受信
			case FD_READ:
				if (ClientSocket::Instance()->Receive(wparam) == false)
				{
					
				}
				break;
				// 終了
			case FD_CLOSE:
				ClientSocket::Instance()->CleanUp();
				break;
			default:
				return FALSE;
				break;
			}
			break;
			// サーバーの名前取得
		case WmServerByName:
			if (ClientSocket::Instance()->Connect() == false)
			{
				MessageBox(NULL, TEXT("接続に失敗しました。"), TEXT("接続エラー"), MB_OK);
			}
			break;
		//	// サーバーのアドレス取得
		//case WmServerByAddress:
		//	if (WSAGETASYNCERROR(lparam) == 0)
		//	{
		//		if (ClientSocket::Instance()->Connect() == FALSE)
		//		{
		//			MessageBox(NULL, TEXT("接続に失敗しました。"), TEXT("接続エラー"), MB_OK);
		//		}
		//	}
		//	else 
		//	{
		//		int async_error = WSAGETASYNCERROR(lparam);
		//		int error = WSAGetLastError();
		//		MessageBox(NULL, TEXT("ホストの取得に失敗しました。"), TEXT("ホスト情報取得エラー"), MB_OK);
		//	}
		//	break;
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
