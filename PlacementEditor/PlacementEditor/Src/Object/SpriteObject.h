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
