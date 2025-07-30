#include <iostream>
int main(void){
 char* content = "Yassine";
 char* p = content;
 while(p != nullptr){
      std::cout << *p <<  std::endl;
      p = p + 1;
 } 
 return EXIT_SUCCESS;
}
