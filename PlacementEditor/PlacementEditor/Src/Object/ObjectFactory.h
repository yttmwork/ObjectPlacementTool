#ifndef OBJECT_FACTORY_H_
#define OBJECT_FACTORY_H_

#include "Object.h"
#include "ObjectRelatedDefinitions.h"
#include "SpriteObject.h"
#include "PlacementObject.h"
#include "MouseObject.h"
#include "CreateParameter/SpriteObjectCreateParameter.h"
#include "CreateParameter/PlacementObjectCreateParameter.h"
#include "CreateParameter/CollisionObjectCreateParameter.h"

//=====================================================================//
//! オブジェクトFactoryクラス
//=====================================================================//
class ObjectFactory
{
public:	
	/**
	* @brief SpriteObject作成関数@n
	* SpriteObjectを作成して、ObjectManagerに登録する
	* @param[in] paramter 生成パラメータ
	* @param[in] is_register ObjectManager登録フラグ(初期値：true)
	*/
	static SpriteObject* CreateSprite(SpriteObjectCreateParameter& paramter, bool is_register = true);

	/**
	* @brief PlacementObject作成関数@n
	* PlacementObjectを作成して、ObjectManagerに登録する
	* @param[in] paramter 生成パラメータ
	* @param[in] is_register ObjectManager登録フラグ(初期値：true)
	*/
	static PlacementObject* CreatePlacement(PlacementObjectCreateParameter& parameter, bool is_register = true);

	/**
	* @brief MouseObject作成関数@n
	* MouseObjectを作成して、ObjectManagerに登録する@n
	* 引数がCollisionObjectCreateParameterを指定しているのは@n
	* Mouse自体に追加の生成情報がないので親クラスであるCollsionObjectの@n
	* 生成データを使用している
	* @param[in] paramter 生成パラメータ
	* @param[in] is_register ObjectManager登録フラグ(初期値：true)
	*/
	static MouseObject* CreateMouse(CollisionObjectCreateParameter& parameter, bool is_register = true);

};

#endif
