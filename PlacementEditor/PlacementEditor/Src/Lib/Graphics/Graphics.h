#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include "GraphicsRelatedDefinitions.h"
#include "GraphicsDeviceBase.h"
#include "GraphicsDeviceFactory.h"

namespace Lib
{
	//==========================================================
	//! 描画クラス@n
	//! 描画関連の処理はこのクラスを通して行う
	//==========================================================
	class Graphics
	{
	public:
		/**
		* @brief インスタンスのゲッター@n
		* Graphicsはシングルトンとして使用するので@n
		* 必ずこのメソッドを通して、他のメンバにアクセスすること
		* @return インスタンスのポインタ
		*/
		static Graphics* Instance()
		{
			static Graphics instance;
			return &instance;
		}

	public:
		/** @brief Destructor */
		~Graphics()
		{
			Release();
		}

		/**
		* @brief 初期化関数
		* GraphicsDeviceの初期化を行い、描画を行えるようにする@n
		* ゲームループの前に実行しておくこと
		* @return 初期化の成否 成功はtrue
		* @param[in] width バッファの横幅
		* @param[in] height バッファの縦幅
		* @param[in] is_window_mode ウィンドウモード設定(オプション：デフォルトはウィンドウモード)
		* @param[in] window_handle GraphicsDeviceで使用するウィンドウハンドル(オプション：デフォルトはWindow生成で使用したウィンドウハンドル)
		*/
		bool Initialize(unsigned int width, unsigned int height, bool is_window_mode = true, GraphicsDevice select_device = GraphicsDevice::DirectX9, HWND window_handle = nullptr);

		/**
		* @brief 解放関数@n
		* GraphicsDevice、Factoryの解放を行う
		*/
		void Release();

		/**
		* @brief 描画開始関数@n
		* 描画開始の関数になるので、ゲームループ内で描画処理を行う前に必ず１回だけ実行する
		*/
		void StartRendering();

		/**
		* @brief 描画終了関数@n
		* 描画終了の関数なので、描画処理を行った後に必ず１回だけ実行する
		*/
		void FinishRendering();

	private:
		/**
		* @brief Constructor@n
		* シングルトンとして使用するのでコンストラクタは@n
		* メンバの初期化だけを行うようにする@n
		* privateなのはインスタンス化阻止対応
		*/
		Graphics() :
			m_SelectedDevice(GraphicsDevice::DirectX9),
			m_Device(nullptr),
			m_Factory(nullptr)
		{
		}

	private:
		GraphicsDevice m_SelectedDevice;		// 選択されたデバイス
		GraphicsDeviceFactory* m_Factory;		// デバイス生成Factory
		GraphicsDeviceBase* m_Device;			// GraphicsDevice
	};
}

#endif
