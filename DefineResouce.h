#pragma once
#define BUF_SIZE 1024
#define SERVE_IP 192.168.1.100
#define CLIENT_IP 192.168.1.104
#define SERVE_RECEIVE_PORT 4000
#define CLIENT_RECEIVE_PORT 4000
#define QUEUE   20

#define PersonType 1

#include"DefineResouce.h"
//#include "spdlog/spdlog.h"
//namespace spd = spdlog;
class CCopHead
{
public:
	unsigned char ucStoreInqury;  //1�洢��2��ѯ
	unsigned char ucAddDelete;//1���ӣ�2ɾ��
	char cType;
};
//extern std::shared_ptr<spd::logger> g_MyLogger;