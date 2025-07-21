#include <iostream>
#include <cstring>
void printHello(){
std::cout << "Yassine Loussaief is the best in the west" << std::endl;
}
int main(void){
	void (*pointer)() = printHello;
	std::cout << typeid(*pointer).name() << std::endl;
	auto show = [](int a,int b) {
            return a + b;
	};
	auto conc = [](const char* a , const char* b){
		std::string results("");
		for (int i  = 0 ; i<strlen(a);i++){
			results.push_back(a[i]);
	        }
		results.push_back(" "[0]);
		for (int j = 0 ; j<strlen(b);j++){
                    results.push_back(b[j]);
		}
		return results;
	};
	std::cout << typeid(show).name() <<  std::endl;
	std::cout << typeid(show(10,10)).name() << std::endl;
	std::cout << conc("Yassine","Loussaief") << std::endl;
return EXIT_SUCCESS;
}
