#ifndef SPRITE_MANAGER_H_
#define SPRITE_MANAGER_H_

#include <map>
#include <vector>
#include "Sprite.h"

//=====================================================================//
//! Sprite管理クラス
//=====================================================================//
class SpriteManager
{
public:
	/** Instanceのゲッター */
	static SpriteManager* Instance()
	{
		static SpriteManager instance;
		return &instance;
	}
public:
	/** Destructor */
	~SpriteManager()
	{
	}

	/**
	* @brief Sprite登録関数@n
	* 指定された情報からSpriteを作成し、登録する
	* @param[in] sprite_name 登録するSpriteの名前
	* @param[in] texture_key_word Spriteで使用するテクスチャのキーワード
	* @param[in] x テクスチャ座標(X)
	* @param[in] y テクスチャ座標(Y)
	* @param[in] size テクスチャ矩形のサイズ
	*/
	void Entry(std::string sprite_name, std::string texture_key_word, float x, float y, Size size);

	/**
	* @brief Sprite削除関数@n
	* 指定された情報からSpriteを削除する
	* @param[in] sprite_name 削除するSpriteの名前
	* @param[in] texture_key_word 削除するSpriteが使われているテクスチャのキーワード
	*/
	void Delete(std::string sprite_name, std::string texture_key_word);

	/**
	* @brief Sprite全削除関数@n
	* 登録されたSpriteを全て削除する
	*/
	void AllDelete();

	/**
	* @brief 検索関数@n
	* 指定された情報のSpriteを検索する
	* @return 見つかったSprite 見つからなかったらnullptr
	*/
	Sprite* Find(std::string texture_key_word, std::string sprite_name);

private:
	/** Constructor */
	SpriteManager() {}
private:
	std::map<std::string, std::map<std::string, Sprite*>> m_SpriteList; //!< 登録されたSpriteのリスト
};

#endif
