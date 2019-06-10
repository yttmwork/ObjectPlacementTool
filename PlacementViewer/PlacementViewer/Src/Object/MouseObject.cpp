#include <string>
#include <map>
#include "../Lib/Input/Input.h"
#include "MouseObject.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"
#include "../Editor/Editor.h"
#include "../Collision/CollisionManager.h"

void MouseObject::Update()
{
	Vec2 pos = Lib::Input::Instance()->GetMousePos();
	m_PointCollider.X = m_PosX = pos.X;
	m_PointCollider.Y = m_PosY = pos.Y;
	
	Collision::CollisionManager::Instance()->Entry(Collision::CollisionGroup::Mouse, this);

	if (Lib::Input::Instance()->OnMouseDown(MouseKey::Left))
	{
		m_ClickPos = pos;
	}

	if (Lib::Input::Instance()->OnMouseUp(MouseKey::Left))
	{
		Editor::Instance()->SetDragObject(nullptr);

		float distance = sqrt((pos.X - m_ClickPos.X) * (pos.X - m_ClickPos.X) * (pos.Y - m_ClickPos.Y) * (pos.Y - m_ClickPos.Y));

		if (distance <= 3.0f && m_OnObject == false)
		{
			std::string sprite_name = Editor::Instance()->GetSelectSpriteName();
			std::map<std::string, PlacementType> list = 
			{
				{ "Object01", PlacementType::Obj01 },
				{ "Object02", PlacementType::Obj02 },
				{ "Object03", PlacementType::Obj03 },
				{ "Object04", PlacementType::Obj04 },
				{ "Object05", PlacementType::Obj05 },
			};

			PlacementObjectCreateParameter placement_list =
			{
				list[sprite_name], Collision::CollisionGroup::PlacementObj, sprite_name, pos.X, pos.Y
			};
			ObjectFactory::CreatePlacement(placement_list);
		}
	}

	m_OnObject = false;
}

void MouseObject::ReflectCollision(CollisionObject* object)
{
	if (object->GetCollisionGroup() == Collision::CollisionGroup::PlacementObj)
	{
		m_OnObject = true;
	}
}


