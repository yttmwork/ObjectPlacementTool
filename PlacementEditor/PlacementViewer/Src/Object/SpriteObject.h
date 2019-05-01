#ifndef SPRITE_OBJECT_H_
#define SPRITE_OBJECT_H_

#include <string>
#include "Object.h"
#include "CreateParameter/SpriteObjectCreateParameter.h"

//=====================================================================//
//! Sprite描画用オブジェクトクラス
//=====================================================================//
class SpriteObject : public Object
{
public:
	/**
	* @brief Constructor
	* @param[in] parameter 初期化用パラメータデータ
	*/
	SpriteObject(SpriteObjectCreateParameter& parameter);

	/**
	* @brief Constructor
	* @param[in] sprite_name スプライト名
	* @param[in] x X軸描画座標
	* @param[in] y Y軸描画座標
	* @param[in] z Z軸描画座標(初期値：0.0f)
	* @param[in] degree 回転角度(度数法 初期値：0.0f)
	* @param[in] scale_x X軸拡縮率(初期値：1.0f)
	* @param[in] scale_y Y軸拡縮率(初期値：1.0f)
	*/
	SpriteObject(std::string sprite_name, float x, float y, float z = 0.0f, float degree = 0.0f, float scale_x = 1.0f, float scale_y = 1.0f) :
		Object(x, y, z, degree, scale_x, scale_y),
		m_SpriteName(sprite_name)
	{}

	/** @brief Destructor */
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
