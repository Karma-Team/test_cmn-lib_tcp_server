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

	SPathMsgBody 			l_pathMsgBody1;
	SPathMsgBody 			l_pathMsgBody2;
	SPathCorrectionMsgBody 	l_pathCorrectionMsgBody1;
	SPathCorrectionMsgBody 	l_pathCorrectionMsgBody2;
	SWorkShopOrderMsgBody	l_workShopOrderMsgBody1;
	SWorkShopOrderMsgBody	l_workShopOrderMsgBody2;
	SStopMsgBody		 	l_stopMsgBody1;
	SStopMsgBody		 	l_stopMsgBody2;
	SWorkShopReportMsgBody	l_workShopReportMsgBody1;
	SWorkShopReportMsgBody	l_workShopReportMsgBody2;
	SBitReportMsgBody		l_bitReportMsgBody1;
	SBitReportMsgBody		l_bitReportMsgBody2;
	SErrorMsgBody 			l_errorMsgBody1;
	SErrorMsgBody 			l_errorMsgBody2;
	string 					l_serverInputMsg;
	uint32_t 				l_updatePathMsgBodyCounter				= 0;
	uint32_t 				l_updatePathCorrectionMsgBodyCounter	= 0;
	uint32_t 				l_updateWorkShopOrderMsgBodyCounter		= 0;
	uint32_t 				l_updateStopMsgBodyCounter				= 0;
	uint32_t 				l_updateWorkShopReportMsgBodyCounter	= 0;
	uint32_t 				l_updateBitReportMsgBodyCounter			= 0;
	uint32_t 				l_updateErrorMsgBodyCounter				= 0;
	int 					l_quitRequested							= 0;
	int 					l_serverSocket;

	CTcpServer l_CTcpServer;
	l_serverSocket = l_CTcpServer.initTcpServer();

	if(l_serverSocket != -1)
	{
		//	While loop: send and receive message from server
			do
			{
				// Enter server cmd
					getline(cin, l_serverInputMsg);
					cout << "> Server cmd : " << l_serverInputMsg.c_str() << "\n";

				// Treat server cmd
					if(strcmp(l_serverInputMsg.c_str(), "help") == 0)
					{
						cout << "	help : display help message\n";
						cout << "	quit : close TCP server\n";
						cout << "	updatePathMsg : update PATH message\n";
						cout << "	updatePathCorrectionMsg : update PATH_CORRECTION message\n";
						cout << "	updateWorkShopOrderMsg : update WORKSHOP_ORDER message\n";
						cout << "	updateStopMsg : update STOP message\n";
						cout << "	updateWorkShopOrderReportMsg : update WORKSHOP_ORDER_REPORT message\n";
						cout << "	updateBitReportMsg : update BIT_REPORT message\n";
						cout << "	updateErrorMsg : update ERROR message\n";
						cout << "	displayPathMsg : display PATH message\n";
						cout << "	displayPathCorrectionMsg : display PATH_CORRECTION message\n";
						cout << "	displayWorkShopOrderMsg : display WORKSHOP_ORDER message\n";
						cout << "	displayStopMsg : display STOP message\n";
						cout << "	displayWorkShopOrderReportMsg : display WORKSHOP_ORDER_REPORT message\n";
						cout << "	displayBitReportMsg : display BIT_REPORT message\n";
						cout << "	displayErrorMsg : display ERROR message\n";
					}

					else if(strcmp(l_serverInputMsg.c_str(), "quit") == 0)
					{
						cout << "> Quit requested\n";
						l_quitRequested = 1;
					}

					else if(strcmp(l_serverInputMsg.c_str(), "updatePathMsg") == 0)
					{
						cout << "> Message to be updated : MSG_ID_PATH\n";
						if((l_updatePathMsgBodyCounter%2) == 0)
						{
							l_CTcpServer.updateMsg(MSG_ID_PATH, &l_pathMsgBody1);
						}
						else
						{
							l_CTcpServer.updateMsg(MSG_ID_PATH, &l_pathMsgBody2);
						}
						l_updatePathMsgBodyCounter++;
					}

					else if(strcmp(l_serverInputMsg.c_str(), "updatePathCorrectionMsg") == 0)
					{
						cout << "> Requested message to server : MSG_ID_PATH_CORRECTION\n";
						if((l_updatePathCorrectionMsgBodyCounter%2) == 0)
						{
							l_CTcpServer.updateMsg(MSG_ID_PATH_CORRECTION, &l_pathCorrectionMsgBody1);
						}
						else
						{
							l_CTcpServer.updateMsg(MSG_ID_PATH_CORRECTION, &l_pathCorrectionMsgBody2);
						}
						l_updatePathCorrectionMsgBodyCounter++;
					}

					else if(strcmp(l_serverInputMsg.c_str(), "updateWorkShopOrderMsg") == 0)
					{
						cout << "> Requested message to server : MSG_ID_WORKSHOP_ORDER\n";
						if((l_updateWorkShopOrderMsgBodyCounter%2) == 0)
						{
							l_CTcpServer.updateMsg(MSG_ID_WORKSHOP_ORDER, &l_workShopOrderMsgBody1);
						}
						else
						{
							l_CTcpServer.updateMsg(MSG_ID_WORKSHOP_ORDER, &l_workShopOrderMsgBody2);
						}
						l_updateWorkShopOrderMsgBodyCounter++;
					}

					else if(strcmp(l_serverInputMsg.c_str(), "updateStopMsg") == 0)
					{
						cout << "> Requested message to server : MSG_ID_STOP\n";
						if((l_updateStopMsgBodyCounter%2) == 0)
						{
							l_CTcpServer.updateMsg(MSG_ID_STOP, &l_stopMsgBody1);
						}
						else
						{
							l_CTcpServer.updateMsg(MSG_ID_STOP, &l_stopMsgBody2);
						}
						l_updateStopMsgBodyCounter++;
					}

					else if(strcmp(l_serverInputMsg.c_str(), "updateWorkShopReportMsg") == 0)
					{
						cout << "> Requested message to server : MSG_ID_WORKSHOP_REPORT\n";
						if((l_updateWorkShopReportMsgBodyCounter%2) == 0)
						{
							l_CTcpServer.updateMsg(MSG_ID_WORKSHOP_REPORT, &l_workShopReportMsgBody1);
						}
						else
						{
							l_CTcpServer.updateMsg(MSG_ID_WORKSHOP_REPORT, &l_workShopReportMsgBody2);
						}
					}

					else if(strcmp(l_serverInputMsg.c_str(), "updateBitReportMsg") == 0)
					{
						cout << "> Requested message to server : MSG_ID_BIT_REPORT\n";
						if((l_updateBitReportMsgBodyCounter%2) == 0)
						{
							l_CTcpServer.updateMsg(MSG_ID_BIT_REPORT, &l_bitReportMsgBody1);
						}
						else
						{
							l_CTcpServer.updateMsg(MSG_ID_BIT_REPORT, &l_bitReportMsgBody2);
						}
					}

					else if(strcmp(l_serverInputMsg.c_str(), "updateErrorMsg") == 0)
					{
						cout << "> Requested message to server : MSG_ID_ERROR\n";
						if((l_updateErrorMsgBodyCounter%2) == 0)
						{
							l_CTcpServer.updateMsg(MSG_ID_ERROR, &l_errorMsgBody1);
						}
						else
						{
							l_CTcpServer.updateMsg(MSG_ID_ERROR, &l_errorMsgBody2);
						}
					}

					else if(strcmp(l_serverInputMsg.c_str(), "displayPathMsg") == 0)
					{
						cout << "> Path message : \n";
					}

					else if(strcmp(l_serverInputMsg.c_str(), "displayPathCorrectionMsg") == 0)
					{
						cout << "> Path correction message : \n";
					}

					else if(strcmp(l_serverInputMsg.c_str(), "displayWorkShopOrderMsg") == 0)
					{
						cout << "> Workshop order message : \n";
					}

					else if(strcmp(l_serverInputMsg.c_str(), "displayStopMsg") == 0)
					{
						cout << "> Stop message : \n";
					}

					else if(strcmp(l_serverInputMsg.c_str(), "displayWorkShopReportMsg") == 0)
					{
						cout << "> Workshop report message : \n";
					}

					else if(strcmp(l_serverInputMsg.c_str(), "displayBitMsg") == 0)
					{
						cout << "> Bit message : \n";
					}

					else if(strcmp(l_serverInputMsg.c_str(), "displayStopMsg") == 0)
					{
						cout << "> Stop message : \n";
					}

					else
					{
						cout << "> Unknown server cmd : enter 'help' to display available cmd\n";
					}
			} while(l_quitRequested == 0);
	}
	else
	{
		cerr << "TCP server is not initialized! Quitting" << endl;
		return -1;
	}

    return 0;
}

