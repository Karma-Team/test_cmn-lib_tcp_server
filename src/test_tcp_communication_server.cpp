/*
 * test_tcp_communication_server.cpp
 *
 *  Created on: 13 janv. 2020
 *      Author: ahu
 */



#include <iostream>
#include <COM_TcpServer.hpp>



using namespace std;
using namespace COM;



int main()
{
	cout << "Test C++ library for TCP communication : Server" << endl;

	int l_ret;

	CTcpServer l_CTcpServer;
	l_ret = l_CTcpServer.initTcpServer();
	if(l_ret != -1)
	{
		l_CTcpServer.startTcpServer();
	}

    return 0;
}

