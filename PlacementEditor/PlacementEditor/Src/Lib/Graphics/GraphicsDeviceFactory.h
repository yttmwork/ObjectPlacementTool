#ifndef GRAPHICS_DEVICE_FACTORY_H_
#define GRAPHICS_DEVICE_FACTORY_H_

#include "GraphicsRelatedDefinitions.h"
#include "GraphicsDeviceBase.h"

namespace Lib
{
	//=============================================================
	//! GraphicsDeviceを生成するためのFactoryクラス
	//=============================================================
	class GraphicsDeviceFactory
	{
	public:
		/** @brief Constructor */
		GraphicsDeviceFactory() {}

		/** @brief Destructor */
		~GraphicsDeviceFactory() {}

		/**
		* @brief デイバス生成関数
		* 引き数で指定されたGraphicsDeviceを生成する
		* @return 生成されたGraphicsDeviceのポインタ(失敗はnullptr)
		*/
		GraphicsDeviceBase* CreateDevice(GraphicsDevice create_device);
	};
}

#endif
