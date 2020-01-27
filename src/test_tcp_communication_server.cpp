/*
 * "test_tcp_communication_server.cpp"
 */



#include <iostream>
#include <TCP_Server.hpp>



using namespace std;
using namespace TCP;



int main()
{
	cout << "Test C++ library for TCP communication : Server" << endl;

	CTcpServer l_CTcpServer;
	l_CTcpServer.initTcpServer();


	while(1);

    return 0;
}

