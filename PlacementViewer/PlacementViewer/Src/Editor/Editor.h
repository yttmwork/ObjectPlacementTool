#ifndef EDITOR_H_
#define EDITOR_H_

#include <string>
#include "../Object/PlacementObject.h"

//=====================================================================//
//! エディタークラス
//=====================================================================//
class Editor
{
public:
	/**
	* @brief インスタンスのゲッター@n
	* Graphicsはシングルトンとして使用するので@n
	* 必ずこのメソッドを通して、他のメンバにアクセスすること
	* @return インスタンスのポインタ
	*/
	static Editor* Instance()
	{
		static Editor instance;
		return &instance;
	}

	/**
	* @brief 初期化関数@n
	* メンバ変数の初期化を行う
	* このゲームループが開始される前に１度だけ実行する
	*/
	void Initialize(std::string select_sprite_name)
	{
		m_SelectSpriteName = select_sprite_name;
		m_DragObject = nullptr;
	}

	/**
	* @brief データ受信関数@n
	* 通信結果で渡されたバッファからエディターのデータを書き換える
	* @param[in] buffer 通信結果
	*/
	void Recive(char buffer[1024]);

	/** @brief ツールで選択中のSprite名のゲッター */
	std::string GetSelectSpriteName()
	{
		return m_SelectSpriteName;
	}

	/** @brief ドラッグオブジェクトのゲッター */
	PlacementObject* GetDragObject()
	{
		return m_DragObject;
	}

	/** @brief ドラッグオブジェクトのセッター */
	void SetDragObject(PlacementObject* obj)
	{
		m_DragObject = obj;
	}
private:
	/**
	* @brief Constructor@n
	* シングルトンとして使用するのでコンストラクタは@n
	* メンバの初期化だけを行うようにする@n
	* privateなのはインスタンス化阻止対応
	*/
	Editor() {}

private:
	std::string m_SelectSpriteName;	//!< ツールで選択中のスプライト名
	PlacementObject* m_DragObject;	//!< ドラッグ中のオブジェクト
};

#endif
