#pragma once
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include"DefineResouce.h"
class CSocketPackage
{
public:
	//int		client_sockfd;			 //�ͻ���ocket������
	int		m_server_sockfd;          //������socket������
	int		 m_iAccept;
	struct  sockaddr_in  m_server_addr;		//��������ַ
	struct sockaddr_in m_client_addr;//�ͻ��˵�ַ
	char m_cBuffSend[BUF_SIZE];
	char m_cBuffReceive[BUF_SIZE];
	int initall();
	//int sendBuff(char*);
	int receiveBuff(char*);
	CSocketPackage();
	~CSocketPackage();
};

