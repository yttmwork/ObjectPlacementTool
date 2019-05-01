#include <Windows.h>
#include "../Window.h"
#include "DirectInput.h"

namespace Lib
{
	bool DirectInput::Create()
	{
		if (CreateInterface() == false)
		{
			return false;
		}

		if (CreateMouseDevice() == false)
		{
			Release();
			return false;
		}

		ZeroMemory(&m_CurrentMouseState, sizeof(DIMOUSESTATE));
		ZeroMemory(&m_PrevMouseState, sizeof(DIMOUSESTATE));

		return true;
	}

	void DirectInput::Release()
	{
		if (m_MouseDevice != nullptr)
		{
			m_MouseDevice->Release();
			m_MouseDevice = nullptr;
		}

		if (m_InputInterface != nullptr)
		{
			m_InputInterface->Release();
			m_InputInterface = nullptr;
		}
	}

	void DirectInput::Update()
	{
		m_PrevMouseState = m_CurrentMouseState;

		// マウスの状態を取得します
		HRESULT	hr = m_MouseDevice->GetDeviceState(sizeof(DIMOUSESTATE), &m_CurrentMouseState);
		if (FAILED(hr))
		{
			m_MouseDevice->Acquire();
			hr = m_MouseDevice->GetDeviceState(sizeof(DIMOUSESTATE), &m_CurrentMouseState);
		}
	}

	bool DirectInput::OnMouseDown(MouseKey key_type)
	{
		if (!(m_PrevMouseState.rgbButtons[key_type] & 0x80) &&
			m_CurrentMouseState.rgbButtons[key_type] & 0x80 )
		{
			return true;
		}

		return false;
	}

	bool DirectInput::OnMousePush(MouseKey key_type)
	{
		if (m_PrevMouseState.rgbButtons[key_type] & 0x80 &&
			m_CurrentMouseState.rgbButtons[key_type] & 0x80)
		{
			return true;
		}

		return false;
	}

	bool DirectInput::OnMouseUp(MouseKey key_type)
	{
		if (m_PrevMouseState.rgbButtons[key_type] & 0x80 &&
			!(m_CurrentMouseState.rgbButtons[key_type] & 0x80))
		{
			return true;
		}

		return false;
	}

	bool DirectInput::CreateInterface()
	{
		HRESULT ret = DirectInput8Create(GetModuleHandle(nullptr), DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&m_InputInterface, nullptr);
		if (FAILED(ret))
		{
			return false;	// 作成に失敗
		}

		return true;
	}

	bool DirectInput::CreateMouseDevice()
	{
		// マウス用にデバイスオブジェクトを作成
		if (FAILED(m_InputInterface->CreateDevice(GUID_SysMouse, &m_MouseDevice, nullptr))) 
		{
			// デバイスの作成に失敗
			return false;
		}

		// データフォーマットを設定
		if (FAILED(m_MouseDevice->SetDataFormat(&c_dfDIMouse))) 
		{
			// データフォーマットに失敗
			return false;
		}

		// モードを設定（フォアグラウンド＆非排他モード）
		if (FAILED(m_MouseDevice->SetCooperativeLevel(
							FindWindow(Lib::WindowClassName.c_str(), nullptr),
							DISCL_NONEXCLUSIVE | DISCL_FOREGROUND)))
		{
			// モードの設定に失敗
			return false;
		}

		// デバイスの設定
		DIPROPDWORD diprop;
		diprop.diph.dwSize = sizeof(diprop);
		diprop.diph.dwHeaderSize = sizeof(diprop.diph);
		diprop.diph.dwObj = 0;
		diprop.diph.dwHow = DIPH_DEVICE;
		diprop.dwData = DIPROPAXISMODE_REL;	// 相対値モードで設定（絶対値はDIPROPAXISMODE_ABS）

		if (FAILED(m_MouseDevice->SetProperty(DIPROP_AXISMODE, &diprop.diph)))
		{
			// デバイスの設定に失敗
			return false;
		}

		// 入力制御開始
		m_MouseDevice->Acquire();

		return true;
	}
}
