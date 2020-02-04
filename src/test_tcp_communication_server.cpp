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

	SPathMsg 				l_pathMsg;
	SPathCorrectionMsg		l_pathCorrectionMsg;
	SWorkShopOrderMsg 		l_workShopOrderMsg;
	SStopMsg 				l_stopMsg;
	SWorkShopReportMsg 		l_workShopReportMsg;
	SBitReportMsg 			l_bitReportMsg;
	SErrorMsg 				l_errorMsg;
	SPathMsgBody 			l_pathMsgBody1 							= {3, {1,2,3,0,0,0,0,0,0,0}};
	SPathMsgBody 			l_pathMsgBody2 							= {7, {7,6,5,4,3,2,1,0,0,0}};
	SPathCorrectionMsgBody	l_pathCorrectionMsgBody1				= {2, 3, {11,12,13,0,0,0,0,0,0,0}};
	SPathCorrectionMsgBody	l_pathCorrectionMsgBody2				= {5, 7, {17,16,15,14,13,12,11,0,0,0}};
	SWorkShopOrderMsgBody 	l_workShopOrderMsgBody1					= {1};
	SWorkShopOrderMsgBody 	l_workShopOrderMsgBody2					= {2};
	SStopMsgBody 			l_stopMsgBody1							= {11};
	SStopMsgBody 			l_stopMsgBody2							= {12};
	SWorkShopReportMsgBody 	l_workShopReportMsgBody1				= {101};
	SWorkShopReportMsgBody 	l_workShopReportMsgBody2				= {102};
	SBitReportMsgBody 		l_bitReportMsgBody1						= {1001};
	SBitReportMsgBody 		l_bitReportMsgBody2						= {1002};
	SErrorMsgBody 			l_errorMsgBody1							= {10001};
	SErrorMsgBody 			l_errorMsgBody2							= {10002};
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
						cout << "	displayWorkShopReportMsg : display WORKSHOP_ORDER_REPORT message\n";
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
						l_updateWorkShopReportMsgBodyCounter++;
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
						l_updateBitReportMsgBodyCounter++;
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
						l_updateErrorMsgBodyCounter++;
					}

					else if(strcmp(l_serverInputMsg.c_str(), "displayPathMsg") == 0)
					{
						l_CTcpServer.getMsg(MSG_ID_PATH, &l_pathMsg);
						cout << "> Path message : \n";
						cout << "	[hd]\n";
						cout << "		id : " << l_pathMsg.hd.id << "\n";
						cout << "		size : " << l_pathMsg.hd.size << "\n";
						cout << "	[body]\n";
						cout << "		pointsNb : " << l_pathMsg.body.pointsNb << "\n";
						cout << "		xyPointsArray : [";
						for(uint32_t i=0 ; i<MAX_PATH_POINTS ; i++)
						{
							cout << l_pathMsg.body.xyPointsArray[i] << " ";
						}
						cout << "]\n";
					}

					else if(strcmp(l_serverInputMsg.c_str(), "displayPathCorrectionMsg") == 0)
					{
						l_CTcpServer.getMsg(MSG_ID_PATH_CORRECTION, &l_pathCorrectionMsg);
						cout << "> Path correction message : \n";
						cout << "	[hd]\n";
						cout << "		id : " << l_pathCorrectionMsg.hd.id << "\n";
						cout << "		size : " << l_pathCorrectionMsg.hd.size << "\n";
						cout << "	[body]\n";
						cout << "		lastIdValid : " << l_pathCorrectionMsg.body.lastIdValid << "\n";
						cout << "		pointsNb : " << l_pathCorrectionMsg.body.pointsNb << "\n";
						cout << "		xyPointsArray : [";
						for(uint32_t i=0 ; i<MAX_PATH_POINTS ; i++)
						{
							cout << l_pathCorrectionMsg.body.xyCorrectionPointsArray[i] << " ";
						}
						cout << "]\n";
					}

					else if(strcmp(l_serverInputMsg.c_str(), "displayWorkShopOrderMsg") == 0)
					{
						l_CTcpServer.getMsg(MSG_ID_WORKSHOP_ORDER, &l_workShopOrderMsg);
						cout << "> Workshop order message : \n";
						cout << "	[hd]\n";
						cout << "		id : " << l_workShopOrderMsg.hd.id << "\n";
						cout << "		size : " << l_workShopOrderMsg.hd.size << "\n";
						cout << "	[body]\n";
						cout << "		tmp : " << l_workShopOrderMsg.body.tmp << "\n";
					}

					else if(strcmp(l_serverInputMsg.c_str(), "displayStopMsg") == 0)
					{
						l_CTcpServer.getMsg(MSG_ID_STOP, &l_stopMsg);
						cout << "> Stop message : \n";
						cout << "	[hd]\n";
						cout << "		id : " << l_stopMsg.hd.id << "\n";
						cout << "		size : " << l_stopMsg.hd.size << "\n";
						cout << "	[body]\n";
						cout << "		tmp : " << l_stopMsg.body.tmp << "\n";
					}

					else if(strcmp(l_serverInputMsg.c_str(), "displayWorkShopReportMsg") == 0)
					{
						l_CTcpServer.getMsg(MSG_ID_WORKSHOP_REPORT, &l_workShopReportMsg);
						cout << "> Workshop report message : \n";
						cout << "	[hd]\n";
						cout << "		id : " << l_workShopReportMsg.hd.id << "\n";
						cout << "		size : " << l_workShopReportMsg.hd.size << "\n";
						cout << "	[body]\n";
						cout << "		tmp : " << l_workShopReportMsg.body.tmp << "\n";
					}

					else if(strcmp(l_serverInputMsg.c_str(), "displayBitReportMsg") == 0)
					{
						l_CTcpServer.getMsg(MSG_ID_BIT_REPORT, &l_bitReportMsg);
						cout << "> Bit report message : \n";
						cout << "	[hd]\n";
						cout << "		id : " << l_bitReportMsg.hd.id << "\n";
						cout << "		size : " << l_bitReportMsg.hd.size << "\n";
						cout << "	[body]\n";
						cout << "		tmp : " << l_bitReportMsg.body.tmp << "\n";
					}

					else if(strcmp(l_serverInputMsg.c_str(), "displayErrorMsg") == 0)
					{
						l_CTcpServer.getMsg(MSG_ID_ERROR, &l_errorMsg);
						cout << "> Error message : \n";
						cout << "	[hd]\n";
						cout << "		id : " << l_errorMsg.hd.id << "\n";
						cout << "		size : " << l_errorMsg.hd.size << "\n";
						cout << "	[body]\n";
						cout << "		tmp : " << l_errorMsg.body.tmp << "\n";
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

