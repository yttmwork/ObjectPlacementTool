#ifndef TEXTURE_BASE_H_
#define TEXTURE_BASE_H_

#include <string>
#include <minwindef.h>
#include "../../../Utility/Size.h"

namespace Lib
{
	//=====================================================================//
	//! Textureデータの基底クラス
	//=====================================================================//
	class TextureBase
	{
	public:
		/** 
		* @brief Constructor 
		* @param[in] size テクスチャのサイズ
		*/
		TextureBase(Size size) :
			m_Size(size),
			m_LoadCount(0)
		{}

		/** @brief Destructor */
		virtual ~TextureBase() {}

		/**
		* @brief テクスチャ解放関数@n
		* 継承先のテクスチャデータを解放させるための純粋仮想関数
		*/
		virtual void Release() = 0;

		/**
		* @brief テクスチャ設定関数@n
		* グラフィクスデバイスに保持しているテクスチャを設定する
		* @param[in] stage_id テクスチャステージのID
		*/
		virtual void SetToGraphicsDevice(DWORD stage_id = 0) = 0;

		/** @brief テクスチャサイズのゲッター */
		Size GetSize()
		{
			return m_Size;
		}

		/** @brief 読み込みカウンターのインクリメント関数 */
		void IncCount()
		{
			m_LoadCount++;
		}

		/** @brief 読み込みカウンターのデクリメント関数 */
		void DecCount()
		{
			m_LoadCount = max(m_LoadCount - 1, 0);
		}

		/**
		* @brief 解放判定関数@n
		* テクスチャを解放することができるかどうかを判定し、結果を返す
		* @return 判定結果 解放できる(true)
		*/
		bool CanRelease()
		{
			return m_LoadCount == 0 ? true : false;
		}
	protected:
		Size m_Size;			//!< テクスチャサイズ
		int m_LoadCount;		//!< 読み込み回数
	private:
		/** @brief Constructor */
		TextureBase() = delete;
	};
}

#endif
