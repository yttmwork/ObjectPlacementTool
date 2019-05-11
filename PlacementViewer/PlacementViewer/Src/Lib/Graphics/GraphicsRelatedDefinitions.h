#ifndef GRAPHICS_RELATED_DEFINITIONS_H_
#define GRAPHICS_RELATED_DEFINITIONS_H_

#define GRAPHICS_DEVICE_TYPE_DIRECTX9 (0x01)

#define GRAPHICS_DEVICE_TYPE (GRAPHICS_DEVICE_TYPE_DIRECTX9)

#include <d3d9.h>

namespace Lib
{
	//========================================
	//! 2D用頂点構造
	//========================================
	struct CustomVertex2D
	{
		float m_X;		//!< X座標
		float m_Y;		//!< Y座標
		float m_Z;		//!< Z座標
		float m_Rhw;	//!< 除算数

		DWORD m_Color;	//!< 頂点カラー

		float m_Tu;		//!< TextureX座標
		float m_Tv;		//!< TextureY座標
	};

#if GRAPHICS_DEVICE_TYPE == GRAPHICS_DEVICE_TYPE_DIRECTX9
	const DWORD Vertex2DFVF = D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1;	//!< 頂点宣言
#endif
}

#endif
