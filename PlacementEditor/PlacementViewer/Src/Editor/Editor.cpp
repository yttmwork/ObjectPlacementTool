#include "Editor.h"
#include "../Socket/SocketRelatedDefinitions.h"

void Editor::Recive(char buffer[1024])
{
	/*
		受信データは頭の４バイトがコマンドID
		残りがコマンドIDで必要なデータ
	*/
	int command = 0;
	memcpy(&command, buffer, sizeof(int));

	switch (command)
	{
	case CommunicationCommand::OutPut:

		break;
	case CommunicationCommand::SelectSprite:
		m_SelectSpriteName = &buffer[sizeof(int)];
		break;
	}
}
