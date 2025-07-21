#include <iostream>
int main(void){
	char* allocation = (char*) malloc(sizeof(char) * 20);
	if(allocation == nullptr){
         free(allocation);
	 std::exit(0);
	}

 }
