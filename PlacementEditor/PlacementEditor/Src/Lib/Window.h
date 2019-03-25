#ifndef WINDOW_H_
#define WINDOW_H_

#include <string>
#include <Windows.h>

namespace Lib
{
	const std::string WindowClassName = "EditorWindow";	//!< ウィンドウクラスの名前

	class Window
	{
	public:
		/**
		* @brief ウィンドウプロシージャ
		* @param[in] window_handle イベントが発生したウィンドウのハンドル
		* @param[in] message_id イベントメッセージ
		* @param[in] wparam イベント情報
		* @param[in] lparam イベント情報
		* @return メッセージ処理結果
		*/
		static LRESULT CALLBACK WindowProc(HWND window_handle, UINT message_id, WPARAM wparam, LPARAM lparam);

		/**
		* インスタンスのゲッター@n
		* Windowはシングルトンとして使用するので@n
		* 必ずこのメソッドを通して、他のメンバにアクセスすること
		* @return インスタンスのポインタ
		*/
		static Window* Instance()
		{
			static Window instance;
			return &instance;
		}

	public:
		/** @brief Destructor */
		~Window()
		{}

		/**
		* ウィンドウ生成関数@n
		* 引き数で指定された内容でウィンドウを作成する
		* @return 生成の成否 成功はtrue
		* @param[in] title ウィンドウのタイトル
		* @param[in] width ウィンドウの横幅
		* @param[in] height ウィンドウの縦幅
		*/
		bool Create(std::string title, unsigned int width, unsigned int height);

	private:
		/**
		* @brief Constructor@n
		* インスタンス化阻止対応
		*/
		Window() 
		{}

	};
}

#endif
