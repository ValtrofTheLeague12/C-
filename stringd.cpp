#include <iostream>
using namespace std;
void change(int& a);
void change(int& a){
a++;
}
using namespace std;
int main(void){
        void(*abc)(int&) = change;
	int& dc = 10;
	abc(dc);
	int c = 5;
	int& a = c;
	cout << a++ << endl;
	int  *b = (int*) malloc(sizeof(int));
	*b = 5;
	change(a);
	cout << a << endl;
	delete b;

return EXIT_SUCCESS;
}
