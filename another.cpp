#include <iostream>
#include <cstring>
#include <fstream>
#include <memory>
#include <random>
#include <vector>
#define MIN_BUFFER_LENGTH 20
struct guide {
        char name[MIN_BUFFER_LENGTH];
        char ln[MIN_BUFFER_LENGTH];
        int a;
}Guide;

void CopyByReference(guide* G,std::string name,std::string last);
void CopyByValue(guide G,std::string name,std::string last);

void CopyByReference(guide* G,std::string name,std::string last){
	strcpy(G->name,name.c_str());
	strcpy(G->ln,last.c_str());
	G->a = 20;
}

//Copying by value
void CopyByValue(guide G,std::string name,std::string lastname){
strcpy(G.name,name.c_str());
strcpy(G.ln,lastname.c_str());
G.a = 500;
}
#undef MIN_BUFFER_LENGTH
int main(void){
guide G;
memset(&G,0,sizeof(G));
G = {
   "Yassine",
   "Loussaief",
   10

};

std::string example;
std::cout << G.name << std::endl;
std::cout << G.ln << std::endl;
std::cout << G.a << std::endl;
CopyByReference(&G,std::string("Yassuo"),std::string("Doflaming"));
CopyByValue(G,std::string("Yassine"),std::string("Loussaief")); // Won't work :D you are creating a copy and changing it
std::cout << "After changement Name " << G.name << std::endl;
std::cout << "After changement last name  : " << G.ln << std::endl;
std::cout << "After changement age : " << G.a << std::endl;
std::cout << "enter your name " << std::endl;
std::getline(std::cin >> std::ws,example);
//std::cin normal one can't read content that has spaces between them
std::cout << example << std::endl;
std::cout << example.length() << std::endl;

int value = 10;
double *p = (double*) reinterpret_cast<int*>(&value);
float *c = reinterpret_cast<float*>(&p);
int val = 97;
char *a = reinterpret_cast<char*>(&val);
std::cout <<  "Casted to  char : " << *a << std::endl;
std::cout << *c << std::endl;
std::cout << *p << std::endl;
std::random_device rd;
std::uniform_int_distribution<int> r_int(80,120);
std::vector<int> list;
for (int i = 0;i<10;i++){
	list.push_back(r_int(rd));
	char* conversion = reinterpret_cast<char*>(&list.at(i));
	std::cout << *conversion <<  " " ; 
}
int f = 5;
int g = 6; 
int h = 0;
memcpy(&f,&h,sizeof(int)); //copying content using memcpy() 
memcpy(&g,&f,sizeof(int));
memcpy(&h,&f,sizeof(int));
std::cout << "Substitution using memcpy : " << "Value of a : " << f << "Value of B : " << g << "Value of c" << h  << std::endl;
return EXIT_SUCCESS;
}
