#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include "GraphicsRelatedDefinitions.h"
#include "GraphicsDeviceBase.h"

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
		bool Initialize(unsigned int width, unsigned int height, bool is_window_mode = true, HWND window_handle = nullptr);

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

		/**
		* @brief 矩形描画関数@n
		* 指定した位置をサイズで矩形を作成して描画する
		* @param[in] pos_x X座標
		* @param[in] pos_y Y座標
		* @param[in] pos_z Z座標
		* @param[in] width 矩形横幅
		* @param[in] height 矩形縦幅
		* @param[in] degree 回転角度(デフォルトは0.0)
		*/
		void Draw(float pos_x, float pos_y, float pos_z, float width, float height, float degree = 0.0f);

		/**
		* @brief スプライト描画関数@n
		* 指定されたスプライトを描画する
		* @param[in] texture_key_word スプライトで使用するテクスチャのキーワード
		* @param[in] sprite_name 使用するスプライト名
		* @param[in] pos_x X座標
		* @param[in] pos_y Y座標
		* @param[in] pos_z Z座標
		* @param[in] degree 回転角度(デフォルトは0.0)
		*/
		void Draw(std::string texture_key_word, std::string sprite_name, float pos_x, float pos_y, float pos_z, float degree = 0.0f);

		/**
		* テクスチャ読み込み関数@n
		* 指定されたファイル名からテクスチャを読み込む@n
		* ※App側で読み込む場合はTextureManagerから行う事
		* @param[in] file_name 読み込む予定のファイル名(パス込み)
		*/
		TextureBase* LoadTexture(std::string file_name);

	private:
		/**
		* @brief Constructor@n
		* シングルトンとして使用するのでコンストラクタは@n
		* メンバの初期化だけを行うようにする@n
		* privateなのはインスタンス化阻止対応
		*/
		Graphics() :
			m_Device(nullptr)
		{
		}

	private:
		GraphicsDeviceBase* m_Device;			//!< GraphicsDevice
	};
}

#endif
