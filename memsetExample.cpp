#include <iostream>
#include <cstring>
void printString(std::string_view reader){

	std::cout << reader << std::endl;
}
struct test{
char a[20];
int s;
const float b = 302.1f;
}Test;
int main(void){
char* allocation = (char*) malloc(sizeof(char) *  11);
if(allocation == nullptr){
  std::cerr << "Error allocation please try again" << std::endl;
  std::exit(EXIT_FAILURE);
}
memset(allocation,"\0"[0],sizeof(allocation));
std::cout << strlen(allocation) << std::endl;
std::cout << allocation << std::endl;
allocation = nullptr;
free(allocation);
test t1;
memset(&t1,0,sizeof(t1));
memset(t1.a,"*"[0],sizeof(t1.a));
std::cout << t1.a << std::endl;
std::cout << t1.b << std::endl;

// string views
std::string abc = "Yassine";
const char* data = abc.c_str();
printString((std::string_view)data);
return EXIT_SUCCESS;
}
