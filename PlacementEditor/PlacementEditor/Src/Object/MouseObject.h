#ifndef MOUSE_OBJECT_H_
#define MOUSE_OBJECT_H_

#include "../Utility/Vec.h"
#include "CollisionObject.h"
#include "ObjectRelatedDefinitions.h"

//=====================================================================//
//! マウスオブジェクトクラス
//=====================================================================//
class MouseObject : public CollisionObject
{
public:
	/**
	* @brief Constructor@n
	* Mouseは生成時に新しく追加する情報がないので、@n
	* CollisionObjectCreateParameterを使用してる
	* @param[in] parameter CollisionObject生成データ
	*/
	MouseObject(CollisionObjectCreateParameter& parameter) :
		CollisionObject(
			parameter.Group,
			parameter.SpriteName,
			parameter.PosX,
			parameter.PosY,
			parameter.PosZ,
			parameter.Degree,
			parameter.ScaleX,
			parameter.ScaleY
		),
		m_ClickPos(Vec2(0.0f, 0.0f)),
		m_OnObject(false)
	{
		m_PointCollider.X = m_PosX;
		m_PointCollider.Y = m_PosY;
	}

	/** @brief Destructor */
	virtual ~MouseObject() {}

	/**
	* @brief 更新関数@n
	* マウスで毎フレーム行う処理を実装する
	*/
	virtual void Update();

	/**
	* @brief 描画関数@n
	* マウスは描画を行わないので、空関数として実装
	*/
	virtual void Draw() {}

	/**
	* @brief 当たり反映関数@n
	* 引数のオブジェクトを使用して当たりの反映処理を行う
	* @param[in] object 当たった相手
	*/
	virtual void ReflectCollision(CollisionObject* object);

	/** @brief 当たりグループのゲッター */
	virtual Collision::CollisionGroup GetCollisionGroup()
	{
		return Collision::CollisionGroup::Mouse;
	}

	/** @brief 当たり形状のゲッター */
	virtual Collision::ColliderType GetColliderType()
	{
		return m_PointCollider.GetColliderType();
	}

	/** @brief 当たりデータのゲッター */ 
	virtual void GetColliderData(Collision::PointCollider& out)
	{
		out = m_PointCollider;
	}

private:
	Collision::PointCollider m_PointCollider;	//!< ポイント当たりデータ
	Vec2 m_ClickPos;							//!< クリック座標
	bool m_OnObject;							//!< オブジェクト上判定フラウ
};

#endif
