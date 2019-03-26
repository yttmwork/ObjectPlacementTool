#ifndef OBJECT_H_
#define OBJECT_H_

//=====================================================================//
//! オブジェクト基底クラス
//=====================================================================//
class Object
{
public:
	/**
	* @brief Constructor
	* @param[in] x 描画座標(X)
	* @param[in] y 描画座標(Y)
	* @param[in] z 描画座標(Z)
	*/
	Object(float x, float y, float z) :
		m_PosX(x),
		m_PosY(y),
		m_PosZ(z),
		m_Degree(0.0f),
		m_ScaleX(1.0f),
		m_ScaleY(1.0f),
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
