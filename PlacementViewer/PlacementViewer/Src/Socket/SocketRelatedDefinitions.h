﻿#ifndef SOCKET_RELATED_DEFINITIONS_H_
#define SOCKET_RELATED_DEFINITIONS_H_

#define WIN32_LEAN_AND_MEAN
#include <WinSock2.h>

//!< 通信コマンド
enum CommunicationCommand
{
	OutPut = 1,		//!< 出力
	SelectSprite,	//!< 選択中のスプライト
};

const UINT WmAsync = (WM_USER + 1);				//!< 通信通知用ID
const UINT WmServerByName = (WM_USER + 2);
const UINT WmServerByAddress = (WM_USER + 3);
const UINT HostInfoBuffSize = 256;

#endif