#ifndef COLLISION_RELATED_DEFINITIONS_H_
#define COLLISION_RELATED_DEFINITIONS_H_

namespace Collision
{
	// Colliderの種類
	enum ColliderType
	{
		Point,
		Rect,
		Circle,
	};

	// 衝突データグループ
	enum CollisionGroup
	{
		Mouse,
		PlacementObj,
	};
}

#endif
