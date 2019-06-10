#ifndef COLLIDER_DATA_H_
#define COLLIDER_DATA_H_

#include "../Object/Object.h"
#include "CollisionRelatedDefinitions.h"

namespace Collision
{
	struct RectCollider;
	struct CircleCollider;

	//=====================================================================//
	//! 当たり基底データ
	//=====================================================================//
	struct ColliderBase
	{
		/**
		* @brief Constructor
		*/
		ColliderBase()
		{
			X = 0.0f;
			Y = 0.0f;
			Z = 0.0f;
		}

		/**
		* @brief Constructor
		* @param[in] data 初期化データ
		*/
		ColliderBase(const ColliderBase& data)
		{
			this->X = data.X;
			this->Y = data.Y;
			this->Z = data.Z;
		}

		/**
		* @brief Constructor
		* @param[in] x X座標
		* @param[in] y Y座標
		* @param[in] z Z座標（オプション)
		*/
		ColliderBase(float x, float y, float z = 0.0f) :
			X(x),
			Y(y),
			Z(z)
		{
		}

		/**
		* @brief ColliderTypeのゲッター
		*/
		virtual ColliderType GetColliderType() = 0;

		float X;	//!< 座標X
		float Y;	//!< 座標Y
		float Z;	//!< 座標Z
	};

	//=====================================================================//
	//! Point当たりデータ
	//=====================================================================//
	struct PointCollider : public ColliderBase
	{
		/** @brief ColliderTypeのゲッター */
		virtual ColliderType GetColliderType()
		{
			return ColliderType::Point;
		}
	};

	//=====================================================================//
	//! 矩形当たりデータ
	//=====================================================================//
	struct RectCollider : public ColliderBase
	{
		/**
		* @brief Constructor
		*/
		RectCollider() :
			Width(0.0f),
			Height(0.0f),
			Degree(0.0f)
		{
		}

		/**
		* @brief Constructor
		* @param[in] data 初期化データ
		*/
		RectCollider(const RectCollider& data) :
			ColliderBase(data.X, data.Y, data.Z),
			Width(data.Width),
			Height(data.Height),
			Degree(data.Degree)
		{
		}

		/**
		* @brief Constructor
		* @param[in] x X座標
		* @param[in] y Y座標
		* @param[in] z Z座標
		* @param[in] width 矩形の横幅
		* @param[in] height 矩形の縦幅
		* @param[in] degree 角度
		*/
		RectCollider(float x, float y, float z, float width, float height, float degree = 0.0f) :
			ColliderBase(x, y, z),
			Width(width),
			Height(height),
			Degree(degree)
		{
		}

		/**  @brief ColliderTypeのゲッター */
		virtual ColliderType GetColliderType()
		{
			return ColliderType::Rect;
		}

		float Width;	// 横幅
		float Height;	// 縦幅
		float Degree;	// 角度
	};


	//=====================================================================//
	//! 円当たりデータ
	//=====================================================================//
	struct CircleCollider : public ColliderBase
	{
		/**
		* @brief Constructor
		*/
		CircleCollider()
		{
		}

		/**
		* @brief Constructor
		* @param[in] data 初期化データ
		*/
		CircleCollider(const CircleCollider& data) :
			ColliderBase(data.X, data.Y, data.Z),
			Radius(data.Radius)
		{
		}

		/**
		* @brief Constructor
		* @param[in] x X座標
		* @param[in] y Y座標
		* @param[in] radius 半径
		*/
		CircleCollider(float x, float y, float radius) :
			ColliderBase(x, y),
			Radius(radius)
		{
		}

		float Radius;		//!< 半径
	};
}

#endif
