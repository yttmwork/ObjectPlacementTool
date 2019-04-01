#ifndef SPRITE_OBJECT_CREATE_PARAMETER_H_
#define SPRITE_OBJECT_CREATE_PARAMETER_H_

#include <string>
#include "CreateParameterBase.h"
#include "../SpriteObject.h"

//=====================================================================//
//! SpriteObject用パラメータ構造体
//=====================================================================//
struct SpriteObjectCreateParameter : public CreateParameterBase
{
	/**
	* @brief Constructor
	* @param[in] sprite_name 描画予定のスプライト名
	* @param[in] x X軸描画座標
	* @param[in] y Y軸描画座標
	* @param[in] z Z軸描画座標(初期値1.0f)
	* @param[in] degree 回転角度(度数法、初期値0.0f)
	* @param[in] scale_x X軸拡縮率(初期値1.0f)
	* @param[in] scale_y Y軸拡縮率(初期値1.0f)
	*/
	SpriteObjectCreateParameter(std::string sprite_name, float x, float y, float z = 0.0f, float degree = 0.0f, float scale_x = 1.0f, float scale_y = 1.0f) :
		CreateParameterBase(x, y, z, degree, scale_x, scale_y),
		SpriteName(sprite_name)
	{
	}

	std::string SpriteName;	//!< スプライト名
private:
	/** Constructor */
	SpriteObjectCreateParameter() = delete;
};

#endif
