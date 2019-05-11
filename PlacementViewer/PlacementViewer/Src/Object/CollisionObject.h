#ifndef COLLISION_OBJECT_H_
#define COLLISION_OBJECT_H_

#include "SpriteObject.h"
#include "../Collision/ColliderData.h"
#include "CreateParameter/CollisionObjectCreateParameter.h"
#include "../Collision/CollisionRelatedDefinitions.h"

//=====================================================================//
//! 当たり判定追加オブジェクトクラス
//=====================================================================//
class CollisionObject : public SpriteObject
{
public:
	/**
	* @brief Constructor
	* @param[in] parameter CollisionObject生成データ
	*/
	CollisionObject(CollisionObjectCreateParameter& parameter) :
		SpriteObject(
			parameter.SpriteName,
			parameter.PosX,
			parameter.PosY,
			parameter.PosZ,
			parameter.Degree,
			parameter.ScaleX,
			parameter.ScaleY),
		m_CollisionGroup(parameter.Group)
	{
	}

	/**
	* @brief Constructor
	* @param[in] group 当たりグループ
	* @param[in] sprite_name スプライト名
	* @param[in] x X軸描画座標
	* @param[in] y Y軸描画座標
	* @param[in] z Z軸描画座標(初期値：0.0f)
	* @param[in] degree 回転角度(度数法 初期値：0.0f)
	* @param[in] scale_x X軸拡縮率(初期値：1.0f)
	* @param[in] scale_y Y軸拡縮率(初期値：1.0f)
	*/
	CollisionObject(Collision::CollisionGroup group, std::string sprite_name, float x, float y, float z = 0.0f, float degree = 0.0f, float scale_x = 1.0f, float scale_y = 1.0f) :
		SpriteObject(sprite_name, x, y, z, degree, scale_x, scale_y),
		m_CollisionGroup(group)
	{
	}

	/**
	* @brief 当たり反映関数@n
	* 引数のオブジェクトを使用して当たりの反映処理を行う
	* @param[in] object 当たった相手
	*/
	virtual void ReflectCollision(CollisionObject* object) = 0;

	/** @brief 当たり判定グループの取得 */
	virtual Collision::CollisionGroup GetCollisionGroup() = 0;

	/** @brief 当たりの形状の取得 */
	virtual Collision::ColliderType GetColliderType() = 0;

	
	/**
	* @brief 当たりデータの更新関数@n
	* ColliderDataの更新を行う
	*/
	//virtual void UpdateCollisionData() = 0;

	/** 
	* @brief 当たりデータ取得関数@n
	* @param[in] collider 当たり形状データ
	*/
	virtual void GetColliderData(Collision::PointCollider& collider) {}

	/**
	* @brief 当たりデータ取得関数@n
	* @param[in] collider 当たり形状データ
	*/
	virtual void GetColliderData(Collision::RectCollider& collider) {}

	/**
	* @brief 当たりデータ取得関数@n
	* @param[in] collider 当たり形状データ
	*/
	virtual void GetColliderData(Collision::CircleCollider& collider) {}
protected:
	Collision::CollisionGroup m_CollisionGroup;		//!< 判定判断用グループ
};

#endif
