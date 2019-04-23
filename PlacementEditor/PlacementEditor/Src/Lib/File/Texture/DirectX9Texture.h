#ifndef DIRECTX9_TEXTURE_H_
#define DIRECTX9_TEXTURE_H_

#include <d3d9.h>
#include "TextureBase.h"

namespace Lib
{
	//=====================================================================//
	//! DirectX9用Textureクラス
	//=====================================================================//
	class DirectX9Texture : public TextureBase
	{
	public:
		/**
		* @brief Constructor
		* @param[in] device DirectX9のグラフィックデバイス
		* @param[in] texture DirectX9のテクスチャデータ
		* @param[in] size テクスチャサイズ
		*/
		DirectX9Texture(LPDIRECT3DDEVICE9 device, LPDIRECT3DTEXTURE9 texture, Size size) :
			m_Device(device),
			m_Texture(texture),
			TextureBase(size)
		{}

		/** @brief Destructor */
		virtual ~DirectX9Texture()
		{
			Release();
		}

		/**
		* @brief テクスチャ解放関数@n
		* このクラスが保持しているテクスチャを解放する
		*/
		virtual void Release();

		/**
		* @brief テクスチャ設定関数@n
		* グラフィクスデバイスに保持しているテクスチャを設定するための純粋仮想関数
		* @param[in] stage_id テクスチャステージのID
		*/
		virtual void SetToGraphicsDevice(DWORD stage_id = 0);
	private:
		LPDIRECT3DDEVICE9 m_Device;			//!< グラフィクスデバイス
		LPDIRECT3DTEXTURE9 m_Texture;		//!< テクスチャデータ
	};
}

#endif
