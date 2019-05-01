#ifndef TEXTURE_MANAGER_H_
#define TEXTURE_MANAGER_H_

#include <map>
#include <string>
#include "TextureBase.h"

namespace Lib
{
	//=====================================================================//
	//! Texture管理クラス
	//=====================================================================//
	class TextureManager
	{
	public:
		/** @brief Instanceのゲッター */
		static TextureManager* Instance()
		{
			static TextureManager instance;
			return &instance;
		}

	public:
		/**
		* @brief テクスチャ読み込み関数@n
		* 指定されたファイル名でテクスチャを読み込み@n
		* 読み込み済みリストに登録する
		* @return 読み込み結果 成功(true)
		* @param[in] key_word 読み込み後の登録キーワード
		* @param[in] file_name 読み込む予定のファイル名
		*/
		bool Load(std::string key_word, std::string file_name);

		/**
		* @brief テクスチャ解放関数@n
		* 指定されたキーワードのテクスチャを解放する
		* @param[in] key_word 削除をするテクスチャのキーワード
		*/
		void Release(std::string key_word);

		/**
		* @brief テクスチャ全開放関数@n
		* このクラスが保持しているテクスチャを全て解放する
		*/
		void AllRelease();

		/**
		* @brief テクスチャ検索関数@n
		* 指定されたキーワードのテクスチャがあるかを調べる
		* @return 見つかったテクスチャデータ 見つからなかったらnullptr
		* @param[in] key_word 探したいテクスチャのキーワード
		*/
		TextureBase* Find(std::string key_word);

	private:
		std::map<std::string, TextureBase*> m_TextureList;	//!< 登録テクスチャのリスト
	};
}

#endif
