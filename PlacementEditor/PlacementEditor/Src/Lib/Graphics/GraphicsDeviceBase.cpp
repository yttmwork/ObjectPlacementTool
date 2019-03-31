#include <d3d9.h>
#include <d3dx9.h>
#include "GraphicsDeviceBase.h"

namespace Lib
{
	void GraphicsDeviceBase::VertexTransform(CustomVertex2D vertex_list[4], float degree, float scale_x, float scale_y)
	{
		float width_half = (vertex_list[1].m_X - vertex_list[0].m_X) / 2.0f;
		float height_half = (vertex_list[2].m_Y - vertex_list[0].m_Y) / 2.0f;

		width_half *= scale_x;
		height_half *= scale_y;

		float pos_x = vertex_list[0].m_X;
		float pos_y = vertex_list[0].m_Y;

		float sin = sinf(D3DXToRadian(degree));
		float cos = cosf(D3DXToRadian(degree));

		float vertex_pos_x = 0.0f;
		float vertex_pos_y = 0.0f;

		for (int i = 0; i < 4; i++)
		{
			vertex_pos_x = (i % 3 == 0) ? -width_half : width_half;
			vertex_pos_y = (i < 2) ? -height_half : height_half;

			vertex_pos_x *= scale_x;
			vertex_pos_y *= scale_y;

			float new_x = (vertex_pos_x * cos) + (vertex_pos_y * -sin);
			float new_y = (vertex_pos_x * sin) + (vertex_pos_y * cos);

			vertex_list[i].m_X = new_x + pos_x + width_half;
			vertex_list[i].m_Y = new_y + pos_y + height_half;
		}
	}
}