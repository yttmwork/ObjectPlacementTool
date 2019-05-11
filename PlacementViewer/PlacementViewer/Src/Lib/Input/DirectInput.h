#ifndef DIRECT_INPUT_H_
#define DIRECT_INPUT_H_

#include <dinput.h>

#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

#include "InputRelatedDefinition.h"

namespace Lib
{
	//=====================================================================//
	//! DirectInputクラス
	//=====================================================================//
	class DirectInput
	{
	public:
		/** @brief Constructor */
		DirectInput() :
			m_InputInterface(nullptr),
			m_MouseDevice(nullptr)
		{}

		/** @brief Destructor */
		~DirectInput()
		{
			Release();
		}

		/**
		* @brief 生成関数@n
		* DirectInputのインターフェースやデバイスの作成を行う
		* @return 生成の成否 (trueは成功)
		*/
		bool Create();

		/*
		* @brief 更新関数
		* 入力情報の更新を行う関数
		*/
		void Update();

		/**
		* マウスを押した瞬間の判定関数@n
		* 指定したマウスのボタンを押した瞬間かどうかの判定を取得する
		* @return 押した瞬間の判定 trueは押した瞬間
		* @param[in] key_type マウスキーの種類
		*/
		bool OnMouseDown(MouseKey key_type);

		/**
		* マウスを押しているか状態かの判定関数@n
		* 指定したマウスのボタンを押している状態かどうかの判定を取得する
		* @return 押している状態かの判定 trueは押している状態
		* @param[in] key_type マウスキーの種類
		*/
		bool OnMousePush(MouseKey key_type);

		/**
		* マウスを離した瞬間かの判定関数@n
		* 指定したマウスのボタンを離した瞬間かどうかの判定を取得する
		* @return 離した瞬間の判定 trueは離した瞬間
		* @param[in] key_type マウスキーの種類
		*/
		bool OnMouseUp(MouseKey key_type);

	private:
		/**
		* @brief インターフェースの生成関数@n
		* DirectInputのインターフェースを生成する
		* @return 生成の成否 (成功はtrue)
		*/
		bool CreateInterface();

		/**
		* @brief マウスデバイスの生成関数@n
		* マウスデバイスの生成を行う
		* @return 生成の成否 (成功はtrue)
		*/
		bool CreateMouseDevice();

		/**
		* 解放関数@n
		* DirectInputの解放を行う
		*/
		void Release();

	private:
		LPDIRECTINPUT8 m_InputInterface;		//!< DIRECTINPUT8のポインタ
		LPDIRECTINPUTDEVICE8 m_MouseDevice;		//!< DIRECTINPUTDEVICE8のポインタ

		DIMOUSESTATE m_PrevMouseState;			//!< マウスの１フレーム前の入力情報
		DIMOUSESTATE m_CurrentMouseState;		//!< マウスの現在の入力情報
	};
}

#endif
