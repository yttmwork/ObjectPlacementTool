#ifndef OBJECT_FACTORY_H_
#define OBJECT_FACTORY_H_

#include "Object.h"
#include "CreateParameter/CreateParameterBase.h"
#include "ObjectRelatedDefinitions.h"

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
};

#endif
