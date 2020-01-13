/*
 * test_tcp_communication_server.cpp
 *
 *  Created on: 13 janv. 2020
 *      Author: ahu
 */



#include <iostream>
#include <SRV_TcpServer.hpp>



using namespace std;
using namespace SRV;



int main()
{
	cout << "Test C++ library for TCP communication : Server" << endl;

	CTcpServer l_CTcpServer;
	l_CTcpServer.initTcpServer();
	l_CTcpServer.startTcpServer();

    return 0;
}

