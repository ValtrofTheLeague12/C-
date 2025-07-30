#include <iostream>
using namespace std;

// Follow the Instructions to solve the lab and execute the code
int* reverse(int * pointer,int size);
void print(int *  pointer,int size);
void palindrom(int* array,int size);
int main()
{

    int n = 0;
	std::cout << "give me a size : " << std::endl;
	std::cin >> n;
	int *array = new int[n];
	int *p = array;
	for(int i = 0;i<n;i++){
		std::cout << "give elements" << i << std::endl;
        std::cin >> *(p + i);
	}
	std::cout << "Original Array " << std::endl;
    for(int* p = array; p != array + n; p++){
		    std::cout << *p << std::endl;
	}
	std::cout  << "Revered Array" << std::endl;
	palindrom(array,n);
	array = reverse(array,n);
	delete[] array;

	std::cout << "give me rows" << std::endl;
	int nm = 0;
	int cn = 0;
	std::cin >> nm; 
	std::cout << "Give me cols" << std::endl;
	std::cin >> cn;
	int **matrice = new int*[n];
	for(int i = 0;i<n;i++){
		*(matrice + i) = new int[cn];
	}
	for(int i = 0;i<n;i++){
		for(int j = 0 ;j<n;j++){
			 int * pointers = *(matrice + (i * j));
			 *pointers = 0;	
	}

	
    return EXIT_SUCCESS;
}
}
int* reverse(int* pointers,int size){
	int *a = new int[size]; 
	int i = 0;
	for(int *p = &pointers[size - 1] ; p >= &pointers[0];p--){
		 *(a + i) = *p;
		 i++;
	}
	return a;
}

void print(int* ptr,int size){
	for(int* p = &ptr[size - 1] ; p >= &ptr[0];p--){
          std::cout << *p << std::endl;
	} 
}
void palindrom(int *array,int size){
	std::string rev;
	for(int * p = &array[0];p <= &array[size];p++){
	char s = *p;
	rev.push_back(s);
	}
	std::string other;
	for(int i = rev.size() - 1 ;i>= 0 ;i--){
		other.push_back(rev[i]);
	}
	std::cout << rev << std::endl;
	std::cout << other << std::endl;
    if(other == rev){
            std::cout << "Reverse "<< rev << std::endl;
	}else{
		std::cout << "Not Reversed" << rev << std::endl;
	}	
}

