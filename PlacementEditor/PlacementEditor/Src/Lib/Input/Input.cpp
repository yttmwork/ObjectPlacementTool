#include <Windows.h>
#include "Input.h"
#include "../Window.h"

namespace Lib
{
	bool Input::Initialize()
	{
		m_InputDevice = new DirectInput();
		if (m_InputDevice->Create() == false)
		{
			return false;
		}

		return true;
	}

	void Input::Release()
	{
		delete m_InputDevice;
		m_InputDevice = nullptr;
	}

	void Input::Update()
	{
		MouseUpdate();
		m_InputDevice->Update();
	}

	bool Input::OnMouseDown(MouseKey key_type)
	{
		return m_InputDevice->OnMouseDown(key_type);
	}

	bool Input::OnMousePush(MouseKey key_type)
	{
		return m_InputDevice->OnMousePush(key_type);
	}

	bool Input::OnMouseUp(MouseKey key_type)
	{
		return m_InputDevice->OnMouseUp(key_type);
	}

	void Input::MouseUpdate()
	{
		Vec2 prev = m_MousePos;
		POINT p;
		GetCursorPos(&p);
		ScreenToClient(FindWindow(Lib::WindowClassName.c_str(), nullptr), &p);

		m_MousePos.X = p.x;
		m_MousePos.Y = p.y;

		m_MouseVec.X = m_MousePos.X - prev.X;
		m_MouseVec.Y = m_MousePos.Y - prev.Y;
	}
}
