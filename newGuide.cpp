#include <iostream>
#include <fstream>
#include <string>
#include <string_view>
#include <cstring>
#include <vector>
#define MAX_BUFFER 255
// in this guide we will be grouping everything we learned : 
// socket programming -> Reseau
// file handling
// pointer
// Macros
// Templates
// type()
// namespaces
// Server will be logging data and Client will  be able to send data
// Command like interface where user can tell server can delete logs through commands
void PrintResponse(std::string_view value){
 std::cout << "Here is what client has send this message " << value << std::endl;
}
void cleanFiles(std::fstream* file){
(*(file)).flush();
(*(file)).close();
}
template <typename T>
void cleanBuffer(T buffer){
buffer = nullptr;
free(buffer);
}

template <typename T>
void LogToFile(T data,void (*cleaner)(std::fstream* file),void (*buffcleaner)(T buffer)) {
std::cout << "Data to be Logged : " << data << std::endl;
char* buffer = (char*) malloc(sizeof(char) * MAX_BUFFER);
if(buffer == nullptr){
 throw std::runtime_error("memory allocation failed please try again");
}
memset(buffer,"\0"[0],sizeof(buffer));
sprintf(buffer,"[LOGGING] %s at %s",std::to_string(data),std::string(__DATE__,strlen(__DATE__)));
char* temp_buffer = (char*) realloc(buffer,sizeof(char) * strlen(buffer));
if(temp_buffer == nullptr){
throw  std::runtime_error("Memory Allocation failed !!! please try again");
}
buffer = temp_buffer;
std::fstream file("Loggers.log",std::ios::ios_base::app);
if(!file.is_open()){
throw std::runtime_error("File not open please try again");
}
file << buffer;
cleaner(&file);
buffcleaner(buffer);
std::cout << "Logs has been saved successfully !!! " << std::endl;
}
template <typename T>
T ReadLogs(bool ret){
std::fstream file("Loggers.log",std::ios::ios_base::in);
if(!file.is_open()){
throw std::runtime_error("file failed to open");
}
std::string content;
while(getline(file,content)){
	std::cout << "getting content from file" <<  std::endl;
}
if(ret){
  return content;
}
return nullptr;
}


int main(void){
LogToFile(20,&cleanFiles,&cleanBuffer);
return EXIT_SUCCESS;
}
