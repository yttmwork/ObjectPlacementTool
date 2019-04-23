#include <windowsx.h>
#include "SocketRelatedDefinitions.h"
#include "ServerSocket.h"
#include "../Lib/Window.h"
#include "../Editor/Editor.h"

bool ServerSocket::Start(int port_no)
{
	WORD version_request = MAKEWORD(1, 1);

	WSADATA wsa_data;

	int error = WSAStartup(version_request, &wsa_data);
	if (error != 0)
	{
		return false;
	}

	m_PortNo = port_no;
	m_ServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (m_ServerSocket == INVALID_SOCKET)
	{
		return false;
	}

	if (WSAAsyncSelect(
		m_ServerSocket,
		FindWindow(Lib::WindowClassName.c_str(), nullptr),
		WmAsync,
		FD_ACCEPT))
	{
		closesocket(m_ServerSocket);
		return false;
	}

	SOCKADDR_IN sock_addr;
	memset(&sock_addr, 0, sizeof(SOCKADDR_IN));
	sock_addr.sin_family = AF_INET;
	sock_addr.sin_port = htons(m_PortNo);
	sock_addr.sin_addr.s_addr = INADDR_ANY;

	if (bind(m_ServerSocket, (SOCKADDR*)&sock_addr, sizeof(SOCKADDR_IN)) ==
		SOCKET_ERROR)
	{
		closesocket(m_ServerSocket);
		return false;
	}

	if (listen(m_ServerSocket, 0) == SOCKET_ERROR)
	{
		closesocket(m_ServerSocket);
		return false;
	}

	return true;
}

bool ServerSocket::Accept()
{
	SOCKET socket;
	SOCKADDR sock_addr;
	int len = sizeof(SOCKADDR);

	memset(&sock_addr, 0, sizeof(SOCKADDR));

	socket = accept(m_ServerSocket, &sock_addr, &len);
	if (socket == INVALID_SOCKET)
	{
		MessageBox(FindWindow(Lib::WindowClassName.c_str(), nullptr),
			TEXT("通信許可をしませんでした"),
			TEXT("エラー"),
			MB_OK);
		return FALSE;
	}

	int ret = WSAAsyncSelect(
			socket,
			FindWindow(Lib::WindowClassName.c_str(), nullptr), 
			WmAsync,
			FD_CLOSE | FD_READ);

	if (ret != 0)
	{
		closesocket(socket);
		MessageBox(NULL,
			TEXT("通信用ソケットの非同期化を失敗しました"),
			TEXT("エラー"),
			MB_OK);
		return false;
	}

	// ソケットリストに追加
	m_ConnectSocket = socket;

	return true;
}

bool ServerSocket::Receive(SOCKET socket)
{
	char buff[1024];
	memset(buff, 0, sizeof(char) * 1024);

	if (socket != m_ConnectSocket)
	{
		return false;
	}

	int ret = recv(socket, buff, 1024, 0);
	if (ret == SOCKET_ERROR)
	{
		MessageBox(NULL,
			TEXT("データの受信に失敗しました"),
			TEXT("受信エラー"),
			MB_OK);
		return false;
	}

	// 受信データの反映はEditorで行う
	Editor::Instance()->Recive(buff);

	return true;
}

void ServerSocket::CleanUp()
{
	// 接続したソケットを解除する
	shutdown(m_ConnectSocket, SD_BOTH);
	closesocket(m_ConnectSocket);

	// サーバー用ソケットを閉じる
	if (m_ServerSocket != 0 && m_ServerSocket != INVALID_SOCKET)
	{
		// サーバーソケットを閉じる
		closesocket(m_ServerSocket);
	}
	WSACleanup();
}
