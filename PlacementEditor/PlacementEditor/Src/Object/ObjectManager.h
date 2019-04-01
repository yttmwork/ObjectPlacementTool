#ifndef OBJECT_MANAGER_H_
#define OBJECT_MANAGER_H_

#include <vector>
#include "Object.h"

//=====================================================================//
//! オブジェクト管理クラス
//=====================================================================//
class ObjectManager
{
public:
	/** Instanceのゲッター */
	static ObjectManager* Instance()
	{
		static ObjectManager instance;
		return &instance;
	}

public:
	/** Destructor */
	~ObjectManager()
	{
	}

	/**
	* @brief 登録関数@n
	* 引数のオブジェクトをリストに登録する
	* @param[in] register_obj 登録するオブジェクト
	*/
	void Register(Object* register_obj);

	/**
	* @brief 実行関数@n
	* 管理しているオブジェクトのゲーム更新関数を実行する
	*/
	void Update();

	/**
	* @brief 描画関数@n
	* 管理しているオブジェクトの描画関数を実行する
	*/
	void Draw();

	/**
	* 削除関数@n
	* 管理しているオブジェクトの削除判定を行い、
	* 削除対処となっているオブジェクトをリストから外す
	*/
	void Delete();

	/**
	* 全削除関数@n
	* 管理しているオブジェクトを全て削除する
	*/
	void AllDelete();

private:
	/** Constructor */
	ObjectManager() {}

private:
	std::vector<Object*> m_ObjectList;	//!< 管理中のオブジェクトのリスト
};

#endif
