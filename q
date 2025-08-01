#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <sstream>
#define MAX_BUFFER 100
std::vector<int> getBinary(int num);
struct t_bin {
 int first_number;
 int second_number;
};
int main(void){
 t_bin* bin = (t_bin*) malloc(sizeof(t_bin));
 if(bin == nullptr){
     std::cerr << "Error Allocation failed exiting..." << std::endl;
     std::exit(EXIT_FAILURE);
 }
 memset(&bin,0,sizeof(bin));
 while(true){
  std::string choice; 
  std::cout << "hi there welcome to my terminal what is that you want to do ?" << std::endl;
  std::cout << "1 . Add to binary number"  << std::endl;
  std::cout << "2 . Convert a number to its binary format" << std::endl;
  std::cout << "3 . Convert an binary to Decimal" << std::endl;
  std::cin >> choice;
  if(choice == "2"){
	  std::cout << "enter you number : " << std::endl;
	  try{ 
		int num;
		std::cin >> num;
		std::vector<int> results = getBinary(num);
		for(int i : results){
                       std::cout << " " << i;
		} 

	  }catch(std::exception& e){
	      std::cout << e.what() << std::endl;
	      std::cout << "please fix you input..." << std::endl;
	      main();
	  }  
  }
  if(choice == "3"){
      try{
      std::string input;
      std::cout << "enter binary value ...." << std::endl;
      std::cin >> input;
      char * buffer = (char*) malloc(sizeof(char) * MAX_BUFFER);
      if(buffer == nullptr){
          std::cerr << "Allocation failed please try again" << std::endl;
	  std::exit(EXIT_FAILURE);
      }
      memset(buffer,"\0"[0],sizeof(buffer));
      strcpy(buffer,input.c_str());
      char* temp_buffer = (char*) realloc(buffer,sizeof(char) * strlen(buffer));
      if(temp_buffer == nullptr){
            std::cerr << "Allocation failed please try again" << std::endl;
	    std::exit(EXIT_FAILURE);
      } 
      buffer = temp_buffer;
      std::stringstream stm;
      int value_of_bit = 0;
      int somme = 0;
      for(int i = strlen(buffer) - 1;i>=0;i--){
	    std::string bit = std::string(buffer[i],1);
	    std::cout << "Converted Bit : " << bit << std::endl;
	    stm << bit;
	    stm >> value_of_bit; 
	    std::cout << "Treated bit : " << value_of_bit << std::endl;
            value_of_bit = value_of_bit * pow(2,i);
	    somme += value_of_bit;
      }
      std::cout << "Results Decimal value of : " << buffer << "is " << somme << std::endl;
     
     }
  
 catch(std::exception& e){
       std::cout << e.what() << std::endl;
  }
}
  
 }

return EXIT_SUCCESS;
}
 std::vector<int> getBinary(int number){
	 std::vector<int> bin;
	 std::vector<int> results;
	 if(number < 0){
             throw std::runtime_error("your input is invalid please try again");
	 }
	 while(number != 0){
                 int f = number / 2;
		 bin.push_back(number % 2);
		 number = f;
	 }
	 int i = bin.size() - 1;
	 while(i >= 0){
              results.push_back(bin.at(i));
	      i--;
	 } 
	 return results;
 }


 
