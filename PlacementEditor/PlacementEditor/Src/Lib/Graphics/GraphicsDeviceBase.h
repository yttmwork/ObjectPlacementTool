#ifndef GRAPHICS_DEVICE_BASE_H_
#define GRAPHICS_DEVICE_BASE_H_

#include <Windows.h>

namespace Lib
{
	//=========================================================================
	//! グラフィックデバイスの基底クラス@n
	//! このクラスをグラフィックデバイスクラスが継承することで、@n
	//! Graphicsクラスがどのデバイスを使用しているかを意識させないようにする@n
	//=========================================================================
	class GraphicsDeviceBase
	{
	public:
		/** @brief Constructor */
		GraphicsDeviceBase()
		{}

		/** @brief Destructor */
		virtual ~GraphicsDeviceBase()
		{}

		/**
		* @brief 初期化関数@n
		* 継承先で確実にデバイスの初期化処理を実装させるための純粋仮想関数
		* @return 初期化の成否 成功はtrue
		* @param[in] width バッファの横幅 
		* @param[in] height バッファの縦幅
		* @param[in] is_window_mode ウィンドウモードで起動するか(オプション：デフォルトはウィンドウモード)
		* @param[in] window_handle 描画対象となるウィンドウのハンドル(オプション：nullptrではWindowクラスで生成されたものを使用)
		*/
		virtual bool Initialize(unsigned int width, unsigned int height, bool is_window_mode = true, HWND window_handle = nullptr) = 0;

		/**
		* @brief 解放関数@n
		* 継承先で確実にデバイス解放処理を実装させるための純粋仮想関数
		*/
		virtual void Release() = 0;
		
		/**
		* @brief 描画開始関数@n
		* 継承先で確実に描画開始処理を実装させるための純粋仮想関数
		*/
		virtual void StartRendering() = 0;

		/**
		* @brief 描画終了関数@n
		* 継承先で確実に描画終了処理を実装させるための純粋仮想関数
		*/
		virtual void FinishRendering() = 0;
	};
}

#endif
