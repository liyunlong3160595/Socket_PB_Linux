#include"DefineResouce.h"
#include"SocketPackage.h"
#include"PackAndUnpack.h"
#include"Person.pb.h"
using namespace tutorial;
int main()
{
	CSocketPackage SocketPackage;
	int iRet = SocketPackage.initall();
	if (iRet >0 || iRet == 0)
	{
		while (1)
		{
			char szBuff[1024];
			memset(szBuff, 0, 1024);
			SocketPackage.receiveBuff(szBuff);
			CCopHead copHead;
			char *buffBody = new char;
			UnPackHead(copHead, szBuff, buffBody);
			switch (copHead.cType)
			{
			case PersonType:
			{
				AddressBook  addressBookSend;
				bool bParse1 = addressBookSend.ParseFromArray((void*)(buffBody), strlen(buffBody));
				Person people1 = addressBookSend.people(0);
				if (copHead.ucStoreInqury == 1)
				{
					if (copHead.ucAddDelete == 1)
					{
						//�洢���ڴ���
					}
					else
					{

					}
				}
				else
				{
					char szSendBuff[1024];
					memset(szSendBuff, 0, 1024);

					//���Ӳ�ѯ������
					send(SocketPackage.iAccept, szSendBuff, strlen(szSendBuff), 0);
				}
				break;
			}
				
			default:
				break;
			}
			
		}
	}
	
}