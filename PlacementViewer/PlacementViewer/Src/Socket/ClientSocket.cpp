#include <windowsx.h>
#include "SocketRelatedDefinitions.h"
#include "ClientSocket.h"
#include "../Lib/Window.h"
#include "../Editor/Editor.h"

bool ClientSocket::Start(int port_no)
{
	WORD version_request = MAKEWORD(1, 1);

	WSADATA wsa_data;

	int error = WSAStartup(version_request, &wsa_data);
	if (error != 0)
	{
		return false;
	}

	m_PortNo = port_no;
	m_Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (m_Socket == INVALID_SOCKET)
	{
		return false;
	}

	// URLからホスト情報取得
	WSAAsyncGetHostByName(
		FindWindow(Lib::WindowClassName.c_str(), nullptr),
		WmServerByName,
		"localhost",
		(char *)m_HostInfoBuff,
		HostInfoBuffSize);

	return true;
}

bool ClientSocket::Connect()
{
	LPHOSTENT phost = NULL;
	unsigned int addr;
	SOCKADDR_IN sock_addr;

	// サーバーへ接続するための準備
	phost = (LPHOSTENT)m_HostInfoBuff;

	memset(&sock_addr, 0, sizeof(SOCKADDR_IN));
	if (phost->h_name != nullptr &&
		phost->h_addr_list != nullptr)
	{
		sock_addr.sin_family = AF_INET;
		sock_addr.sin_port = htons(m_PortNo);
		sock_addr.sin_addr.s_addr = *((unsigned long*)phost->h_addr);
	}

	// クライアントソケットをサーバーのソケットに接続する
	if (connect(m_Socket, (SOCKADDR*)&sock_addr, sizeof(sock_addr)) == SOCKET_ERROR)
	{
		return false;
	}

	if (WSAAsyncSelect(
		m_Socket,
		FindWindow(Lib::WindowClassName.c_str(), nullptr),
		WmAsync,
		FD_CONNECT | FD_READ | FD_CLOSE))
	{
		closesocket(m_Socket);
		return false;
	}

	return true;
}

bool ClientSocket::Receive(SOCKET socket)
{
	char buff[1024];
	memset(buff, 0, sizeof(char) * 1024);

	if (socket != m_Socket)
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

void ClientSocket::CleanUp()
{
	// 接続したソケットを解除する
	shutdown(m_Socket, SD_BOTH);

	// サーバー用ソケットを閉じる
	if (m_Socket != 0 && m_Socket != INVALID_SOCKET)
	{
		// サーバーソケットを閉じる
		closesocket(m_Socket);
	}
	WSACleanup();
}
