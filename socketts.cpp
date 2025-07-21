#include <iostream>
#include <string>
#include <memory>
int main(void){
	int * a = (int*) malloc(sizeof(int));
	if(a == nullptr){
            std::cout << "null pointer" << std::endl;
       }

}
