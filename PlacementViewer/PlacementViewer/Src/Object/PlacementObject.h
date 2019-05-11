#ifndef PLACEMENT_OBJECT_H_
#define PLACEMENT_OBJECT_H_

#include "CollisionObject.h"
#include "ObjectRelatedDefinitions.h"
#include "CreateParameter/PlacementObjectCreateParameter.h"

//=====================================================================//
//! 配置オブジェクトクラス
//=====================================================================//
class PlacementObject : public CollisionObject
{
public:
	/**
	* @brief Constructor
	* @param[in] parameter 生成用データ
	*/
	PlacementObject(PlacementObjectCreateParameter& parameter);

	/** @brief Destructor */
	virtual ~PlacementObject() {}

	/**
	* @brief 更新関数@n
	* 配置オブジェクトが毎フレーム行う処理を実装する
	*/
	virtual void Update();

	/**
	* @brief 描画関数@n
	* 配置オブジェクトを描画する
	*/
	virtual void Draw();

	/** @brief 当たりグループのゲッター */
	virtual Collision::CollisionGroup GetCollisionGroup()
	{
		return Collision::CollisionGroup::PlacementObj;
	}

	/**
	* @brief 当たり反映関数@n
	* 引数のオブジェクトを使用して当たりの反映処理を行う
	* @param[in] object 当たった相手
	*/
	virtual void ReflectCollision(CollisionObject* object);

	/** @brief 当たりの形状のゲッター */
	virtual Collision::ColliderType GetColliderType()
	{
		return m_RectCollider.GetColliderType();
	}

	/** @brief 当たりデータのゲッター */
	virtual void GetColliderData(Collision::RectCollider& out)
	{
		out = m_RectCollider;
	}

	/** @brief 配置オブジェクトの種類のゲッター */
	PlacementType GetPlacementType()
	{
		return m_Type;
	}

protected:
	PlacementType m_Type;	//!< 配置オブジェクトの種類
	int m_Id;				//!< 識別ID
	bool m_IsSelect;		//!< 選択中判定

private:
	Collision::RectCollider m_RectCollider;	//!< 矩形当たりデータ
};

#endif
