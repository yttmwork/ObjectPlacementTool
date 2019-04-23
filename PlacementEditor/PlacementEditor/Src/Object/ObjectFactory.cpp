#include "ObjectFactory.h"
#include "ObjectManager.h"

SpriteObject* ObjectFactory::CreateSprite(SpriteObjectCreateParameter& parameter, bool is_register)
{
	SpriteObject *obj = new SpriteObject(parameter);

	if (is_register == true)
	{
		ObjectManager::Instance()->AddToRegistration(obj);
	}

	return obj;
}

PlacementObject* ObjectFactory::CreatePlacement(PlacementObjectCreateParameter& parameter, bool is_register)
{
	PlacementObject *obj = new PlacementObject(parameter);

	if (is_register == true)
	{
		ObjectManager::Instance()->AddToRegistration(obj);
	}

	return obj;
}

MouseObject* ObjectFactory::CreateMouse(CollisionObjectCreateParameter& parameter, bool is_register)
{
	MouseObject *obj = new MouseObject(parameter);

	if (is_register == true)
	{
		ObjectManager::Instance()->AddToRegistration(obj);
	}

	return obj;
}

