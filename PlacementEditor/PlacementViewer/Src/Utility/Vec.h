#ifndef VEC_H_
#define VEC_H_

struct Vec2
{
	/** Constructor */
	Vec2()
	{
		X = 0.0f;
		Y = 0.0f;
	}

	/**
	* @brief Constructor
	* @param[in] x 横幅
	* @param[in] y 縦幅
	*/
	Vec2(float x, float y)
	{
		X = x;
		Y = y;
	}

	/**
	* @brief Constructor
	* @param[in] Vec2 コピー用Vec2データ
	*/
	Vec2(const Vec2& size)
	{
		this->X = size.X;
		this->Y = size.Y;
	}

	float X;	//!< X値
	float Y;	//!< Y値
};


#endif
