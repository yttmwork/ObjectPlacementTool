#ifndef LIB_H_
#define LIB_H_

#include <string>

namespace Lib
{
	/**
	* @brief ライブラリ初期化関数
	* ウィンドウの作成とゲームエンジンの初期化を行う
	* @param[in] title ウィンドウのタイトル名
	* @param[in] width 横幅
	* @param[in] height 縦幅
	*/
	bool Initialize(std::string title, unsigned int width, unsigned int height);

	/**
	* @brief ライブラリ終了
	* ゲームエンジンを終了させる
	*/
	void Exit();
}

#endif
