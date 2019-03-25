#include "DirectGraphics9.h"
#include "../Window.h"

namespace Lib
{
	bool DirectGraphics9::Initialize(unsigned int width, unsigned int height, bool is_window_mode, HWND window_handle)
	{
		if (window_handle == nullptr)
		{
			window_handle = FindWindow(Lib::WindowClassName.c_str(), nullptr);
		}

		// Interface作成
		if (CreateInterface() == false)
		{
			return false;
		}

		// プレゼントパラメータの設定
		SetUpPasentParameter(width, height, is_window_mode, window_handle);

		// Device作成
		if (CreateDevice(window_handle) == false)
		{
			return false;
		}

		// ViewPortの設定
		if (SetUpViewPort() == false)
		{
			return false;
		}

		return true;
	}

	void DirectGraphics9::Release()
	{
		if (m_Device != nullptr)
		{
			m_Device->Release();
			m_Device = nullptr;
		}

		if (m_Direct3DInterface != nullptr)
		{
			m_Direct3DInterface->Release();
			m_Direct3DInterface = nullptr;
		}
	}
		
	void DirectGraphics9::StartRendering()
	{
		m_Device->Clear(0L,
			nullptr,
			D3DCLEAR_TARGET,			// 初期化するバッファの種類
			D3DCOLOR_ARGB(255, 0, 0, 0),// フレームバッファの初期化色
			1.0f,						// Zバッファの初期値
			0);							// ステンシルバッファの初期値

		m_Device->BeginScene();

		m_Device->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
		m_Device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
		m_Device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	}
	
	void DirectGraphics9::FinishRendering()
	{
		m_Device->EndScene();

		m_Device->Present(NULL, NULL, NULL, NULL);
	}

	bool DirectGraphics9::CreateInterface()
	{
		// インターフェース作成
		m_Direct3DInterface = Direct3DCreate9(D3D_SDK_VERSION);
		if (m_Direct3DInterface == nullptr)
		{
			// 作成失敗
			return false;
		}

		return true;
	}

	void DirectGraphics9::SetUpPasentParameter(unsigned int width, unsigned int height, bool is_window_mode, HWND window_handle)
	{
		// バックバッファの数 => 1
		m_PresentParameter.BackBufferCount = 1;
		// バックバッファのフォーマット => D3DFMT_UNKNOWN(フォーマットを知りません)
		m_PresentParameter.BackBufferFormat = D3DFMT_X8R8G8B8;
		// ウィンドウモード設定 => 定数で切り替え
			// プレゼンテーションパラメータの設定
		// フルスクリーンかどうか
		if (is_window_mode == true)
		{
			m_PresentParameter.Windowed = TRUE;
		} else {
			m_PresentParameter.Windowed = FALSE;
			m_PresentParameter.BackBufferWidth = width;
			m_PresentParameter.BackBufferHeight = height;
			m_PresentParameter.PresentationInterval	= D3DPRESENT_INTERVAL_DEFAULT;
			m_PresentParameter.hDeviceWindow = window_handle;
			m_PresentParameter.FullScreen_RefreshRateInHz = 60.0f;
		}

		// スワップエフェクト設定 => ディスプレイドライバ依存
		// スワップエフェクト => バックバッファとフロントバッファへの切り替え方法
		m_PresentParameter.SwapEffect = D3DSWAPEFFECT_DISCARD;
	}

	bool DirectGraphics9::CreateDevice(HWND window_handle)
	{
		// DirectDeviceの作成
		if (FAILED(m_Direct3DInterface->CreateDevice(D3DADAPTER_DEFAULT,
			D3DDEVTYPE_HAL,
			window_handle,
			D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_MULTITHREADED,
			&m_PresentParameter,
			&m_Device)))
		{
			return false;
		}

		return true;
	}

	bool DirectGraphics9::SetUpViewPort()
	{
		// ビューポートパラメータ
		D3DVIEWPORT9 view_port;

		// ビューポートの左上座標
		view_port.X = 0;
		view_port.Y = 0;
		// ビューポートの幅
		view_port.Width = m_PresentParameter.BackBufferWidth;
		// ビューポートの高さ
		view_port.Height = m_PresentParameter.BackBufferHeight;
		// ビューポート深度設定
		view_port.MinZ = 0.0f;
		view_port.MaxZ = 1.0f;

		// ビューポート設定
		if (FAILED(m_Device->SetViewport(&view_port)))
		{
			return false;
		}

		return true;
	}

}
