#include "../Lib/Graphics/Graphics.h"
#include "../Lib/Input/Input.h"
#include "../Collision/CollisionManager.h"
#include "PlacementObject.h"
#include "../Lib/Graphics/SpriteManager.h"
#include "../Editor/Editor.h"

PlacementObject::PlacementObject(PlacementObjectCreateParameter& parameter) :
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
	m_Type(parameter.Placement),
	m_IsSelect(false)
{
	static int CreateCount = 1;
	m_Id = CreateCount;
	CreateCount++;

	m_RectCollider.X = m_PosX;
	m_RectCollider.Y = m_PosY;
	m_RectCollider.Z = m_PosZ;
	m_RectCollider.Degree = m_Degree;

	Sprite* s = SpriteManager::Instance()->Find(m_SpriteName);
	if (s != nullptr)
	{
		Size size = s->GetSize();
		m_RectCollider.Width = size.Width;
		m_RectCollider.Height = size.Height;
	}
}


void PlacementObject::Update()
{
	Collision::CollisionManager::Instance()->Entry(Collision::CollisionGroup::PlacementObj, this);

	m_RectCollider.X = m_PosX;
	m_RectCollider.Y = m_PosY;
	m_RectCollider.Degree = m_Degree;

	if (m_IsSelect == false)
	{
		return;
	}

	if (Lib::Input::Instance()->OnMousePush(MouseKey::Left) == false)
	{
		m_IsSelect = false;
	}

	Vec2 vec = Lib::Input::Instance()->GetMouseMoveVec();
	m_PosX += vec.X;
	m_PosY += vec.Y;
}

void PlacementObject::Draw()
{
	Lib::Graphics::Instance()->Draw(m_SpriteName, m_PosX, m_PosY, m_PosZ, m_Degree);
}

void PlacementObject::ReflectCollision(CollisionObject* object)
{
	if (object->GetCollisionGroup() == Collision::CollisionGroup::Mouse)
	{
		if (Lib::Input::Instance()->OnMousePush(MouseKey::Left) == true &&
			Editor::Instance()->GetSeletObject() == nullptr)
		{
			m_IsSelect = true;
			Editor::Instance()->SetSelectObject(this);
		}
		else if (Lib::Input::Instance()->OnMouseUp(MouseKey::Right) == true)
		{
			m_IsDelete = true;
		}
	}
}

