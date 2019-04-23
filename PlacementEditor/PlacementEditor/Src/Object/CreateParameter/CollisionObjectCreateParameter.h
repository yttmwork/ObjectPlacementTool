#ifndef COLLIDER_OBJECT_CREATE_PARAMETER_H_
#define COLLIDER_OBJECT_CREATE_PARAMETER_H_

#include "SpriteObjectCreateParameter.h"
#include "../../Collision/CollisionRelatedDefinitions.h"

//=====================================================================//
//! 当たりオブジェクト生成情報構造体
//=====================================================================//
struct CollisionObjectCreateParameter : public SpriteObjectCreateParameter
{
	/**
	* @brief Constructor
	* @param[in] group 当たりのグループ
	* @param[in] sprite_name 描画予定のスプライト名
	* @param[in] x X軸描画座標
	* @param[in] y Y軸描画座標
	* @param[in] z Z軸描画座標(初期値0.0f)
	* @param[in] degree 回転角度(度数法、初期値0.0f)
	* @param[in] scale_x X軸拡縮率(初期値1.0f)
	* @param[in] scale_y Y軸拡縮率(初期値1.0f)
	*/
	CollisionObjectCreateParameter(Collision::CollisionGroup gropu, std::string sprite_name, float x, float y, float z = 0.0f, float degree = 0.0f, float scale_x = 1.0f, float scale_y = 1.0f) :
		SpriteObjectCreateParameter(sprite_name, x, y, z, degree, scale_x, scale_y),
		Group(gropu)
	{}

	Collision::CollisionGroup Group;	//!< 当たり区別用グループ

private:
	/** Constructor */
	CollisionObjectCreateParameter() = delete;

};

#endif
