#include "lib1.h"
#include <iostream>
int main(void){
PRINT(SUBS(10,20));
PRINT(ADD(10,10));
std::cout << "\n";
std::cout << VALUE ;
#undef VALUE
// you cannot print it anymore
std::cout << VALUE;
}
