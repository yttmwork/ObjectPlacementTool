#ifndef SPRITE_H_
#define SPRITE_H_

#include <string>
#include <vector>
#include "../../Utility/Size.h"
#include "GraphicsRelatedDefinitions.h"

//=====================================================================//
//! Spriteクラス
//=====================================================================//
class Sprite
{
public:
	/**
	* @brief Constructor 
	* @param[in] name スプライト名
	* @param[in] texture_key_word スプライトで使用されているテクスチャのキーワード
	* @param[in] x テクスチャ座標(X)
	* @param[in] y テクスチャ座標(Y)
	* @param[in] size 矩形サイズ
	*/
	Sprite(std::string name, std::string texture_key_word, float x, float y, Size size);

	/**
	* @brief 頂点反映関数@n
	* スプライトに登録されているデータを頂点に反映する
	* @param vertex_list 反映を行う頂点配列
	*/
	void ReflectOnVertex(Lib::CustomVertex2D vertex_list[4]);

	/** @brief テクスチャキーワードのゲッター */
	std::string GetTextureKeyWord()
	{
		return m_TextureKeyWord;
	}

	/** @brief 矩形サイズのゲッター */
	Size GetSize()
	{
		return m_Size;
	}
private:
	std::string m_Name;				//!< スプライト名
	std::string m_TextureKeyWord;	//!< テクスチャキーワード

	Size m_Size;					//!< 矩形サイズ(テクスチャサイズが設定される)

	float m_NormalizePosX;			//!< 座標X(0.0～1.0に正規化)
	float m_NormalizePosY;			//!< 座標Y(0.0～1.0に正規化)
	Size m_NormalizeSize;			//!< 矩形サイズ(0.0～1.0に正規化)
};

#endif
