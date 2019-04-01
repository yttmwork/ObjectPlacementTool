#include "ObjectFactory.h"
#include "ObjectManager.h"
#include "SpriteObject.h"

SpriteObject* ObjectFactory::CreateSprite(SpriteObjectCreateParameter& parameter, bool is_register)
{
	SpriteObject *obj = new SpriteObject(parameter);

	if (is_register == true)
	{
		ObjectManager::Instance()->Register(obj);
	}

	return obj;
}
