#include <iostream>
#include <cstring>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <cstring>
#define PORT 8000
void ANOTHER_EXAMPLE(int clientSocket);
int main(int argv,char* argc[]){
	int clientSocket = socket(AF_INET,SOCK_STREAM,0);
	if(clientSocket == -1){
             throw std::runtime_error("error socket failed to be created");
	     std::exit(0);
	}
	//server details
	sockaddr_in server;
	memset(&server,0,sizeof(server)); // init memory block by 0
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	// server.sin_addr.s_addr = INADDR_ANY; this part is for server since it will try to connect         to any interface 
if(inet_pton(AF_INET,"127.0.0.1",&server.sin_addr) < 0){
	//Convert IPV4 or IPV6 Address to binary
	 close(clientSocket); //Close socket
         std::cerr << "Connection failed Unsportedd address " << std::endl;
}
// Connect to client server through socket with port 8080 and Addr 127.0.0.1 loopback
if(connect(clientSocket,(struct sockaddr*)& server,sizeof(server)) < 0){
	std::cerr << "Connection failed" << std::endl;
}
char* buffer =(char*) malloc(sizeof(char) * 1024);
ANOTHER_EXAMPLE(clientSocket);
if(buffer == nullptr){
std::cerr << "Pointer error" << std::endl;
close(clientSocket);
std::exit(EXIT_FAILURE);
}
memset(buffer,"\0"[0],1024);
char* temp_buffer = (char*) realloc(buffer,sizeof(char) * strlen(argc[1]));
if(temp_buffer == nullptr){
             std::cerr << "Reallocation failed" << std::endl;
	     close(clientSocket);
	     std::exit(EXIT_FAILURE);
}
strcpy(temp_buffer,argc[1]);
buffer = temp_buffer;
std::cout << "Content to be send : " <<  buffer << std::endl;
send(clientSocket,buffer,strlen(buffer),0);
close(clientSocket);
}
void ANOTHER_EXAMPLE(int clientSocket){
while(true){
 std::string cs;
 std::cout << "send soemthing to client" << std::endl;
 std::cin >> cs;
 char* buffer = (char*) malloc(sizeof(char) * strlen(cs.c_str()));
 if(buffer == nullptr){
       std::cerr << "allocation failed" << std::endl;
       std::exit(EXIT_SUCCESS);
 }
 strcpy(buffer,cs.c_str());
 if (send(clientSocket, buffer, strlen(buffer), 0) < 0) {
            std::cerr << "Send failed" << std::endl;
            break;
 }
 if(strcmp(buffer,"EXIT") == 0){
	 std::cout << "exit chat mode" << std::endl;
 break;
 }
 free(buffer);
}
close(clientSocket);
std::exit(EXIT_SUCCESS);
}
