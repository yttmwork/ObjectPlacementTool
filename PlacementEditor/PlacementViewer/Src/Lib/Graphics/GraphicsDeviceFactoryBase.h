#ifndef GRAPHICS_DEVICE_FACTORY_BASE_H_
#define GRAPHICS_DEVICE_FACTORY_BASE_H_

#include "GraphicsRelatedDefinitions.h"
#include "GraphicsDeviceBase.h"

namespace Lib
{
	//=============================================================
	//! GraphicsDeviceを生成するためのFactoryクラス
	//=============================================================
	class GraphicsDeviceFactoryBase
	{
	public:
		/** @brief Constructor */
		GraphicsDeviceFactoryBase() {}

		/** @brief Destructor */
		~GraphicsDeviceFactoryBase() {}

		/**
		* @brief デイバス生成関数
		* 引き数で指定されたGraphicsDeviceを生成する
		* @return 生成されたGraphicsDeviceのポインタ(失敗はnullptr)
		*/
		virtual GraphicsDeviceBase* CreateDevice() = 0;
	};
}

#endif
