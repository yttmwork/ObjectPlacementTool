#ifndef DIRECTX9_GRAPHICS_H_
#define DIRECTX9_GRAPHICS_H_

#include <d3d9.h>
#include <d3dx9.h>
#include <minwinbase.h>

#include "GraphicsDeviceBase.h"

namespace Lib
{
	//================================================================
	//! DirectX9を使用するGraphicsデバイスクラス
	//================================================================
	class DirectX9Graphics : public GraphicsDeviceBase
	{
	public:
		/** @brief Constructor */
		DirectX9Graphics() :
			m_Direct3DInterface(nullptr),
			m_Device(nullptr)
		{
			ZeroMemory(&m_PresentParameter, sizeof(D3DPRESENT_PARAMETERS));
		}

		/** @brief Destructor */
		virtual ~DirectX9Graphics()
		{
			Release();
		}

		/**
		* @brief 初期化関数@n
		* DirectX9のGraphicsDeviceを使用出来るように初期化する
		* @return 初期の成否 成功はtrue
		* @param[in] width バッファの横幅
		* @param[in] height バッファの縦幅
		* @param[in] is_window_mode ウィンドウモードで起動するか(オプション：デフォルトはウィンドウモード)
		* @param[in] window_handle 描画対象となるウィンドウのハンドル(オプション：nullptrではWindowクラスで生成されたものを使用)
		*/
		virtual bool Initialize(unsigned int width, unsigned int height, bool is_window_mode = true, HWND window_handle = nullptr);

		/**
		* @brief 解放関数@n
		* GraphicsDeviceの解放を行う
		*/
		virtual void Release();
		/**
		* @brief 描画開始@n
		* 描画を開始するためのバッファの初期化などを行う
		*/
		virtual void StartRendering();

		/**
		* @brief 描画終了@n
		* 描画を終了する
		*/
		virtual void FinishRendering();

		/**
		* @brief 描画関数@n
		* 指定した位置をサイズで矩形を作成して描画する
		* @param[in] pos_x X座標
		* @param[in] pos_y Y座標
		* @param[in] pos_z Z座標
		* @param[in] width 矩形横幅
		* @param[in] height 矩形縦幅
		*/
		virtual void Draw(float pos_x, float pos_y, float pos_z, float width, float height);

		/**
		* @brief スプライト描画関数@n
		* 指定されたスプライトを描画する
		* @param[in] texture_key_word スプライトで使用するテクスチャのキーワード
		* @param[in] sprite_name 使用するスプライト名
		* @param[in] pos_x X座標
		* @param[in] pos_y Y座標
		* @param[in] pos_z Z座標
		*/
		virtual void Draw(std::string texture_key_word, std::string sprite_name, float pos_x, float pos_y, float pos_z);

		/**
		* テクスチャ読み込み関数@n
		* 指定されたファイル名からテクスチャを読み込む@n
		* ※App側で読み込む場合はTextureManagerから行う事
		* @param[in] file_name 読み込む予定のファイル名(パス込み)
		*/
		virtual TextureBase* LoadTexture(std::string file_name);

	private:
		/**
		* @brief インターフェース生成関数@n
		* DirectX9のDevice生成に必要なInterfaceを作成する
		* @return 生成の成否 成功はtrue
		*/
		bool CreateInterface();

		/**
		* @brief Device生成@n
		* DirectX9のGraphicsDeviceを生成する
		* @return 生成の成否 成功はtrue
		* @param[in] window_handle デバイスの描画対象となるウィンドウハンドル
		*/
		bool CreateDevice(HWND window_handle);

		/**
		* @brief デバイス生成パラメータの設定@n
		* DirectX9のDevice作成に使用するPresentParameterの設定を行う
		* @param[in] width バッファの横幅
		* @param[in] height バッファの縦幅
		* @param[in] is_window_mode ウィンドウモードの設定
		* @param[in] window_handle 描画の対象になるウィンドウハンドル
		*/
		void SetUpPasentParameter(unsigned int width, unsigned int height, bool is_window_mode, HWND window_handle);

		/** @brief ビューポート設定関数 */
		bool SetUpViewPort();

	private:
		D3DPRESENT_PARAMETERS m_PresentParameter;	//!< デバイスのパラメータ設定データ
		LPDIRECT3D9 m_Direct3DInterface;			//!< Device作成用のInterface
		LPDIRECT3DDEVICE9 m_Device;					//!< GrahicsDevice
	};
}

#endif
