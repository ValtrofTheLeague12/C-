#include <iostream>
#include <string>
#include <memory>
using namespace std;
int main(void){
	int *test = (int*) malloc(sizeof(int));
	size_t sizek = sizeof(test);
	cout << "size of pointer" << sizek << endl;
	*test = 5 << 1;  // 111 0111 
	cout << "With bit chiffement : " << *test << endl;
	char *png = new char[2];
        png[0] = 'a';
	png[1] = 'b';
	char *pn = png;
	int size = sizeof(png) / sizeof(char);
	cout << size << endl;
	for(int i  = 0;i<sizeof(png) / sizeof(png[0]);i++){
           cout << png[i] << endl;
	}
        
	cout <<  "using pointer math : " << *(pn) << endl;
	cout << "using pointer math : " << *(pn + 1) << endl;

	/*
	while(png != nullptr){
             cout << *(pn) << endl;
	     pn++; 
	}
	*/
	int* p = new int;
	*p = 10;
	cout << "address of p " << p << "value : " << *p << endl;
	cout << "Testing" << endl;
	delete p;
}
