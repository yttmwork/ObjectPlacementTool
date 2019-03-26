#ifndef DIRECTX9_DEVICE_FACTORY_H_
#define DIRECTX9_DEVICE_FACTORY_H_

#include "GraphicsDeviceFactoryBase.h"
#include "DirectX9Graphics.h"

namespace Lib
{
	class DirectX9DeviceFactory : public GraphicsDeviceFactoryBase
	{
	public:
		/** @brief Constructor */
		DirectX9DeviceFactory() {}

		/** @brief Destructor */
		~DirectX9DeviceFactory() {}

		/**
		* @brief デイバス生成関数
		* 引き数で指定されたGraphicsDeviceを生成する
		* @return 生成されたGraphicsDeviceのポインタ(失敗はnullptr)
		*/
		virtual GraphicsDeviceBase* CreateDevice()
		{
			return new DirectX9Graphics();
		}
	};
}

#endif
