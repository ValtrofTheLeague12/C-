#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <random>
using namespace std;
void increment(int& i){
 i++;
}
namespace second{
vector<int> i;
}
using ptint = int*;
int v2(int * a){
return (*a)++; //  (*a) derefrence first then ++ add your value;
}
int v3(int a){
return 10;
}
void meow(){
cout << "fuck you you piece of shit" << endl;
}
void testP(void (*function)(vector<int>)){
vector<int> iop;
iop.push_back(1);
iop.push_back(2);
function(iop);
}
int calcul(int a,int b){
return a + b;
}
void print_vector(vector<int> str){
str.push_back(3);
for(int i = 0;i<str.size();i++){
cout << str[i] << endl;
}
}
void vect(vector<string>& vec){
vec.push_back("1");
}
int main(void){
	char* stringg = (char*)calloc(sizeof(char),10);
	if(stringg == nullptr){
         cout << "nullptr" << endl;
	 exit(0);
	}
	cout << stringg << endl;
	vector<string> s;
	s.push_back("Yassine");
	vect(s);
	for (string p : s){
          cout << p << endl;
	}
	std::random_device rd;
	std::uniform_int_distribution<int> dist(0,30);
	int (*cal)(int,int) = calcul;
	cout << "results : " << cal(dist(rd),dist(rd)) << endl;
	void (*test)(vector<int>) = print_vector;
        testP(test);
	auto function = meow;
	cout << function << endl;
	function();
	// or
	void (*func)() = &meow;
	func();
	int dick = 20;
	ptint t = &dick;
	char* str  = (char*) malloc(sizeof(char) * 20);
	if(str == nullptr){
          cout << "its null" << endl;
	}
        str[0] = '\0';
	cout << "Your string value " << str << endl;
	cout << "value of : " << *t << endl;
	int* rm =(int*) malloc(sizeof(int));
	rm = nullptr;
	if(rm == nullptr){
         cout << &rm << endl;
	};
	int b = 10;
	int& a = b;
        increment(a);
	int c = 10;
	int * p = &c;
	v2(p);
	cout << *p << endl;
	p = nullptr;
	cout << a << endl;
	delete p;
}
