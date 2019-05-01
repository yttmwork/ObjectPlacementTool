#ifndef GRAPHICS_DEVICE_BASE_H_
#define GRAPHICS_DEVICE_BASE_H_

#include <Windows.h>
#include "../File/Texture/TextureBase.h"
#include "GraphicsRelatedDefinitions.h"

namespace Lib
{
	//=========================================================================
	//! グラフィックデバイスの基底クラス@n
	//! このクラスをグラフィックデバイスクラスが継承することで、@n
	//! Graphicsクラスがどのデバイスを使用しているかを意識させないようにする
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

		/**
		* @brief 矩形描画関数@n
		* 継承先で確実に描画関数を実装させるための純粋仮想関数@n
		* 指定した位置をサイズで矩形を作成して描画する
		* @param[in] pos_x X座標
		* @param[in] pos_y Y座標
		* @param[in] pos_z Z座標
		* @param[in] width 矩形横幅
		* @param[in] height 矩形縦幅
		* @param[in] degree 回転角度(デフォルトは0.0)
		*/
		virtual void Draw(float pos_x, float pos_y, float pos_z, float width, float height, float degree = 0.0f) = 0;

		/**
		* @brief スプライト描画関数@n
		* 引き数で指定されたスプライトを描画させるための純粋仮想関数@n
		* @param[in] sprite_name 描画するスプライト名
		* @param[in] pos_x X座標
		* @param[in] pos_y Y座標
		* @param[in] pos_z Z座標
		* @param[in] degree 回転角度(デフォルトは0.0)
		*/
		virtual void Draw(std::string sprite_name, float pos_x, float pos_y, float pos_z, float degree = 0.0f) = 0;

		/**
		* @brief テクスチャ読み込み@n
		* 指定されたテクスチャを読み込む
		* @return 読み込まれたテクスチャが格納されたTextureクラス 失敗はnullptr
		* @param[in] file_name 読み込む予定のテクスチャのファイル名(パス込み)
		*/
		virtual TextureBase* LoadTexture(std::string file_name) = 0;

	protected:
		/**
		* @brief 頂点変換
		* 矩形頂点に対して拡縮、回転を行う
		* @param[out] vertex_list 変換対象の頂点リスト
		* @param[in] degree 回転角度
		* @param[in] scale_x 拡縮率(X)
		* @param[in] scale_y 拡縮率(Y)
		*/
		void VertexTransform(CustomVertex2D vertex_list[4], float degree, float scale_x, float scale_y);
	};
}

#endif
