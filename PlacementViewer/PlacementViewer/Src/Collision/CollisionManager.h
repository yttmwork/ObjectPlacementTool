#ifndef COLLISION_MANAGER_H_
#define COLLISION_MANAGER_H_

#include <map>
#include <vector>
#include "../Object/CollisionObject.h"
#include "CollisionRelatedDefinitions.h"

namespace Collision
{
	//=====================================================================//
	//! 当たり判定管理
	//=====================================================================//
	class CollisionManager
	{
	public:
		/** @brief Instanceのゲッター */
		static CollisionManager* Instance()
		{
			static CollisionManager instance;
			return &instance;
		}

		/**
		* @brief 登録関数@n
		* 引数のオブジェクトをリストに登録する
		* @param[in] group 登録する衝突グループ
		* @param[in] group 登録するオブジェクト
		*/
		void Entry(CollisionGroup group, CollisionObject* obj)
		{
			if (obj == nullptr)
			{
				return;
			}

			m_ColliderList[group].push_back(obj);
		}

		/**
		* リストクリア関数@n
		* 衝突リストをリセットする
		*/
		void Clear()
		{
			m_ColliderList.clear();
		}

		/**
		* 更新関数@n
		* m_ColliderListに登録されているオブジェクトで@n
		* 衝突処理を実行する
		*/
		void Update();

	private:
		/** @brief Constructor */
		CollisionManager();

		/**
		* グループ同士の衝突開始関数@n
		* 二つのグループで衝突を開始する
		* @param[in] group_a 衝突グループA
		* @param[in] group_b 衝突グループB
		*/
		void StartCollisionCombination(CollisionGroup group_a, CollisionGroup group_b);

		/**
		* Colliderの組み合わせ選択関数@n
		* 二つのColliderの種類による組み合わせを選択する
		* @param[in] obj_a ColliderA
		* @param[in] obj_b ColliderB
		*/
		void SelectColliderCombination(CollisionObject* obj_a, CollisionObject* obj_b);

		/**
		* 点と矩形の衝突実行関数@n
		* 二つのColliderで点と矩形の当たり判定を行う
		* @param[in] obj_a ColliderA
		* @param[in] obj_b ColliderB
		*/
		void RunCollisionPointAndRect(CollisionObject* point_a, CollisionObject* rect_b);
	private:
		std::map<CollisionGroup, std::vector<CollisionObject*>> m_ColliderList;		//!< Colliderリスト
		std::map<CollisionGroup, std::vector<CollisionGroup>> m_CombinationList;	//!< 組み合わせリスト
	};
}

#endif
