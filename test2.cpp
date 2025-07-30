#include <iostream>
using namespace std;

// Follow the Instructions to solve the lab and execute the code
void palindrom(int* array,int size);
int* reverse(int * pointer,int size);
void print(int *  pointer,int size);
void matrice();
int main()
{

    int n = 0;
	std::cout << "give me a size : " << std::endl;
	std::cin >> n;
	int *array = new int[n];
	if(array == nullptr){
          throw std::runtime_error("Allocation failed");
	} 
	int *p = array;
	for(int i = 0;i<n;i++){
		std::cout << "give elements" << i << std::endl;
        std::cin >> *(p + i);
	}
	std::cout << "Original Array " << std::endl;
    for(int* p = array; p != array + n; p++){
		    std::cout << *p << std::endl;
	}
	std::cout  << "Reversed Array" << std::endl;
	palindrom(array,n);
	array = reverse(array,n); 
	delete[] array;	
	matrice();
    return EXIT_SUCCESS;
}


int* reverse(int* pointers,int size){
	int* start = pointers;
	int* end = pointers + size - 1;
	while(start < end){
          int temp = *start;
	  *start = *end;
	  *end = temp; 
	  start++;
	  end--;
	}	
	return pointers;
}

void print(int* ptr,int size){
	for(int* p = &ptr[size - 1] ; p >= &ptr[0];p--){
          std::cout << *p << std::endl;
	} 
}

void palindrom(int* array,int size){
	int *arrpointer = &array[0];
	int *rev = reverse(array,size);
	int i = 0 ;
    for(int* p = &rev[size - 1]  ; p >= &rev[0];p--){
	     std::cout << "Element at Reversed Array : " << *p << std::endl;
	     std::cout << "Element at Original Array :  " << *(arrpointer + i) << std::endl;
		 if(*p == *(arrpointer + i)){
			 i++;   
		 }else{
			 std::cout << "this is not a palindrom please try again" << std::endl;
	        	 std::exit(EXIT_FAILURE);
		 }
	}
	std::cout << "this is a palindrom" << std::endl;
}
void matrice(){
 std::cout << "give me number of rows" << std::endl;
 int nligne = 0;
 std::cin >> nligne;
 int cols = 0;
 std::cout << "give me numbers of cols" << std::endl;
 std::cin >> cols;
 int** mat = new int*[nligne];
 if(mat == nullptr){
     throw std::runtime_error("Allocation failed pls  try again ");
 }
 for(int i = 0; i<nligne;i++){
 *(mat + i) = new int[cols];
 if(*(mat + i) == nullptr){
       delete *(mat +i);
       delete[] mat;
       throw std::runtime_error("Allocation of colums failed");
 } 
 }
 for(int i = 0;i<nligne;i++){
    for(int j = 0;j<cols;j++){
	    std::cout << "give me value of " << "[" << i << "]" << "[" << j << "]" << std::endl;
	    int * pointer = *(mat + i) + j;
	    if(pointer == nullptr){
	       throw std::runtime_error("Allocation failed pls try again !!!");
	    }
	    std::cin >> *pointer;
	    std::cout << "Given Value : " << *pointer << std::endl;
   }
 }
std::cout << "Affichage de matrice" << std::endl;
for(int i = 0;i<nligne;i++){
     for(int j = 0 ; j<cols;j++){
         std::cout << *(*(mat + i) + j) << std::endl;    
     }  
}

for(int i = 0;i<nligne;i++){
  mat[i] = reverse(mat[i],cols); 
}
for(int i = 0 ;i<nligne;i++){
  for(int j = 0 ;j<cols;j++){
      std::cout << *(*(mat + i) + j) << std::endl;
  } 
 } 
}



