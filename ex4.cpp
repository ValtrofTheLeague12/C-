#include <iostream>
class Student {
  private:
  int id;
  double gpa;
  std::string name;
  public:
  void setName(std::string name){
    this->name = name;
  }
  public:
  void setGPA(double gpa){
    this->gpa = gpa;
  }
  void setID(int id){
    this->id = id;
  }
  public:
  std::string getName(){
    return name;
  }
  double getGpa(){
    return gpa;
  }
  int getId(){
    return id;
  }
};

int main(){
Student *s = new Student();
if(s == nullptr){
  throw std::runtime_error("Allocation failed !!! ");
}
std::cout << "Enter GPA" << std::endl;
double gpa;
std::cin >> gpa;
if(gpa <= 0 || gpa > 4){
  std::cout << "please re-enter GPA" << std::endl;
  main();
}
s->setGPA(gpa);
std::string name("");
do{
   std::cout << "Enter your name" << std::endl;
   std::cin >> name;
}while(name.length() <= 0);
s->setName(name);
int id = 0;
do{
 std::cout << "enter you id " << std::endl;
 std::cin >> id;
}while(id <= 0);
s->setID(id); 

std::cout << "Student Information" << std::endl;
std::cout << "Name: " <<s->getName() << std::endl;
std::cout << "ID : " << s->getId() << std::endl;
std::cout << "GPA : " << s->getId() << std::endl;
delete s;
  return EXIT_SUCCESS;
}

