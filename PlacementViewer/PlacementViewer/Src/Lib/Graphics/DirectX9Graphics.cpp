#include "DirectX9Graphics.h"
#include "GraphicsRelatedDefinitions.h"
#include "../Window.h"
#include "../File/Texture/DirectX9Texture.h"
#include "SpriteManager.h"
#include "../File/Texture/TextureManager.h"

namespace Lib
{
	bool DirectX9Graphics::Initialize(unsigned int width, unsigned int height, bool is_window_mode, HWND window_handle)
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

	void DirectX9Graphics::Release()
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

	void DirectX9Graphics::StartRendering()
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

	void DirectX9Graphics::FinishRendering()
	{
		m_Device->EndScene();

		m_Device->Present(NULL, NULL, NULL, NULL);
	}

	void DirectX9Graphics::Draw(float pos_x, float pos_y, float pos_z, float width, float height, float degree)
	{
		CustomVertex2D vertex[] =
		{
			{ pos_x, pos_y, pos_z, 1.0f, 0xffffffff, 0.0f, 0.0f },
			{ pos_x + width, pos_y, pos_z, 1.0f, 0xffffffff, 0.0f, 0.0f },
			{ pos_x + width, pos_y + height, pos_z, 1.0f, 0xffffffff, 0.0f, 0.0f },
			{ pos_x, pos_y + height, pos_z, 1.0f, 0xffffffff, 0.0f, 0.0f },
		};

		VertexTransform(vertex, degree, 1.0f, 1.0f);

		m_Device->SetTexture(0, nullptr);
		m_Device->SetFVF(Lib::Vertex2DFVF);
		m_Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, vertex, sizeof(CustomVertex2D));
	}

	void DirectX9Graphics::Draw(std::string sprite_name, float pos_x, float pos_y, float pos_z, float degree)
	{
		CustomVertex2D vertex_list[4];

		for (int i = 0; i < 4; i++)
		{
			vertex_list[i].X = pos_x;
			vertex_list[i].Y = pos_y;
			vertex_list[i].Z = pos_z;
			vertex_list[i].Rhw = 1.0f;
			vertex_list[i].Color = 0xffffffff;
		}
		Sprite* sprite = SpriteManager::Instance()->Find(sprite_name);
		if (sprite == nullptr)
		{
			return;
		}
		sprite->ReflectOnVertex(vertex_list);
		VertexTransform(vertex_list, degree, 1.0f, 1.0f);

		TextureBase* texture = TextureManager::Instance()->Find(sprite->GetTextureKeyWord());
		if (texture != nullptr)
		{
			texture->SetToGraphicsDevice(0);
		}
		m_Device->SetFVF(Lib::Vertex2DFVF);
		m_Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, vertex_list, sizeof(CustomVertex2D));
	}

	TextureBase* DirectX9Graphics::LoadTexture(std::string file_name)
	{
		LPDIRECT3DTEXTURE9 texture;
		Size size;
		D3DXIMAGE_INFO info;

		// 2の階乗じゃないので元のサイズを取得してD3DXCreateTextureFromFileExで使う
		D3DXGetImageInfoFromFile(file_name.c_str(), &info);
		
		if (FAILED( D3DXCreateTextureFromFileEx(m_Device,
											file_name.c_str(),
											info.Width,
											info.Height,
											1,
											0,
											D3DFMT_UNKNOWN,
											D3DPOOL_MANAGED,
											D3DX_DEFAULT,
											D3DX_DEFAULT,
											0x0000ff00,
											nullptr,
											nullptr,
											&texture)))
		{
			return nullptr;
		} 
		else
		{
			// テクスチャサイズの取得
			D3DSURFACE_DESC desc;

			if( FAILED( texture->GetLevelDesc( 0, &desc ) ))
			{
				texture->Release();
				return nullptr;
			}
			size.Width = desc.Width;
			size.Height = desc.Height;
		}

		return new DirectX9Texture(m_Device, texture, size);
	}


	bool DirectX9Graphics::CreateInterface()
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

	void DirectX9Graphics::SetUpPasentParameter(unsigned int width, unsigned int height, bool is_window_mode, HWND window_handle)
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

	bool DirectX9Graphics::CreateDevice(HWND window_handle)
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

	bool DirectX9Graphics::SetUpViewPort()
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
