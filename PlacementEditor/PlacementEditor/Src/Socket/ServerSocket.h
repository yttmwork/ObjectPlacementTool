#ifndef SERVER_SOCKET_H_
#define SERVER_SOCKET_H_

#define WIN32_LEAN_AND_MEAN
#include <WinSock2.h>

#pragma comment (lib, "Ws2_32.lib")

//=====================================================================//
//! ソケットクラス
//=====================================================================//
class ServerSocket
{
public:
	/**
	* @brief インスタンスのゲッター@n
	* Graphicsはシングルトンとして使用するので@n
	* 必ずこのメソッドを通して、他のメンバにアクセスすること
	* @return インスタンスのポインタ
	*/
	static ServerSocket* Instance()
	{
		static ServerSocket instance;

		return &instance;
	}

	/**
	* @brief ソケット開始@n
	* ソケット通信を開始する
	* @return 開始結果(成功はtrue)
	* @param[in] port_no ソケットに設定するポート番号
	*/
	bool Start(int port_no);

	/**
	* @brief ソケット許可関数@n
	* クライアントとの通信を許可する
	* @return クライアントとの通信許可の成否(成功はtrue)
	*/
	bool Accept();

	/**
	* @brief 受信関数@n
	* クライアントからのデータを受信する
	* @param[in] socket 送信してきたソケット
	*/
	bool Receive(SOCKET socket);

	/**
	* @brief 終了関数@n
	* ソケットを閉じて通信を終了する
	*/
	void CleanUp();

private:
	/**
	* @brief Constructor@n
	* シングルトンとして使用するのでコンストラクタは@n
	* メンバの初期化だけを行うようにする@n
	* privateなのはインスタンス化阻止対応
	*/
	ServerSocket() {}

private:
	int m_PortNo;				//!< ポート番号
	SOCKET m_ServerSocket;		//!< サーバー用ソケット
	SOCKET m_ConnectSocket;		//!< 接続側ソケット
};

#endif
