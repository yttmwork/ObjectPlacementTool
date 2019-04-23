#ifndef COLLISION_MANAGER_H_
#define COLLISION_MANAGER_H_

#include <map>
#include <vector>
#include "../Object/CollisionObject.h"
#include "CollisionRelatedDefinitions.h"

namespace Collision
{
	class CollisionManager
	{
	public:
		static CollisionManager* Instance()
		{
			static CollisionManager instance;
			return &instance;
		}

		void Entry(CollisionGroup group, CollisionObject* obj)
		{
			if (obj == nullptr)
			{
				return;
			}

			m_ColliderList[group].push_back(obj);
		}

		void Clear()
		{
			m_ColliderList.clear();
		}

		void Update();

	private:
		CollisionManager();
		void StartCollisionCombination(CollisionGroup group_a, CollisionGroup group_b);
		void SelectCollisionTypeCombination(CollisionObject* obj_a, CollisionObject* obj_b);

		void RunCollisionPointAndRect(CollisionObject* point_a, CollisionObject* rect_b);
	private:
		std::map<CollisionGroup, std::vector<CollisionObject*>> m_ColliderList;
		std::map<CollisionGroup, std::vector<CollisionGroup>> m_CombinationList;
	};
}

#endif
