#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
struct newperson {
char* name;
int age;
};

int main(void){
//	cout << "Name : " << t2.name << endl;
//	cout << "Age : " << t2.age << endl;

	char name[] = "Yassine";
	newperson *t2 = (newperson*) malloc(sizeof(newperson));
	if(t2 == nullptr){
          cout << "null object" << endl;
	}
	t2->name =(char*) malloc(sizeof(char*) * 10);
	if(t2->name == nullptr){
          cout << "null ptr" << endl;
	}
        	
	// memcpy(t2->name,,sizeof(t2->name));
	t2->age = 20;
	cout << t2->name << endl;
	cout << t2->age << endl;
	int array[3];
	array[0] = 1;
	array[1] = 2;
	array[2] = 3;
	for(int i : array){
         cout << i << endl;
	}
	char s[] = "abcdefg";
	char d[sizeof(s) / sizeof(s[0])];
	memcpy(d,s,sizeof(char) * (sizeof(s) /sizeof(s[0])));
	cout << d << endl;
	char b[] = "abcdefgh\0ig";
	char sr[sizeof(b) / sizeof(b[0])];
	strcpy(sr,b);
	cout << "copied string using strcpy : " << sr << endl; // stops an \0
        char sec[sizeof(b) / sizeof(b[0])];
	memcpy(sec,b,sizeof(b));
	cout << "copied using memset : " << sec << endl;
	cout << "Size of of byte sec memcpy : " << sizeof(sec) << endl;
	cout << "Size of byte sec str cpy :  " << sizeof(b) << endl;
}
