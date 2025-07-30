#include <iostream>
int a(int b){

} 
int main(void){	
int x  = 20;
	int num;
	int userint = 0;
	do{
	   std::cout << "enter a valid number" << std::endl;
	   std::cin >> userint;
	   std::cout << "You entered this !!! : " << userint << std::endl;
	}while(x >= userint);
	std::cout << a(10) << std::endl;
}

