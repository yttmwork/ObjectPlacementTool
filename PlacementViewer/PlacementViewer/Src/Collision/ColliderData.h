#ifndef COLLIDER_DATA_H_
#define COLLIDER_DATA_H_

#include "../Object/Object.h"
#include "CollisionRelatedDefinitions.h"

namespace Collision
{
	struct RectCollider;
	struct CircleCollider;

	struct ColliderBase
	{
		ColliderBase()
		{
			X = 0.0f;
			Y = 0.0f;
			Z = 0.0f;
		}

		ColliderBase(const ColliderBase& data)
		{
			this->X = data.X;
			this->Y = data.Y;
			this->Z = data.Z;
		}

		ColliderBase(float x, float y, float z = 0.0f) :
			X(x),
			Y(y),
			Z(z)
		{
		}

		virtual ColliderType GetColliderType() = 0;

		float X;
		float Y;
		float Z;
	};

	struct PointCollider : public ColliderBase
	{
		virtual ColliderType GetColliderType()
		{
			return ColliderType::Point;
		}
	};

	struct RectCollider : public ColliderBase
	{
		RectCollider()
		{
		}

		RectCollider(const ColliderBase& data)
		{
			this->X = data.X;
			this->Y = data.Y;
			this->Z = data.Z;
		}

		RectCollider(float x, float y, float z, float width, float height, float degree = 0.0f) :
			ColliderBase(x, y, z),
			Width(width),
			Height(height),
			Degree(degree)
		{
		}

		virtual ColliderType GetColliderType()
		{
			return ColliderType::Rect;
		}

		float Width;
		float Height;
		float Degree;
	};

	struct CircleCollider : public ColliderBase
	{
		CircleCollider()
		{
		}

		CircleCollider(const CircleCollider& data) :
			ColliderBase(data.X, data.Y, data.Z),
			Radius(data.Radius)
		{
		}

		CircleCollider(float x, float y, float radius) :
			ColliderBase(x, y),
			Radius(radius)
		{
		}

		virtual void GetColliderData(CircleCollider& out)
		{
			out = *this;
		}

		float Radius;
	};
}

#endif
