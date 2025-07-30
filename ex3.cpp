#include <iostream>
#define MAX_SIZE 5

void get_input(int* array);
double calculate_average(int* arr);
void display_output(double avg);
int main(){
  int* array = new int[MAX_SIZE];
  if(array == nullptr){
    throw std::runtime_error("Please verify your input");
  }
  get_input(array);
  display_output(calculate_average(array));
    return 0;
}
void get_input(int *array){
  int i = 0;
  for(int* pointer = &array[0] ; pointer <= &array[MAX_SIZE - 1] ;pointer++){
    std::cout  << "give your value for field [" << i << "]" << std::endl;
    std::cin >> *pointer;
    i++;
  }
}
double calculate_average(int* arr){
  int sum = 0;
  for(int i = 0 ; i<MAX_SIZE;i++){
    sum += *(arr + i);
  }
  return sum / MAX_SIZE;
}
void display_output(double avg){
  std::cout << "Your Array AVG " << avg << std::endl; 
}

