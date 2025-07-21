#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <vector>
#include <memory>
class Employee {
public:

	//std::unique_ptr<std::string> s;
	std::string name;
	std::string company;
	std::string lastname;
	int Age;
	long getid(){
              return this->id; 
	}
	void setid(long id){
            this->id = id;
	}
	Employee(std::string name,std::string lastname){
		//s = "Blob";
		this->name = name;
		this->lastname = lastname;
	}
	//Type* &Reference variable
         static void changeNameWithRef(Employee* &point){
	 std::string yassine;
	 std::cout << "Enter your name scumbag !!!" << std::endl;
	 std::cin >> yassine;
         point->name = yassine;
	 std::cin.clear();
	 std::cin.ignore();
	}
private:
	long id;
	template <typename T>
	void clear_mem(T** p[]){
		for(int i = 0 ; i<sizeof(*p)/sizeof(*p[0]);i++){
                  free(*p[i]);
		}
		std::cout << "memory has been cleared successfully !!!" << std::endl;
	}
public:
	template <typename T> 
	void LogAnyType(T data){
    try{
	   T * d = (T*) malloc(sizeof(T));
	   *d = data;
	   std::cout << data << std::endl;
	   if(d == nullptr){
               throw std::runtime_error("something went wrong !!!");
	   }
	   std::cout << "T Type value : " <<  *d << std::endl;
	   std::ofstream meow("file.txt",std::ios_base::app);
	   meow << *d << "\n";
	   meow.close();
	   free(d);
		}catch(std::exception& error){
			std::cout << "error has been found" << error.what() << std::endl;
		}
	}

	void read_from_file(){
		try{
		  std::ifstream s("file.txt");
		  if(!s.is_open()){
                  throw std::runtime_error("file did not want to open... [LOCK]");
		  }
		  std::string sts;
	          while (getline(s,sts)){
			  std::cout << sts << std::endl;
		  }
		  s.close();
	    }catch(std::exception& error){
                    std::cout << "file not open" << std::endl;
		    exit(EXIT_FAILURE);
	    }
	}
	void save_to_file(std::string content){	
    try{
	char* charlie = (char*) malloc(sizeof(char) * content.length());
        char* value = (char*) malloc(sizeof(char) * (std::string("Hi There").length() + content.length()) + 1);
        if(value == nullptr && charlie == nullptr){
	     throw std::runtime_error("allocation failed");
	     exit(EXIT_FAILURE);
	     }
	     strcpy(charlie,content.data());
	     std::cout << content << std::endl;
	     std::sprintf(value,"%s %s","Hi There",charlie);
	     std::ofstream m("file.txt");
	     if(!m.is_open()){
                std::cout << "something went wrong !!!" << std::endl;
		exit(EXIT_FAILURE);
	     }
	     m << value;
	     m.flush(); 
	     m.close();
	     std::cout << "file has been written successfully" << std::endl;
	     char** p[2];
             p[0] = &charlie;
             p[1] = &value;
             this->clear_mem(p);

	     }catch(std::exception& e){
		     std::cout << e.what() << std::endl; 
	     }
	}
public:
	
	template <typename T>
	void hash_content(T content){
		std::hash<T> hash;
		std::cout << "the hash is : " << hash(content) << std::endl;
	}
};

int main(void){
 Employee* serbia = new Employee("M","FF");
 Employee* bosnia = new Employee("Meow","Flanders");
 Employee* crotia = new Employee("F","M");
 Employee** yogu[3];
 yogu[0] = &serbia;
 yogu[1]  = &bosnia;
 yogu[2] = &crotia;
 for(int i = 0;i<3; i++){
	 std::cout << "name : " << (*(yogu[i]))->name << std::endl;
	 std::cout << "last :" << (*(yogu[i]))->lastname << std::endl;
 }
 std::cout << "####################################" << std::endl;
 Employee* emp = new Employee("Yassine","Loussaief");
 //FunctionABC(emp);
 Employee::changeNameWithRef(emp);
 std::cout << "After Changes : " << emp->name << std::endl;
 emp->name = "Yassine";
 emp->company = "Loussaief";
 std::cout << emp->lastname << std::endl;
 std::cout << emp->name << std::endl;
 emp->setid(40);
 std::cout << emp->getid() << std::endl;
 emp->save_to_file("Yassine Loussaief is the best in the west");
 emp->read_from_file();
 int a = 10; 
 emp->LogAnyType(a);
 emp->hash_content("Yassine");
 emp->hash_content(10);
//std::unique_ptr<string> p = move(emp->s);
 std::cin.clear();
 return EXIT_SUCCESS;
}
