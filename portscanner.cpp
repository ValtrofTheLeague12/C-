#include <iostream>
#include <random>
#include <arpa/inet.h> // for sockaddr* struct
#include <sys/socket.h> // for socket declaration
#include <cstring> 
#include <unistd.h> // for close() -> to close a socket
int generate_port_number();
void open_or_not(int port);
void log_file(std::string content);

int generate_port_number(){
	std::random_device rd;
	std::uniform_int_distribution<int> random(1024,65535);
	return random(rd);
} 
void open_or_not(int port){
//AF _INET means ipv4 address 
// SOCK_STREAM MEANS TCP

int soc = socket(AF_INET,SOCK_STREAM,0); // TCP IP socket 
if(soc == -1){ // means socket failed to be created -1  
	throw std::runtime_error("Opening socket failed !!!");
}
sockaddr_in server = {
AF_INET,
htons(port),
INADDR_ANY // 127.0.0.1 addr	
};
if(bind(soc,(struct sockaddr*)&server,sizeof(server)) == 0){	// bind() == 0 means its open
	char* buff = (char*) calloc(sizeof(char),100);
	if(buff == nullptr){
	  free(buff);
          throw std::runtime_error("Allocation error located");
	}
	sprintf(buff,"Port is open at %d",port);
	buff = (char*) realloc(buff,strlen(buff) + 1);
	if(!buff){
          free(buff); // clean memory if failed !!!
	  throw std::runtime_error("Reallocation of variable failed please try again");
	} 
	std::cout << buff << std::endl;
	free(buff);
}else{
	std::cout << "this port " << port << " is not open" << std::endl;
}
close(soc); // closing soc after usage 
}
int main(void){
try{
open_or_not(3306);
for(int i = 0 ;i<100;i++){
open_or_not(generate_port_number());
}
}catch(std::exception& e){
std::cout << "error : " << e.what() << std::endl;
}
return EXIT_SUCCESS;
}
//IA helped with this but i learned alot
