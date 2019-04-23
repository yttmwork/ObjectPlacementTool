#ifndef INPUT_H_
#define INPUT_H_

#include "../../Utility/Vec.h"
#include "InputRelatedDefinition.h"
#include "DirectInput.h"

namespace Lib
{
	//=====================================================================//
	//! 入力関連クラス
	//=====================================================================//
	class Input
	{
	public:
		/**
		* @brief インスタンスのゲッター@n
		* Graphicsはシングルトンとして使用するので@n
		* 必ずこのメソッドを通して、他のメンバにアクセスすること
		* @return インスタンスのポインタ
		*/
		static Input* Instance()
		{
			static Input instance;
			return &instance;
		}

		/**
		* @brief 初期化関数@n
		* インプット処理を使用できるように初期化を行う
		* @return 初期化の成否 成功はtrue
		*/
		bool Initialize();

		/**
		* @brief 解放関数@n
		* インプットの解放を行う
		*/
		void Release();

		/**
		* @brief 更新関数@n
		* 入力デバイスの更新を行う、毎フレームに１度だけ必ず呼び出す@n
		* 入力情報の取得はOnMouseDown、OnMousePushなどで取得する
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

		/** マウスの座標取得関数 */
		Vec2 GetMousePos()
		{
			return m_MousePos;
		}

		/** マウスの前フレーム差分ベクトル取得関数 */
		Vec2 GetMouseMoveVec()
		{
			return m_MouseMoveVec;
		}

	private:
		/**
		* @brief Constructor@n
		* シングルトンとして使用するのでコンストラクタは@n
		* メンバの初期化だけを行うようにする@n
		* privateなのはインスタンス化阻止対応
		*/
		Input() 
		{}

		/**
		* @biref マウスの更新@n
		* マウス情報の更新を行う
		*/
		void MouseUpdate();
	private:
		DirectInput* m_InputDevice;	//!<  DirectInputのデバイスクラス
		Vec2 m_MouseMoveVec;		//!< マウスの移動ベクトル
		Vec2 m_MousePos;			//!< マウスの座標
	};
}

#endif
