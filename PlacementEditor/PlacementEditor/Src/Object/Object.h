#ifndef OBJECT_H_
#define OBJECT_H_

struct CreateParamterBase;
struct SpriteObjectCreateParameter;

//=====================================================================//
//! オブジェクト基底クラス
//=====================================================================//
class Object
{
public:
	/**
	* @brief Constructor
	* @param[in] x X軸描画座標
	* @param[in] y Y軸描画座標
	* @param[in] z Z軸描画座標(初期値：0.0f)
	* @param[in] degree 回転角度(度数法 初期値：0.0f)
	* @param[in] scale_x X軸拡縮率(初期値：1.0f)
	* @param[in] scale_y Y軸拡縮率(初期値：1.0f)
	*/
	Object(float x, float y, float z, float degree = 0.0f, float scale_x = 1.0f, float scale_y = 1.0f) :
		m_PosX(x),
		m_PosY(y),
		m_PosZ(z),
		m_Degree(degree),
		m_ScaleX(scale_x),
		m_ScaleY(scale_y),
		m_IsDelete(false)
	{}

	/** Destructor */
	virtual ~Object() {}

	/**
	* ゲーム処理更新関数@n
	* 継承先で必ず実装させるために純粋仮想関数にする
	*/
	virtual void Update() = 0;

	/**
	* 描画関数@n
	* 継承先で必ず実装させるために純粋仮想関数にする
	*/
	virtual void Draw() = 0;

	/** 削除判定フラグのゲッター */
	virtual bool IsDelete()
	{
		return m_IsDelete;
	}

protected:
	float m_PosX;		//!< X座標
	float m_PosY;		//!< Y座標
	float m_PosZ;		//!< Z座標

	float m_ScaleX;		//!< 拡縮率X
	float m_ScaleY;		//!< 拡縮率Y

	float m_Degree;		//!< 回転角度

	bool m_IsDelete;	//!< 削除判定フラグ
};

#endif
