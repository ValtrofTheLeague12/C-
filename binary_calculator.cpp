#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <sstream>
#include <unistd.h>
#define BIT int
#define MAX_BUFFER 100
std::vector<int> getBinary(int num);
struct t_bin {
 int first_number;
 int second_number;
};

BIT CalculateBitAddition(BIT b1,BIT b2){
          if (b1 == 1 && b2 == 0){
            return 1;
	  }
	  if(b1 == 0 && b2 == 0){
	    return 0;
	  }
	  if(b1 == 0 && b2 == 1){
            return 1;
	  }
	  if(b1 == 1 && b2 == 1){
           return 0;
	  }
} 

int main(void){
 t_bin* bin = (t_bin*) malloc(sizeof(t_bin));
 if(bin == nullptr){
     std::cerr << "Error Allocation failed exiting..." << std::endl;
     std::exit(EXIT_FAILURE);
 }
 memset(&bin,0,sizeof(bin));
 while(true){
  std::cout << "\n" << std::endl;
  std::string choice; 
  std::cout << "hi there welcome to my terminal what is that you want to do ?" << std::endl;
  std::cout << "1 . Add 2 binary numbers"  << std::endl;
  std::cout << "2 . Convert a number to its binary format" << std::endl;
  std::cout << "3 . Convert an binary to Decimal" << std::endl;
  std::cout << "4 . Convert binary to text" << std::endl;
  std::cout << "5 . Exit terminal" << std::endl;
  std::cin >> choice;
  if(choice == "4"){
     std::cout << "Exiting Terminal..." << std::endl;
     std::exit(EXIT_SUCCESS);
  }
  if(choice == "1"){
	  std::cout << "Give me the first binary number" << std::endl;
          int  firstbin;
	  int secondbin;
	  std::cin >> firstbin;
	  std::cout << "Give me the second binary number" << std::endl;
	  std::cin >> secondbin;
	  std::vector<int> first  =  getBinary(firstbin);
	  std::vector <int>second = getBinary(secondbin);
	  std::cout << "First Binary : " << std::endl;
          int firstsize = first.size() - 1;
	  int secondsize = second.size() - 1; 

  } 
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
      std::vector<char> vecs;
      
      char bit = '\0';
      int s = strlen(buffer) - 1; // 1 2 * 3 | 0 2 * 2  | 1 2 * 1 | 0 2 * 0  
      int value = 0;
      int somme = 0; 
      for(int j = 0 ; j<=strlen(buffer) - 1;j++){
            vecs.push_back(buffer[j]); 
            char bit = buffer[j];
            value = std::stoi(&bit) * pow(2,(s--));
            std::cout <<  bit <<  "*" << "(" << 2 << " * " << s << ")" << std::endl;
            std::cout << value << std::endl;
            somme += value;	    
      }
      std::cout << "The Decimal value of : " << buffer << " is : " << somme << std::endl;
      buffer = nullptr;
      free(buffer);
      

      //1010 -> 4 
   
      /*
      i = vecs.size() - 1;
      for(int p =vecs.size();p>= 0;p++){
	 int c = std::stoi(&vecs.at(p));
	 std::cout << "integer to be treated " << c << std::endl;
	 std::cout << c << "*" << "(" << 2 << "*" << p << ")" << std::endl;
         int value = c * pow(2,p);
	 somme += value;
	 std::cout << "Bit " << c << "Calculations " << value << std::endl;
	 std::cout << "Current Sum " << somme  << std::endl;
	 i--;
      }
      std::cout << "the dicimal value of this binary number is : " << somme << std::endl; 
     }
     */
  
  }
 catch(std::exception& e){
       std::cout << e.what() << std::endl;
 }
}
  
 }

return EXIT_SUCCESS;
}
//decimal vers binaire
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
/*
 * 1111
 * 1111
 * ----
 *  010
 *
 */ 


 
