#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		cerr<<"Missing hostname and port number";
		exit(0);
	}
	char *serverName = argv[1];
	int port =atoi(argv[2]);
	char message[1500];
	struct hostent* host= gethostbyname(serverName);
	sockaddr_in clientSocket;
	clientSocket.sin_family = AF_INET;
	clientSocket.sin_port = htons(port);
	clientSocket.sin_addr = **(struct in_addr **)host->h_addr_list;
	int clientSocket=socket(AF_INET, SOCK_STREAM,0);
	int status = connect(clientSocketID, (sockaddr *)&clientSocket, sizeof(clientSocket));  //connect to the server
	if(status<0)
	{
		cout<<"Error in connecting"<<endl;
		exit(0);
	}
	cout<<"Successful connection"<<endl;
	while(1){			//send and receive messages
		string data;
		cout<<"Client: ";
		cin>>data;
		strcpy(message,data.c_str());
		if(data == "exit")
		{
			cout<<"Connection terminated";
			break;
		}
		send(clientSocketID,message,sizeof(message),0);
		cout<<"Server";
		recv(clientSocketID,message, sizeof(message),0);
		if(!strcmp(message,"exit"))
		{
			cout<<"Connection terminated";
			break;
		}
		cout<<message<<endl;
		close(clientSocketID);
		
	}
