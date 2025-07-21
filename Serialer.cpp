#include <iostream>
#include <string>

class Number{
	private:
               int a;
	public:
             Number(int a){
		     this->a = a;

	     }
	     
	     Number operator+(const Number& numb){
                   return Number(a + numb.a);
	     }
	     
	     int return_number(){
                return this->a;
	     }
	     void set_number(int num){
                 a = num;
	     }
};
struct test{
	std::string name;
	int32_t age;
};
int main(void){
	try{
	float* pi = (float*) malloc(sizeof(float)); //practicing pointers
	if(pi == nullptr){
            throw std::runtime_error("allocation error");
	}
	*pi = 3.14f; //float pointers
	test t1 = { // structs
              "Yassine",
	      22
	}; //how to create a struct
	std::cout << *reinterpret_cast<float*>(&pi) << std::endl;
	std::cout << sizeof(t1) << std::endl;
	Number* b =  new Number(10);
	Number& ref = *b;
	std::cout << ref.return_number() << std::endl;
	Number c = Number(10) + Number(20);
	std::cout << c.return_number() << std::endl;
	


	return EXIT_SUCCESS;
	}catch(std::exception& err){
               std::cout << err.what() << std::endl;
	}
}
