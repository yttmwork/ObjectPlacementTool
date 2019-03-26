#ifndef SPRITE_OBJECT_H_
#define SPRITE_OBJECT_H_

#include <string>
#include "Object.h"

//=====================================================================//
//! Sprite描画用オブジェクトクラス
//=====================================================================//
class SpriteObject : public Object
{
public:
	/**
	* @brief Constructor
	* @param[in] sprite_name 描画予定のスプライト名
	* @param[in] x 描画座標(X)
	* @param[in] y 描画座標(Y)
	* @param[in] z 描画座標(Z)
	*/
	SpriteObject(std::string sprite_name, float x, float y, float z) :
		Object(x, y, z),
		m_SpriteName(sprite_name)
	{
	}

	/** Destructor */
	virtual ~SpriteObject()
	{}

	/**
	* @brief ゲーム処理更新関数
	* ゲーム処理を更新する
	*/
	virtual void Update() override;

	/**
	* @brief 描画関数
	* メンバで所持しているスプライトを描画する
	*/
	virtual void Draw() override;
protected:
	std::string m_SpriteName;	//!< 描画予定スプライト名
};

#endif
