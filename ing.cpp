#include <iostream>
int main(void){
int a = 5; 
int ba[1];
ba[2] = 1; //ERROR SEGFAULT
std::cin >> a;
std::cout << a << std::endl;
}
