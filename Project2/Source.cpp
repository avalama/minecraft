/*#include<iostream>
#include<WinSock2.h>
#include<WS2tcpip.h>
#include<tchar.h>
#pragma comment(lib,"ws2_32.lib")//winsock libary
using namespace std;
int main()
{
	WSADATA wsaData;
	int wsaerr;
	WORD wVersionRequired = MAKEWORD(2, 2);
	wsaerr = WSAStartup(wVersionRequired, &wsaData);//startup
	if (wsaerr != 0)
	{
		cout << "ddl not loading itz dum" << wsaData.szSystemStatus << endl;
	}
	else
	{
		cout << "ddl loaded" << endl;
	}
	SOCKET boi = INVALID_SOCKET;
	boi = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);//create socket
	if (boi == INVALID_SOCKET)
	{
		cout << "socket not created monke" << endl;
	}
	else
	{
		cout << "socket created" << endl;
	}
	sockaddr_in kono;
	kono.sin_family = AF_INET;
	InetPton(AF_INET, _T("127.0.0.1"), &kono.sin_addr.s_addr);
	kono.sin_port = htons(3948);
	if(bind(boi,(sockaddr*)&kono,sizeof(sockaddr))==SOCKET_ERROR)
	{
		cout << "problem while binding "<<WSAGetLastError;
		closesocket(boi);
	}
	else
	{
		cout << "binding is gud"<<endl;
	}
	if (listen(boi, 1)==SOCKET_ERROR)
	{
		cout << "ma listening is stupit" << endl;
	}
	else
	{
		cout << "listening kill me" << endl;
	}
	SOCKET otBoi;
	sockaddr_in ava;
	ava.sin_family = AF_INET;
	InetPton(AF_INET, _T("127.0.0.1"), &ava.sin_addr.s_addr);
	ava.sin_port = htons(3948);
	int bugi = sizeof(sockaddr_in);
	otBoi = accept(boi,(sockaddr*)&ava,(socklen_t*)&bugi);
	if (otBoi==INVALID_SOCKET)
	{
		cout << "not accepting dummos";
	}
	else
	{
		cout << "welcome to the club";
	}
	send(otBoi, "im so cool yeaaa",17,0 );
	WSACleanup();
}*/