#include <iostream>
#include <cstring>
#include <vector>
#define MAX_LIBRARY 100
#define LIB_CURRENT_SIZE 5
#define LIB_BORROW_SIZE 5
void terminal();
using namespace std;
class Book{
  private:
  Book ** books;
  std::vector<Book*> br;  
  std::string Author;
  std::string title;
  std::string Description;
  std::string isbn;
  bool Available;
  int borrowcount = 0;
  int cc = 0;
  public:
  int getCount(){
        return cc;
  }
  void setCount(int count){
    cc = count;
  }
  void printBorrowedbooks(){
	  if(br.size() == 0){
            std::cout << "You have borrowed nothing " << std::endl;
	  } 
	  for(int i = 0;i<br.size();i++){
	     std::string des = br.at(i)->Description.length() == 0 ? "EMPTY" : br.at(i)->Description;
             std::cout << "ISBN : " <<  br.at(i)->isbn << std::endl;
	     std::cout << "NAME : " << br.at(i)->title << std::endl;
	     std::cout << "AUTHOR : " << br.at(i)->Author << std::endl;
	     std::cout << "Description :" << des << std::endl;
	     std::cout << "#################################" << std::endl;
	  } 
  }
  std::string getDescription(){
       return this->Description;
  }
  void setDescription(std::string des,std::string title,int count){
	  bool found = false; 
          for(int i = 0;i<count;i++){
               if(books[i]->title == title){
		    books[i]->Description = des;
                    found = true;
		    std::cout << "Description has been set " << std::endl;
		    break;
	       } 
	  }
	 if(!found){
           std::cout << "Book not found please try again " << std::endl;
	 }  
  }
  
  void AddToLibray(Book* p,int count){
	  std::cout << "Count to be used " << count << std::endl;
	  if(count < MAX_LIBRARY){
          Book** arr = new Book*[count + 1];
	  copy(books,books + count,arr);
	  arr[count - 1] = p;
	  delete[] books;
	  books = arr;
	  }else{
          std::cout << "LIBRARY is full please try again later" << std::endl;
          }  
  }
  void printLibrary(){
          for(int i = 0;i<cc;i++){
		            std::string description = this->books[i]->Description.length() == 0 ? "EMPTY" : this->books[i]->Description; 
                            std::cout << "ISBN : " << this->books[i]->getISBN() << std::endl;
                            std::cout << "AUTHOR : " << this->books[i]->getAuthor()  << std::endl;
                            std::cout << "Title : " << this->books[i]->getTitle() << std::endl;
			    std::cout << "DESCRIPTION : " << description << std::endl;
                            std::cout << "###################################" << std::endl;
           }         
  }
  bool SearchForBook(std::string f,int count){
	  for(int i = 0;i<count;i++){
		  if(f == this->books[i]->title){
                          return true;
		  }
	  }
	  return false;
  }

  Book(){
       books = new Book*[LIB_CURRENT_SIZE];
       books[0] = new Book("Yassine","Loussaief","ABCDEF2FG",false);
       books[1] = new Book("Yassuo","Mandela","AVGAVGAVG",true);
       books[2] = new Book("Yassuo","AAAAA","AAASSSOOOOLL",false);
       books[3] = new Book("DDDD","DDDDDDD","MMMMMM",false);
       books[4] = new Book("FFFFF","MMMMM","SSSSSS",true);
       this->cc = LIB_CURRENT_SIZE;
  } 
  void setISBN(std::string isbn){
    this->isbn = isbn;
  }
  void setAuthor(std::string Author){
    this->Author = Author;
  }
  void setAvailable(bool aval){
    Available = aval;
    
  }
  void setTitle(std::string title){
    this->title = title;
  }
  std::string getTitle(){
    return this->title;
  }
  std::string getAuthor(){
    return this->Author;
  }
  std::string getISBN(){
    return this->isbn;
  }
  bool isAvailable(){
    return Available;
  }

 

void borrow(std::string titre,int count){ 
bool found = false;
bool available = false;
    for(int i = 0;i<count;i++){
        if(books[i]->title == titre){
		found = true;
		if(books[i]->Available){
			std::cout << "You have borrowed the book successfully " << std::endl;
			books[i]->setAvailable(false);
			available = true;
			br.push_back(books[i]); 
                        break;
           } 
      }
    }
    if(!found){
       std::cout << "You cannot borrow the book not found" << std::endl;
    }else if(!available){
       std::cout << "this cannot borrow the book not available" << std::endl;
    } 
  }
int index = 0; 
void DeleteBooks(){
     delete[] books;
} 
void ReturnBook(std::string l,int count){
for(int i = 0;i<count;i++){
 if(books[i]->title == l){
  index = i; 
 } 
}
std::cout << "Book in position : " << index << std::endl;
bool borrowed = false;
for(int i = 0;i<br.size();i++){
 if(br.at(i)->title == l){
      books[index]->setAvailable(true);  
      borrowed = true;
      br.erase(br.begin() + i);
      std::cout << "You have returned the book successfully !!!" << std::endl;
  } 
}
if(!borrowed){
 std::cout << "You did not borrow this book" << std::endl;
} 
}
  Book(std::string Author,std::string title,std::string isbn,bool Available){
    this->Author = Author;
    this->title = title;
    this->isbn = isbn;
    this->Available = Available;
  }
  ~Book(){
    std::cout << "Clearing objects " << std::endl;
  }

};
int count = 0;
Book* p;
Book* item;
int main(){
	p = new Book(); // will be removed in the end from the application memeory (stack)
        count = p->getCount();
	terminal();
  return 0;
}
void terminal(){
try{
  while(true){
   std::cout << "Choose your Option " << std::endl;
   std::cout << "1 . Add Book " << std::endl;
   std::cout << "2 . Borrow Book " << std::endl;
   std::cout << "3 . Print Available Book " << std::endl;
   std::cout << "4 . Search for Book " << std::endl;
   std::cout << "5 . list of borrowed books" << std::endl;
   std::cout << "6 . Return Book" << std::endl;
   std::cout << "7 . Set Book Description " << std::endl;
   std::cout << "8 . Exit " << std::endl;
   std::string str;
   std::cin >> str;
   std::cout << "Your Choice "  << str << std::endl;
   const char* buffer = str.c_str();
   switch(atoi(buffer)){
        case 1 : {
            std::cout << "Enter Book name " << std::endl;
            std::string title;
            std::cin >> title;
            std::cout << "Enter Author name" << std::endl;
            std::string Author;
            std::cin >> Author;
            std::cout << "Enter book ISBN " << std::endl;
            std::string ISBN;
            std::cin >> ISBN;
            item = new Book(Author,title,ISBN,true);
	    std::cout << "Libray Books" << count << std::endl;
	    count += 1;
	    p->setCount(count);
	    p->AddToLibray(item,count);
	    count = p->getCount();
            std::cout << "Book Addedd !!! Count : " << count << std::endl;
	    break;
        }       
        case 2 : {
			 std::cout << "Enter Book name " << std::endl;
			 std::string name;
			 std::cin >> name;
	                 p->borrow(name,count);
			 break;
			  
        }
		 
        case 3 : {
	p->printLibrary();
	break;
        }
        case 4 : {
			 std::cout << "Give me name of the book "<< std::endl;
			 std::string nameBook;
			 std::cin >> nameBook;
			 if(p->SearchForBook(nameBook,count)){
                              std::cout << "The book you are looking for exists ..." << std::endl;
			 }
                 	 break;
        }
	case 5 : {
			 p->printBorrowedbooks();
			 break;

		 } 
        case 6: {
                   std::cout  << "Give me the name of the book you want to return "<< std::endl;
		   std::string name;
		   std::cin >> name;
		   p->ReturnBook(name,count);
		   break;

		}
	case 7: {
			std::cout << "Give me the name of the book you was to set its description " << std::endl;
			std::string name;
			std::cin >> name;
		
                        std::string description;
			std::cout << "Give me Description" << std::endl;
			std::getline(std::cin >> std::ws,description);
			p->setDescription(description,name,count);
			 
			break;


		}	
        case 8 : {
			 std::cout << "EXITING CONSOLE" <<std::endl;
			 p->DeleteBooks();
			 delete item;
			 delete p;
			 std::exit(EXIT_SUCCESS);
			 break;
        }
   }
  }
}catch(std::exception& e){
  std::cout << e.what() << std::endl;
}
}

