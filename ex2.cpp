#include <iostream>
#include <random>
#define MAX_COLS 2
#define MAX_ROWS 2
using namespace std;
int** fillmat(int rows,int cols);
void printmat(int** array , int rows,int cols);
void fillMatrice(int** array,int rows,int cols,int sub,int max); 
class sum {
   public:
   int rows;
   int cols;
   int* rowsum;
   int* colmssum;
   sum(int rows,int cols){
    this->rows = rows;
    this->cols = cols;
    rowsum = new int[rows];
    colmssum = new int[cols];
   }
};
void calculatesum(int rows,int cols,int** array,void (*sl)(sum*));
void printsum(sum* s);
void findMax(int **array ,int rows,int cols);

int main(){
  std::random_device rd;
  std::uniform_int_distribution<int> dist(0,30);
  int n = 0;
  int cols = 0;
  int** array = fillmat(MAX_ROWS,MAX_COLS);
  std::cout << "Give lignes : " << std::endl;
  std::cin >> n;
  std::cout << "Give colms : " << std::endl;
  std::cin >> cols;
  if(n > MAX_ROWS || cols > MAX_COLS){
        throw std::runtime_error("Please verify your input");
  }
  printmat(array,n,cols);
  calculatesum(n,cols,array,&printsum);
  std::cout << "Testing function : " << std::endl;
  std::cout << "give me sub number : " << std::endl;
  int sub = 0;
  std::cin >> sub;
  std::cout << "Give me max : " << std::endl;
  int max = 0;
  std::cin >> max ;
  fillMatrice(array, n,cols,sub,max);
  std::cout << "finding Max" << std::endl;
  findMax(array,n,cols);
  
  return 0;
}
int** fillmat(int rows,int cols){
  if(rows != cols){
    std::cout << "Please verify you input ..." << std::endl;
    throw std::runtime_error("Error needs to be carre");
  }
  std::random_device rd;
  std::uniform_int_distribution<int> dist(0,99);
  int ** array = new int*[rows];
  for(int i = 0;i<rows;i++){
     array[i] = new int[cols];
  }
  for(int i = 0 ;i<rows;i++){
    for(int j = 0;j<cols;j++){
      int *p = *(array + i) + j;
      *p = dist(rd);
    }
  }
  return array;
}
void printmat(int** array,int rows,int cols){
   for(int i = 0 ; i<rows;i++){
    for (int j = 0;j<cols;j++){
      std::cout << *(*(array + i) + j) << " | ";
      
    }
   }
}
void calculatesum(int rows,int cols,int** array,void (*sl)(sum*)){
  if(rows != cols){
    throw std::runtime_error("Please cols and rows need to be the same");
  }
   sum *s = new sum(rows,cols);
   if(s == nullptr){
    throw std::runtime_error("Please try again !!!");
   }
   int sum = 0;
   for (int i = 0;i<rows;i++){
    for(int j = 0;j<cols;j++){
      int p = *(*(array+ i) + j);
      sum += p;
    }
    s->rowsum[i] = sum;
    sum = 0;
   }

   int sum_cols = 0;
   int b = 0;
   for(int i = 0 ;i<rows;i++){
     for(int j  = 0 ; j<cols ;j++){
       sum_cols += array[j][i];
     }
     s->colmssum[b] = sum_cols;
     sum_cols = 0;
     b++;
   }
   sl(s); 
}                                     
void printsum(sum* s){
  for (int i = 0;i<s->rows;i++){
    std::cout << " Sum  of row : " << i << "equals " << s->rowsum[i] << " " << std::endl;
  }
  for(int j = 0 ;j<s->cols;j++){
     std::cout << " Colm  " << j << " Sum  equals : " << s->colmssum[j] << std::endl;
  }
}
void fillMatrice(int** array,int rows,int cols,int sub,int max){
  if(max <= 0 or sub <= 0){
        throw std::runtime_error("please sub and max should not be zero");
  }
  std::random_device rd;
  std::uniform_int_distribution<int> dist(sub,max);
  for(int i = 0;i<rows;i++){
    for(int j = 0;j<cols;j++){
      int* pointer  = *(array + i) + j;
      *pointer = dist(rd);
    }
  }
  printmat(array,rows,cols);
}
void findMax(int** array,int rows,int cols){
    if(rows != cols){
      throw std::runtime_error("Pleasae verify you input...");
   }
   int max = 0;
   int cols_pos = 0;
   int row_pos = 0;
   for(int i = 0;i<rows;i++){
    for (int j = 0 ; j<cols;j++){
      int p = *(*(array + i ) + j); 
       if (max < p){
        max = p;
        cols_pos = j;
        row_pos = i;
       }
    }
   }
   std::cout << "The Maximum value : " << *(*(array + row_pos) + cols_pos) << "Found in  L : " << row_pos << " C : " << cols_pos; 
}


