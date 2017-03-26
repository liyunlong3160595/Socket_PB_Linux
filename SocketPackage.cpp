#include "SocketPackage.h"
#include"PackAndUnpack.h"

CSocketPackage::CSocketPackage()
{
}


CSocketPackage::~CSocketPackage()
{
}

int CSocketPackage::initall()
{
	int iRet = 0;
	//服务端初始化
	m_server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	int m_server_sockfd1 = socket(AF_INET, SOCK_STREAM, 0);
	//SOCKADDR_IN     servAddr;		//服务器地址  
	m_server_addr.sin_family = AF_INET;
	m_server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	m_server_addr.sin_port = htons(4000);
	if (bind(m_server_sockfd, (struct sockaddr *)&m_server_addr, sizeof(m_server_addr)) == -1)
	{
		perror("bind");
		exit(1);
	}

	///listen，成功返回0，出错返回-1
	if (listen(m_server_sockfd, QUEUE) == -1)
	{
		perror("listen");
		exit(1);
	}
	///客户端套接字
	 ///成功返回非负描述字，出错返回-1
	
	return iRet;
}
int CSocketPackage::receiveBuff(char*cBuffReceive)
{
	socklen_t length = sizeof(m_client_addr);
	m_iAccept = accept(m_server_sockfd, (struct sockaddr*)&m_client_addr, &length);
	if (m_iAccept < 0)
	{
		perror("accept");
		exit(1);
	}
	memset(m_cBuffReceive, 0, sizeof(m_cBuffReceive));
	int len = recv(m_iAccept, m_cBuffReceive, sizeof(m_cBuffReceive), 0);
	//UnPackHead(copHead, cBuffReceive, buffBody);
	//send(iAccept, cBuffReceive, len, 0);
}
