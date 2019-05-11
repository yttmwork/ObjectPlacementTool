#ifndef MOUSE_OBJECT_H_
#define MOUSE_OBJECT_H_

#include "../Utility/Vec.h"
#include "CollisionObject.h"
#include "ObjectRelatedDefinitions.h"

//=====================================================================//
//! �}�E�X�I�u�W�F�N�g�N���X
//=====================================================================//
class MouseObject : public CollisionObject
{
public:
	/**
	* @brief Constructor@n
	* Mouse�͐������ɐV�����ǉ������񂪂Ȃ��̂ŁA@n
	* CollisionObjectCreateParameter���g�p���Ă�
	* @param[in] parameter CollisionObject�����f�[�^
	*/
	MouseObject(CollisionObjectCreateParameter& parameter) :
		CollisionObject(
			parameter.Group,
			parameter.SpriteName,
			parameter.PosX,
			parameter.PosY,
			parameter.PosZ,
			parameter.Degree,
			parameter.ScaleX,
			parameter.ScaleY
		),
		m_ClickPos(Vec2(0.0f, 0.0f)),
		m_OnObject(false)
	{
		m_PointCollider.X = m_PosX;
		m_PointCollider.Y = m_PosY;
	}

	/** @brief Destructor */
	virtual ~MouseObject() {}

	/**
	* @brief �X�V�֐�@n
	* �}�E�X�Ŗ��t���[���s����������������
	*/
	virtual void Update();

	/**
	* @brief �`��֐�@n
	* �}�E�X�͕`����s��Ȃ��̂ŁA��֐��Ƃ��Ď���
	*/
	virtual void Draw() {}

	/**
	* @brief �����蔽�f�֐�@n
	* �����̃I�u�W�F�N�g���g�p���ē�����̔��f�������s��
	* @param[in] object ������������
	*/
	virtual void ReflectCollision(CollisionObject* object);

	/** @brief ������O���[�v�̃Q�b�^�[ */
	virtual Collision::CollisionGroup GetCollisionGroup()
	{
		return Collision::CollisionGroup::Mouse;
	}

	/** @brief ������`��̃Q�b�^�[ */
	virtual Collision::ColliderType GetColliderType()
	{
		return m_PointCollider.GetColliderType();
	}

	/** @brief ������f�[�^�̃Q�b�^�[ */ 
	virtual void GetColliderData(Collision::PointCollider& out)
	{
		out = m_PointCollider;
	}

private:
	Collision::PointCollider m_PointCollider;	//!< �|�C���g������f�[�^
	Vec2 m_ClickPos;							//!< �N���b�N���W
	bool m_OnObject;							//!< �I�u�W�F�N�g�㔻��t���E
};

#endif
