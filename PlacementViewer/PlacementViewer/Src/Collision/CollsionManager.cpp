﻿#include "CollisionManager.h"
#include "../Object/MouseObject.h"
#include "../Utility/Vec.h"
#include "../Lib/Input/Input.h"

namespace Collision
{
	CollisionManager::CollisionManager()
	{
		// 衝突の組み合わせを設定する
		m_CombinationList[CollisionGroup::PlacementObj].push_back(CollisionGroup::Mouse);
	}

	void CollisionManager::Update()
	{
		for (auto combination_a : m_CombinationList)
		{
			if (m_ColliderList.count(combination_a.first) == 0)
			{
				continue;
			}

			for (auto combination_b : m_CombinationList[combination_a.first])
			{
				if (m_ColliderList.count(combination_b) == 0)
				{
					continue;
				}

				// 二つのグループで当たり判定を開始する
				StartCollisionCombination(combination_a.first, combination_b);
			}
		}
	}

	void CollisionManager::StartCollisionCombination(CollisionGroup group_a, CollisionGroup group_b)
	{
		for (auto obj_a : m_ColliderList[group_a])
		{
			for (auto obj_b : m_ColliderList[group_b])
			{
				// 当たりの組み合わせを選択する
				SelectColliderCombination(obj_a, obj_b);
			}
		}
	}

	void CollisionManager::SelectColliderCombination(CollisionObject* obj_a, CollisionObject* obj_b)
	{
		ColliderType type_a = obj_a->GetColliderType();
		ColliderType type_b = obj_b->GetColliderType();

		switch (type_a)
		{
		case ColliderType::Rect:
			switch (type_b)
			{
			case ColliderType::Point:
				// 点と矩形の当たり
				RunCollisionPointAndRect(obj_b, obj_a);
				break;
			}
			break;
		case ColliderType::Point:
			switch (type_b)
			{
			case ColliderType::Rect:
				// 点と矩形の当たり
				RunCollisionPointAndRect(obj_a, obj_b);
				break;
			}
			break;
		}
	}

	void CollisionManager::RunCollisionPointAndRect(CollisionObject* point_a, CollisionObject* rect_b)
	{
		PointCollider point;
		RectCollider rect;

		point_a->GetColliderData(point);
		rect_b->GetColliderData(rect);

		// 回転無し
		if (rect.Degree == 0.0f)
		{
			// 矩形の中に点があれば当たり
			if (point.X >= rect.X && point.X <= (rect.X + rect.Width) &&
				point.Y >= rect.Y && point.Y <= (rect.Y + rect.Height))
			{
				// 反映
				point_a->ReflectCollision(rect_b);
				rect_b->ReflectCollision(point_a);
			}
		}
	}
}
