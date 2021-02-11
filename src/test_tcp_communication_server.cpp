/*
 * "test_tcp_communication_server.cpp"
 */

#include <iostream>
#include <common.hpp>
#include <TCP_Server.hpp>

using namespace std;
using namespace TCP;

int main() {
	cout << "Test C++ library for TCP communication : Server (begin)" << endl;

	SMsgInfoKeepAlive 		l_msgInfoKeepAlive						= {.hd={ID_MSG_INFO_KEEP_ALIVE,	sizeof( SMsgInfoKeepAlive )}, 	.body={false}};
	SMsgInfoPosition 		l_msgInfoPosition 						= {.hd={ID_MSG_INFO_POSITION, 	sizeof( SMsgInfoPosition )}, 	.body={0, 0}};
	SMsgOrderBit			l_msgOrderBit							= {.hd={ID_MSG_ORDER_BIT, 		sizeof( SMsgOrderBit )}, 		.body={0}};
	SMsgOrderPath 			l_msgOrderPath 							= {.hd={ID_MSG_ORDER_PATH,		sizeof( SMsgOrderPath )}, 		.body={0, {0,0,0,0,0,0,0,0,0,0}}};
	SMsgOrderPathCorr		l_msgOrderPathCorr						= {.hd={ID_MSG_ORDER_PATH_CORR, sizeof( SMsgOrderPathCorr )}, 	.body={0, 0, {0,0,0,0,0,0,0,0,0,0}}};
	SMsgOrderWorkShop 		l_msgOrderWorkShop						= {.hd={ID_MSG_ORDER_WORKSHOP, 	sizeof( SMsgOrderWorkShop )}, 	.body={0}};
	SMsgOrderStop 			l_msgOrderStop							= {.hd={ID_MSG_ORDER_STOP,		sizeof( SMsgOrderStop )}, 		.body={0}};
	SMsgReportBit 			l_msgReportBit							= {.hd={ID_MSG_REPORT_BIT, 		sizeof( SMsgReportBit )}, 		.body={0}};
	SMsgReportWorkShop 		l_msgReportWorkShop						= {.hd={ID_MSG_REPORT_WORKSHOP, sizeof( SMsgReportWorkShop )},	.body={0}};

	SMsgOrderPathBody 		l_msgOrderPathBody1 					= {3, {{1,2},{3,0},{0,0},{0,0},{0,0}}};
	SMsgOrderPathBody 		l_msgOrderPathBody2 					= {7, {{7,6},{5,4},{3,2},{1,0},{0,0}}};
	SMsgOrderPathCorrBody	l_msgOrderPathCorrBody1					= {2, 3, {11,12,13,0,0,0,0,0,0,0}};
	SMsgOrderPathCorrBody	l_msgOrderPathCorrBody2					= {5, 7, {17,16,15,14,13,12,11,0,0,0}};
	SMsgOrderWorkShopBody 	l_msgOrderWorkShopBody1					= {1};
	SMsgOrderWorkShopBody 	l_msgOrderWorkShopBody2					= {2};

	uint32_t 				l_updateCounterMsgBodyOrderPath			= 0;
	uint32_t 				l_updateCounterMsgBodyOrderPathCorr		= 0;
	uint32_t 				l_updateCounterMsgBodyOrderWorkShop		= 0;

	string 					l_inputCmd;
	int 					l_quitRequested							= 0;
	int 					l_serverSocket;
	int 					l_clientId 								= 0;

	CTcpServer l_CTcpServer;
	l_serverSocket = l_CTcpServer.initTcpServer();

	if( l_serverSocket != -1 ) {
		//	While loop: send and receive message from server
			do {
				// Enter server cmd
					cout << "> Server cmd : ";
					getline( cin, l_inputCmd );

				// Treat server cmd
					// Display the help message
						if( strcmp( l_inputCmd.c_str(), "help" ) == 0 ) {
							cout << "	help : display this help message \n";
							cout << "	quit : close TCP server \n";

							// Display a message that can be sent to the client
							cout << "	getMsgInfoKeepAlive \n";
							cout << "	getMsgInfoPosition \n";
							cout << "	getMsgOrderBit \n";
							cout << "	getMsgOrderPath \n";
							cout << "	getMsgOrderPathCorr \n";
							cout << "	getMsgOrderWorkShop \n";
							cout << "	getMsgOrderStop \n";

							// Display a message that can be received from the client
							cout << "	getMsgReportBit \n";
							cout << "	getMsgReportWorkShop \n";

							// Simulate an update of a message that can be sent to the client
							//cout << "	updateMsgInfoKeepAlive\n";	// Message updated periodically
							//cout << "	updateMsgInfoPosition\n";	// Message updated periodically
							//cout << "	updateMsgOrderBit\n"; 		// Message with no content to be updated
							cout << "	updateMsgOrderPath \n";
							cout << "	updateMsgOrderPathCorr \n";
							cout << "	updateMsgOrderWorkShop \n";
							//cout << "	updateMsgOrderStop \n";		// Message with no content to be updated

							// Send a message to the client
							//cout << "	sendMsgInfoKeepAlive\n";	// Message sent periodically
							//cout << "	sendMsgInfoPosition\n";		// Message sent periodically
							cout << "	sendMsgOrderBit\n";
							cout << "	sendMsgOrderPath \n";
							cout << "	sendMsgOrderPathCorr \n";
							cout << "	sendMsgOrderWorkShop \n";
							cout << "	sendMsgOrderStop \n";
						}

					// Close the server
						else if( strcmp( l_inputCmd.c_str(), "quit" ) == 0 ) {
							l_quitRequested = 1;
						}

					// Display a message that can be sent to the client
						else if( strcmp( l_inputCmd.c_str(), "getMsgInfoKeepAlive" ) == 0 ) {
							l_CTcpServer.getMsg( ID_MSG_INFO_KEEP_ALIVE, &l_msgInfoKeepAlive, l_clientId );
							displayMsgInfoKeepAlive( &l_msgInfoKeepAlive );
						} else if( strcmp( l_inputCmd.c_str(), "getMsgInfoPosition" ) == 0 ) {
							l_CTcpServer.getMsg( ID_MSG_INFO_POSITION, &l_msgInfoPosition, l_clientId );
							displayMsgInfoPosition( &l_msgInfoPosition );
						} else if( strcmp( l_inputCmd.c_str(), "getMsgOrderBit" ) == 0 ) {
							l_CTcpServer.getMsg( ID_MSG_ORDER_BIT, &l_msgOrderBit, l_clientId );
							displayMsgOrderBit( &l_msgOrderBit );
						} else if( strcmp( l_inputCmd.c_str(), "getMsgOrderPath" ) == 0 ) {
							l_CTcpServer.getMsg( ID_MSG_ORDER_PATH, &l_msgOrderPath, l_clientId );
							displayMsgOrderPath( &l_msgOrderPath );
						} else if( strcmp( l_inputCmd.c_str(), "getMsgOrderPathCorr" ) == 0 ) {
							l_CTcpServer.getMsg( ID_MSG_ORDER_PATH_CORR, &l_msgOrderPathCorr, l_clientId );
							displayMsgOrderPathCorr( &l_msgOrderPathCorr );
						} else if( strcmp( l_inputCmd.c_str(), "getMsgOrderWorkShop" ) == 0 ) {
							l_CTcpServer.getMsg( ID_MSG_ORDER_WORKSHOP, &l_msgOrderWorkShop, l_clientId );
							displayMsgOrderWorkShop( &l_msgOrderWorkShop );
						} else if( strcmp( l_inputCmd.c_str(), "getMsgOrderStop" ) == 0 ) {
							l_CTcpServer.getMsg( ID_MSG_ORDER_STOP, &l_msgOrderStop, l_clientId );
							displayMsgOrderStop( &l_msgOrderStop );
						}

					// Display a message that can be received from the client
						else if( strcmp( l_inputCmd.c_str(), "getMsgReportBit" ) == 0 ) {
							l_CTcpServer.getMsg( ID_MSG_REPORT_BIT, &l_msgReportBit, l_clientId );
							displayMsgReportBit( &l_msgReportBit );
						} else if( strcmp( l_inputCmd.c_str(), "getMsgReportWorkShop" ) == 0 ) {
							l_CTcpServer.getMsg( ID_MSG_REPORT_WORKSHOP, &l_msgReportWorkShop, l_clientId );
							displayMsgReportWorkShop( &l_msgReportWorkShop );
						}

					// Simulate an update of a message that can be sent to the client
						else if( strcmp( l_inputCmd.c_str(), "updateMsgOrderPath" ) == 0 ) {
							if( ( l_updateCounterMsgBodyOrderPath%2 ) == 0 ) {
								l_CTcpServer.updateMsg( ID_MSG_ORDER_PATH, &l_msgOrderPathBody1, l_clientId );
								l_updateCounterMsgBodyOrderPath = 0;
							} else {
								l_CTcpServer.updateMsg( ID_MSG_ORDER_PATH, &l_msgOrderPathBody2, l_clientId );
							}
							l_updateCounterMsgBodyOrderPath++;
						} else if( strcmp( l_inputCmd.c_str(), "updateMsgOrderPathCorr" ) == 0 ) {
							if( ( l_updateCounterMsgBodyOrderPathCorr%2 ) == 0 ) {
								l_CTcpServer.updateMsg( ID_MSG_ORDER_PATH_CORR, &l_msgOrderPathCorrBody1, l_clientId );
								l_updateCounterMsgBodyOrderPathCorr = 0;
							} else {
								l_CTcpServer.updateMsg( ID_MSG_ORDER_PATH_CORR, &l_msgOrderPathCorrBody2, l_clientId );
							}
							l_updateCounterMsgBodyOrderPathCorr++;
						} else if( strcmp( l_inputCmd.c_str(), "updateMsgOrderWorkShop" ) == 0 ) {
							if( ( l_updateCounterMsgBodyOrderWorkShop%2 ) == 0 ) {
								l_CTcpServer.updateMsg( ID_MSG_ORDER_WORKSHOP, &l_msgOrderWorkShopBody1, l_clientId );
								l_updateCounterMsgBodyOrderWorkShop = 0;
							} else {
								l_CTcpServer.updateMsg( ID_MSG_ORDER_WORKSHOP, &l_msgOrderWorkShopBody2, l_clientId );
							}
							l_updateCounterMsgBodyOrderWorkShop++;
						}

					// Send a message to the client
						else if( strcmp( l_inputCmd.c_str(), "sendMsgOrderBit" ) == 0 ) {
							l_CTcpServer.sendMsgToClient( ID_MSG_ORDER_BIT, l_clientId );
						} else if( strcmp( l_inputCmd.c_str(), "sendMsgOrderPath" ) == 0 ) {
							l_CTcpServer.sendMsgToClient( ID_MSG_ORDER_PATH, l_clientId );
						} else if( strcmp( l_inputCmd.c_str(), "sendMsgOrderPathCorr" ) == 0 ) {
							l_CTcpServer.sendMsgToClient( ID_MSG_ORDER_PATH_CORR, l_clientId );
						} else if( strcmp( l_inputCmd.c_str(), "sendMsgOrderWorkShop" ) == 0 ) {
							l_CTcpServer.sendMsgToClient( ID_MSG_ORDER_WORKSHOP, l_clientId );
						} else if( strcmp( l_inputCmd.c_str(), "sendMsgOrderStop" ) == 0 ) {
							l_CTcpServer.sendMsgToClient( ID_MSG_ORDER_STOP, l_clientId );
						}

					// Default
						else {
							cout << "> Unknown server cmd : enter 'help' to display available cmd\n";
						}
			} while( l_quitRequested == 0 );
	} else {
		cerr << "TCP server is not initialized! Quitting" << endl;
		return -1;
	}

	cout << "Test C++ library for TCP communication : Server (end)" << endl;
    return 0;
}
