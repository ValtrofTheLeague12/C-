
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int ret(){
return 10;
}
int blood(){
return 20;
}
int gcc(){
return 0;
}
int main(void){
try{
//while(true) fork(); 
int *b = (int*) malloc(sizeof(int));
int *v = (int*) malloc(sizeof(int));
*v = 5; 
//int *snake = (int *) calloc(sizeof(int),3);
cout << b << endl;
b = &v;
cout << "Pointer address" << endl;
int *c = (int*) malloc(sizeof(int));
if(b == nullptr & c == nullptr){
throw runtime_error("allocation failed !!!");
}
cout << "it works" << endl;
map<string,int*> bc;
bc["first"] = b; // automatically 0
bc["second"] = c; // automatically 0
map<string,int (*)()> abc;
abc["piss"] = ret;
abc["blood"] = blood;
for (auto const &[key,function] : abc){
cout << "function calls : " << abc[key]() << endl;
cout << function() << endl;
//cout << "results : " << abc[key]() << endl;
}	
for (auto const &[key,val] : bc){ // REFERNCE TO KEY VALUE IN MAP &[]
(*val)++;
cout << *val << endl;
}
}catch(exception& e){
cout << e.what() << endl;
}catch(...){
cout << "do somethign !!" <<endl;
}

// Exception handling : try{}catch
// Function pointers
// Pointers (using malloc)
// for now we will be using calloc

}
