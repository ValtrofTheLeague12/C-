#include <iostream>
#include <cstring>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#define PORT 8000

int main(void){
int sock = socket(AF_INET,SOCK_STREAM,0);
if(sock < 0){
std::cerr << "Error something went wrong" << std::endl;
std::exit(EXIT_FAILURE);
}
sockaddr_in server; // server struct
memset(&server,0,sizeof(server));
server.sin_family = AF_INET; // ipv4 familly
server.sin_port = htons(PORT);  // big endian byte order
server.sin_addr.s_addr = INADDR_ANY; // any interface availlabe
if(bind(sock,(struct sockaddr*)&server	,sizeof(server)) != 0){
 std::cerr << "Please try again !!! failed at bind phase" << std::endl;
 close(sock);
 std::exit(EXIT_FAILURE);
}
if(listen(sock,3) != 0){
std::cerr << "listing phase failed please try again !!!";
close(sock);
std::exit(EXIT_FAILURE);
}
while(true){
sockaddr_in client;
memset(&client,0,sizeof(client));
socklen_t size = sizeof(client);
int client_sock = accept(sock,(struct sockaddr*)&client,&size);
if(client_sock == -1){
 close(sock);
 std::cerr << "accepting clients failed badly !!!" << std::endl;
 std::exit(EXIT_FAILURE);
}
std::cout << "client accepted throught port 8080 " << std::endl;
char* buffer = (char*) malloc(sizeof(char) * 1024);
if(buffer == nullptr){
std::cerr << "Allocation failed" << std::endl;
close(sock);
std::exit(EXIT_FAILURE);
}
char client_ip[INET_ADDRSTRLEN];
inet_ntop(AF_INET, &client.sin_addr, client_ip, INET_ADDRSTRLEN);
unsigned short client_port = ntohs(client.sin_port);
std::cout << "Received packet from: " << client_ip << ":" << client_port << "\n";

memset(buffer,"\0"[0],strlen(buffer));
while(true){
auto byte = read(client_sock,buffer,1024);
std::cout << "here is what client said"  << buffer << std::endl;
if(byte == 0){
 std::cout << "client has left the chat" << std::endl;
 break;
}
}
free(buffer);
close(sock);
break;
}

std::cout << "Chat is over " << std::endl;
return EXIT_SUCCESS;

}
