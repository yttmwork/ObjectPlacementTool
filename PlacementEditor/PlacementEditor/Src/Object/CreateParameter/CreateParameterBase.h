#ifndef CREATE_PARAMETER_BASE_H_
#define CREATE_PARAMETER_BASE_H_

class Object;
class SpriteObject;

//=====================================================================//
//! 生成用パラメータ構造体(基底)
//=====================================================================//
struct CreateParameterBase
{
	CreateParameterBase(float x, float y, float z = 0.0f, float degree = 0.0f, float scale_x = 1.0f, float scale_y = 1.0f) :
		PosX(x),
		PosY(y),
		PosZ(z),
		Degree(degree),
		ScaleX(scale_x),
		ScaleY(scale_y)
	{
	}

	float PosX;		//!< X座標
	float PosY;		//!< Y座標
	float PosZ;		//!< Z座標

	float Degree;	//!< 角度(度数)

	float ScaleX;	//!< X軸拡縮率
	float ScaleY;	//!< Y軸拡縮率
};

#endif
