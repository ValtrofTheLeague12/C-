#include <fstream>
#include <iostream>
#include <cstring>
#include <string_view>
#define MAX_BUFFER 255
#define MIN_BUFFER 10
#define HTML "html.html"
void savefile(char* content){
	std::fstream file("results.html",std::ios_base::out);
	if(file.is_open()){
             file << content;
	     file.flush();
	     file.close();
	     std::cout << "Content has been saved :!!!" << std::endl;
	}
}
std::string_view PARSE_HTML(void(*save)(char*)){
	std::fstream file(HTML,std::ios_base::in);
	if(!file.is_open()){
             std::cerr << "could not open fail" << std::endl;
	}
	std::string content("");
	std::string data("");
	while(getline(file,content)){
              data = content;
	}
        const char* buffer = data.c_str();
	char* buff = (char*) malloc(sizeof(char) * MAX_BUFFER);
	if(buff == nullptr){
           throw std::runtime_error("error");
	}
	char* temp_buff = (char*) realloc(buff,(sizeof(char) * strlen(buff)) + 1);
	if(temp_buff == nullptr){
           throw std::runtime_error("allocation failed");
	}
	buff = temp_buff;
	if(!sprintf(buff,buffer,"Yassine")){
		std::cout << "failed !!" << std::endl;
		return (char*) malloc(sizeof(char) * MIN_BUFFER);
	}
	save(buff);
	return std::string_view(buff,strlen(buff));
        #undef HTML
        #undef MIN_BUFFER
        #undef MAX_BUFFER
}
int main(void){
      auto lambda = [](char* a){
	      a = nullptr;
	      free(a);
      };
      std::string_view html = PARSE_HTML(&savefile);
      if(strlen(((std::string)html).c_str()) == 0){
	      std::cout << "Parsing html fail" << std::endl;
      } 
      std::cout << html  << std::endl;
}
