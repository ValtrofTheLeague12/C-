#include <iostream>
#include <string>
#include <cstring>
#include <random>
#include <fstream>
class class1{
	public:
	std::string name;
	public:
       	class1(std::string n){
             name = n;
	}
};
class class2 : class1{
	public:
	std::string lastname;
	public:
       	class2(std::string name,std::string lastname) : class1(name) {
		this->lastname = lastname;
                                                           
	}
};
class class3 {
	public:
	char name[21]; //abcdefghij...\0
	char lastname[21];
	class3(char name[],char last[]){
             if(std::strlen(name) == 20 && std::strlen(last) == 20){
		     std::strcpy(this->name,name);
		     std::strcpy(this->lastname,lastname);
	     }else{
                  std::cout << "needs to be 20 length" << std::endl;
		 
	     }
	}
};
class Friend{
private:
std::string name;
std::string lastname;
public:
Friend(){
name = "";
lastname = "";
}
Friend(std::string n,std::string m){
name = n;
lastname = m;
}
std::string getname(){
return this->name;
}
void setname(std::string sn){
this->name  = sn;
}
//concat name;
Friend operator+(const Friend& m){
	std::cout << "Names That will be concated : " << std::endl;
	std::cout << m.name << std::endl;
	std::cout << this->name << std::endl;
	char* buffer = (char*) malloc(sizeof(char) * (m.name.length() + this->name.length()) + 1);
	if(buffer ==  nullptr){
	throw std::runtime_error("error allocation failed please try again");
	}
	char* name1 = (char*) malloc(sizeof(char) * m.name.length() + 1);
	strcpy(name1,m.name.data());
	std::cout << "After Allocation : " << name1 << std::endl;
	char* other_name = (char*) malloc(sizeof(char) * this->name.length() + 1);
	strcpy(other_name,this->name.data());
	std::cout << "After Allocartion the other name : " << other_name << std::endl;
	sprintf(buffer,"%s %s",name1,other_name); //problem was here went from name to name1
	std::cout << "Buffer results : " << buffer << std::endl;
	return Friend(buffer,"haha");
}
Friend* operator-(const Friend& mf){
	int frhash = std::hash<std::string>()(mf.name);
	int nhash = std::hash<std::string>()(this->name);
	int newhash = frhash - nhash;
	std::string meow;
        std::random_device rd;
        std::uniform_int_distribution<int> fd(0,10);	
	for(char name : std::to_string(newhash)){
	  int cs = (int) name + fd(rd);
          meow.push_back((char)cs);
	}
	std::cout << meow << std::endl;
	return new Friend(meow,"second op");
	
}
void casting_pointers_example(){
char* p = new char("a"[0]); 
int *s = reinterpret_cast<int*>(p);
std::cout << *s << std::endl;
};


// we will make a instance of a class turn it to binary and use it
public:
static void turn_to_bin(Friend& fr){ 
std::ofstream f("results.bin",std::ios_base::binary);
if(!f.is_open()){
f.flush();
f.close();
throw std::runtime_error("file could not be open"); //unchecked exception
}
if(!(f.write(reinterpret_cast<char*>(&fr),sizeof(fr)))){
    f.flush();
    f.close();
    throw std::runtime_error("saving file failed...");
}
std::cout << "content has been saved !!!" << std::endl;
f.flush();
f.close();
}

public:
static void read_from_bin(){
	Friend m;
	std::ifstream file("results.bin",std::ios_base::binary);
	if(!file.is_open()){
           throw std::runtime_error("reading file failed...");
	}
	if(!(file.read(reinterpret_cast<char*>(&m),sizeof(Friend)))){
             throw std::runtime_error("failed to read content...");
	}
	std::cout << "Recovered name : " << m.name << std::endl;
	std:: cout << "Recovered lastname : " << m.lastname << std::endl;
	file.close();
}
};
int main(void){
Friend f("Yassine","Loussaief");
Friend G("Y","GG");
Friend Results = f + G;
Friend* R2 = f - G;
std::cout << "new name : " << R2->getname() << std::endl;
std::cout << Results.getname() << std::endl;
R2->casting_pointers_example();
Friend& ref = f;
Friend::turn_to_bin(ref);
Friend::read_from_bin();
delete R2;
return EXIT_SUCCESS;
}
