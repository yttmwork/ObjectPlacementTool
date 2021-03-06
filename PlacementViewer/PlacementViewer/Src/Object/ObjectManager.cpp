﻿#include "ObjectManager.h"

void ObjectManager::AddToRegistration(Object* obj)
{
	if (obj == nullptr)
	{
		return;
	}

	m_RegisterList.push_back(obj);
}

void ObjectManager::Register()
{
	for (auto obj : m_RegisterList)
	{
		m_ObjectList.push_back(obj);
	}

	m_RegisterList.clear();
}


void ObjectManager::Update()
{
	for (auto& object : m_ObjectList)
	{
		object->Update();
	}
}

void ObjectManager::Draw()
{
	for (auto& object : m_ObjectList)
	{
		if (object->IsDelete() == true)
		{
			continue;
		}
		object->Draw();
	}
}

void ObjectManager::Delete()
{
	for (auto itr = m_ObjectList.begin(); itr != m_ObjectList.end();)
	{
		if ((*itr)->IsDelete())
		{
			Object *obj = *itr;
			if (obj != nullptr)
			{
				delete(obj);
			}
			itr = m_ObjectList.erase(itr);
			continue;
		}
		itr++;
	}
}

void ObjectManager::AllDelete()
{
	for (auto itr = m_ObjectList.begin(); itr != m_ObjectList.end(); itr++)
	{
		if ((*itr)->IsDelete())
		{
			Object *obj = *itr;
			if (obj != nullptr)
			{
				delete(obj);
			}
		}
	}
	m_ObjectList.clear();
}
