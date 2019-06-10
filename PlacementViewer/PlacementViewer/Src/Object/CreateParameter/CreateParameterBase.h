#ifndef CREATE_PARAMETER_BASE_H_
#define CREATE_PARAMETER_BASE_H_

class Object;
class SpriteObject;

//=====================================================================//
//! 生成用パラメータ構造体(基底)
//=====================================================================//
struct CreateParameterBase
{
	/**
	* @brief Constructor
	* @param[in] x X軸描画座標
	* @param[in] y Y軸描画座標
	* @param[in] z Z軸描画座標(初期値0.0f)
	* @param[in] degree 回転角度(度数法、初期値0.0f)
	* @param[in] scale_x X軸拡縮率(初期値1.0f)
	* @param[in] scale_y Y軸拡縮率(初期値1.0f)
	*/
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

private:
	/** @brief Constructor */
	CreateParameterBase() = delete;
};

#endif
