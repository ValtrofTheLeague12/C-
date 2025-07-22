#include <iostream>
#include <arpa/inet.h>
#include <fstream>
#include <cstring>
#include <random>
#include <vector>
#include <ctime>
#include <unistd.h>
#include <regex>
#include <ctype.h>
#include <sys/socket.h>
#define MAX_BUFFER 100
#define LOG_FILE "Logs.log"
#define IP_FILE "ip.txt"
#define ALLOWED  "(PERMISSION : 1)"
#define GOOGLE_DNS "8.8.8.8"
#define UNALLOWED "(PERMISSION : 0)"
bool find_ip(char* ip);
void verify_if_online();
void terminal();
enum CLASS{
A = 1,
B = 2,
C = 3,
D = 4,
E = 5
};
enum PERMISSION {
ALLOW_PING = 1,
DONT_PING = 0
};

class classRange{
	private:
	int negative;
        int positive;
        public:
       /*@summary: n is the negative born and p is the positive born
	*used to define the range where ip class is generated
	**/ 	
       classRange(int n, int p){
         negative = n;
	 positive = p;
       }
       void setNegative(int negative){
               this->negative = negative;
       }
       void setPositive(int positive){
	       this->positive = positive;

       }
        int getNegative(){
        return this->negative;
	}
        int getPositive(){
         return this->positive;
	}
        public:
        void LogIntoFile(char* buffer)
{
                time_t tito = time(NULL);
		std::cout << "Current time : " << ctime(&tito) << std::endl;
		if(buffer == nullptr){
                    throw std::runtime_error("Buffer passed as null");
		}
		std::fstream file(LOG_FILE,std::ios::ios_base::app);
		if(!file.is_open()){
			   free(buffer);
			   throw std::runtime_error("File Handling failed please try again");
		}
		char* content = (char*) malloc(sizeof(char) * MAX_BUFFER);
		if(content == nullptr){
			file.close();
			free(buffer);
			throw std::runtime_error("Buffer failed to be created...");
		}
		sprintf(content,"[INFO | %s] Ip Address has been Logged %s\n",ctime(&tito),buffer);
		char* content_temp = (char*) realloc(content,sizeof(char) * strlen(content));
		if(content_temp == nullptr){
                       free(content);
		       throw std::runtime_error("Allocation function failed");
		}
		content = content_temp;
		file << content;
		std::cout << "IP Address logged successfully" << std::endl;
		file.flush();
		file.close();
		content = nullptr;
		free(content);
		free(buffer);
	} 	
};
enum PERMISSION read_perms(char* ip){
     std::fstream file(IP_FILE,std::ios::ios_base::in);
     if(!file.is_open()){
         throw std::runtime_error("error please try again mate !!! ");
     }
     std::string content =  std::string((std::istreambuf_iterator<char>(file)), 
                                            std::istreambuf_iterator<char>());
    
     char* content_buffer = (char*) malloc(sizeof(char) * strlen(content.c_str()));
     if(content_buffer == nullptr){
          file.close();
	  throw std::runtime_error("Allocation failed");
     }
     memset(content_buffer,"\0"[0],sizeof(content_buffer));
     strcpy(content_buffer,content.c_str());
     char* tokenizer = strtok(content_buffer,"\n");
     while(tokenizer != nullptr){
section2:
	     if(strstr(tokenizer,ip) == nullptr){
                   goto section1;
	     }
     if(strstr(tokenizer,ALLOWED) == nullptr){
              std::cout << "IP PERMISSION  [NO PING :] " << ip << "\n" << std::endl;
              return DONT_PING;
     }else{
     std::cout << "IP PERMISSION [PINGABLE : ] " << ip << "\n" << std::endl;
     return ALLOW_PING;
     }
          section1:
          tokenizer = strtok(nullptr,"\n");
     }
  } 
    
void ping_all_ip(){
	std::fstream file(IP_FILE,std::ios::ios_base::in);
        if(!file.is_open()){
          throw std::runtime_error("please verify the file it is not open");
	}	
	std::string content = std::string((std::istreambuf_iterator<char>(file)),std::istreambuf_iterator<char>());
        file.close();
	if(content.length() == 0){
             std::cout << " [ERROR : THERE IS NOTHING PING] IPWALL IS EMPTY" << std::endl;
	     terminal();
	}
	char* contents = (char*) malloc(sizeof(char) * strlen(content.c_str()));
	if(contents == nullptr){
           throw std::runtime_error("please verify you input...");
        }
        strcpy(contents,content.c_str());	
	char* token = strtok(contents," ");
	std::vector<char*> vecs;
	while(token != nullptr){
		vecs.push_back(token);
		token = strtok(nullptr," \n");
	}
        for(int i = 0; i<vecs.size();i++){ 
	  if(strstr(vecs.at(i),".") != nullptr){
		  if(read_perms(vecs.at(i)) == ALLOW_PING){
		  char* command = (char*) malloc(sizeof(char) * MAX_BUFFER);
		  if(command == nullptr){
                    throw std::runtime_error("allocation failed please try again !!!");
		  }
		  memset(command,sizeof(char),sizeof(command));
		  sprintf(command,"ping %s -c 2",vecs.at(i));
		  char* temp_command = (char*) realloc(command,(sizeof(char) * strlen(command)) + 1); 
		  if(temp_command == nullptr){
                         throw std::runtime_error("reallocation failed pls try again !!!");
		  }
		  command = temp_command;
		  std::cout << "\n" << std::endl;
		  std::system(command);
		  command = nullptr;
		  free(command); 
		 }else{
                       std::cout << "This IP is not pingable" << std::endl;
		 }
	    
	  }else{
             continue;
	  } 
	}  	
     vecs.erase(vecs.begin(),vecs.end());
     
} 


bool find_ip(char* ip_addr){
	if(strlen(ip_addr)  == 0){
           throw std::runtime_error("invalid ip address");
	 }
	if(ip_addr == NULL){
               throw std::runtime_error("null ip address");
	}
	std::fstream fs(IP_FILE,std::ios::ios_base::in);
	if(!fs.is_open()){
               throw std::runtime_error("file could not be open");
	}
	std::string contents((std::istreambuf_iterator<char>(fs)), 
        std::istreambuf_iterator<char>()); 
	char* content_buffer = (char*) malloc(sizeof(char) * strlen(contents.c_str()));
	if(content_buffer == nullptr){
		 fs.close();
		 free(ip_addr); 
                 throw std::runtime_error("allocation failed pls try again");
	}
	fs.close();
	memset(content_buffer,"\0"[0],sizeof(content_buffer));
        strcpy(content_buffer,contents.c_str());
        std::cout << "File content : " << content_buffer << std::endl;
	char* compare = strstr(content_buffer,ip_addr);
	if(compare == nullptr){
	    content_buffer = nullptr;
	    compare = nullptr;
	    free(content_buffer);
	    free(compare);
	    std::cout << "IP NOT FOUND ALLOWED TO ADD !!! " << std::endl;
            return true;
	}else{
	      std::cout << "IP WAS FOUND !!!" << std::endl;
	      content_buffer = nullptr;
	      compare = nullptr;
	      free(content_buffer); 
	      free(compare);
              return false; 
	} 
}

void delete_all_content(){
	std::fstream file(IP_FILE,std::ios::ios_base::out | std::ios::ios_base::in | std::ios::ios_base::trunc);
	std::string contents((std::istreambuf_iterator<char>(file)), 
        std::istreambuf_iterator<char>()); 
	if(contents.length() == 0){
             std::cout << "file content is already deleted !! " << std::endl;
	     terminal();
	} 	
	if(!file.is_open()){
           throw std::runtime_error("please try again !!!");
	}

	file << "";
	file.flush();
	file.close();
	std::cout << "file has been deleted successfully !!!" << std::endl;
}
std::string get_file_content(){
  std::fstream file(IP_FILE,std::ios::ios_base::in);
  if(!file.is_open()){
     throw std::runtime_error("error file failed to open please try again");
  }
  std::cout << "ALL RECOVERED IP ADDRESSES" << std::endl;
  std::string content = std::string((std::istreambuf_iterator<char>(file)), 
                                            std::istreambuf_iterator<char>()); 
  if(content.length() == 0){
    return std::string("IP Filewall is empty...");
  }
  file.close();
  return content;
}


bool verify_ip(char* ip){
 if(strlen(ip) == 0){
	  std::cout << "the given ip address is invalid" << std::endl;
          return false;
 }
  char* token = strtok(ip,".");
  int count = 0;
  while(token != nullptr){
	  for(int i = 0;i<strlen(token);i++){
	      if(token[i] ==  '.'){
                 continue;
	      } 
              if(isalpha(token[i])){
                  std::cout << "IPV4 ip cannot contain any letters" << std::endl;
		  terminal();
	      }  
	  }   
          int SEGMENT_VALUE = std::stoi(token);
          if(SEGMENT_VALUE > 255){
                   std::runtime_error("INVALID IP ADDRESS GIVEN ['IP ADDRESS ERROR']");
          }
         token = strtok(NULL,".");
         count++;
  }
  std::cout << "SEGMENTS COUNT : " << count << std::endl;   
  if(count < 4){
        return false;
  }
  return true;
} 

static void save_to_file(char* ip_addr,enum PERMISSION perm){
 char* ip = strdup(ip_addr);
 if(strlen(ip_addr) == 0){
    throw std::runtime_error("please verify your input IP ADDR is INVALID [IPADDR VALUE ERROR]");
 }
 if(perm <  0){
     throw std::runtime_error("INVALID PERMISSION  [PERMISSION ERORR]");
 }
  char* token = strtok(ip_addr,".");
  int count = 0;
  while(token != nullptr){
          int SEGMENT_VALUE = std::stoi(token);
	  if(SEGMENT_VALUE > 255){
                   free(ip_addr);
		   std::runtime_error("INVALID IP ADDRESS GIVEN ['IP ADDRESS ERROR']");
	  }
	 token = strtok(NULL,".");
	 count++;
  }
  std::cout << "SEGMENTS COUNT : " << count << std::endl;   
  if(count < 4){
       	throw std::runtime_error("INVALID IP ADDRESS NOT ALL SECTIONS ARE AVAILABLE");
  }
  if(!find_ip(ip_addr)){
         throw std::runtime_error("IP ALREADY EXISTS IN FILE [ERROR]");
  }
  std::fstream file(IP_FILE,std::ios::ios_base::app);
  if(!file.is_open()){
	 file.close();
         throw std::runtime_error("File did not want to open");
  }
  char* buffer = (char*) malloc(sizeof(char) * MAX_BUFFER);
  if(buffer == nullptr){
      file.close();
      throw std::runtime_error("please verify you allocation of buffer");
  }
  memset(buffer,"\0"[0],sizeof(buffer)); 
  sprintf(buffer,"%s (PERMISSION : %d)\n",ip,perm);
  char* temp_buffer = (char*) realloc(buffer,(sizeof(char) * strlen(buffer)) + 1);
  if(temp_buffer == nullptr){
       free(buffer);
       free(ip_addr);
       file.close();
       throw std::runtime_error("Allocationf failed please try again");
  }
  std::cout << "valid IP address saved !!!" << std::endl;
  file << buffer;
  file.flush();
  file.close();
  buffer = nullptr;
  free(buffer);
}
void generateIpAddress(enum CLASS type,bool ping_addr){
	classRange *R = (classRange*) malloc(sizeof(R));
	if(R == nullptr){
             throw std::runtime_error("memory Allocation failed !!!");
	}
        R->setNegative(0);
	R->setPositive(0); 
        switch(type){
		case 1:{
	                 R->setNegative(1);
			 R->setPositive(126);  
                         break;
                     }
		case  2: {
                         R->setNegative(128);
			 R->setPositive(223);
			    break;

			 }
	        case 3:{
                         R->setNegative(192);
			 R->setPositive(223);
			   break;
		       }
	        case 4: {
		        R->setNegative(224);
		        R->setPositive(239);
			   break;
			}
		case 5: {
                        R->setNegative(240);
			R->setPositive(254);
			}
		     
	}
	std::random_device rand;
        std::uniform_int_distribution<int> FIRST_SEGEMENT(R->getNegative(),R->getPositive());
	std::uniform_int_distribution<int> OTHER_SEGMENTS(0,255);
	std::vector<int>vecs = {0,0,0,0};
	vecs.at(0) = FIRST_SEGEMENT(rand);
	std::cout << "Class A : " << vecs.at(0) << std::endl;
        for(int i = 1; i<3;i++){
             vecs.at(i) = OTHER_SEGMENTS(rand);
	} 
	char* buffer = (char*) malloc(MAX_BUFFER * sizeof(char));
	if(buffer ==  nullptr){
          throw std::runtime_error("please handle error correctly");
	}
	//buffer is already a pointer no need to add the addr ;
	memset(buffer,"\0"[0],sizeof(buffer));
	sprintf(buffer,"%d.%d.%d.%d",vecs.at(0),vecs.at(1),vecs.at(2),vecs.at(3)); 
	char* temp_buffer = (char*) realloc(buffer,sizeof(char) * strlen(buffer));
       if(temp_buffer == nullptr){
	      free(buffer);
              throw std::runtime_error("reallocation failed please try again");
       } 
            buffer = temp_buffer;
	    if(!ping_addr){
               std::cout << "Your Generated ip address "<< buffer << std::endl;       
	    }else{
                char* command = (char*) malloc(sizeof(char) * MAX_BUFFER);
		if(command ==nullptr){
		   free(buffer);
                   throw std::runtime_error("Allocation of Command failed please try agan");
		}
		memset(command,"\0"[0],sizeof(command));
		sprintf(command,"ping %s -c 1",buffer);
		char* temp_command = (char*) realloc(command,sizeof(char) * strlen(command));
		if(temp_command == nullptr){
                   free(command);
		   throw std::runtime_error("Error reallocation of command failed");
		} 
		std::system(command);
		command = nullptr;
		free(command);
	    }  
            R->LogIntoFile(buffer);
	    buffer = nullptr;
	    free(buffer);
	    free(R);   
}
// we need ideas to work on 
void terminal(){
try{
   std::string jeff;
   while(true){
	 std::cout << "\n" << std::endl;
         std::cout << "Welcome to a simple terminal because its simple" << std::endl;
	 std::cout << "1 . Generate an ip address" << std::endl;
	 std::cout << "2 . Ping an ip address " << std::endl;
	 std::cout << "3 . Save an ip address" << std::endl;
	 std::cout << "4 . Recover ip addresses List" << std::endl;
	 std::cout << "5 . Ping All Allowed Ips" << std::endl;
	 std::cout << "6 . Delete IP File " << std::endl;
	 std::cout << "7 . Check if you are Online" << std::endl;
         std::cout << "8 . Exit terminal " << std::endl;
	 // to be createdstd::cout << "8 . socket creator : " << std::endl;  
	 std::cin >> jeff;
	 std::cout << "Your choice : " << jeff << std::endl;
	 switch(stoi(jeff)){
	      case 2:{
			std::string ip;
                        std::cout << "Give me the desired ip address " << std::endl;
			std::cin >> ip;
			if(ip.length() == 0){
			     std::cout << "the given ip is not valid please try again !!!" << std::endl;
                             terminal();
			}
			char* buffer = (char*) malloc(sizeof(char) * MAX_BUFFER);
      				if(buffer == nullptr){
				  throw std::runtime_error("allocation failed please try again !!!");
				}
			strcpy(buffer,ip.c_str());
			if(!verify_ip(buffer)){
                             std::cout << "this ip address is invalid !!!" << std::endl;
			     terminal(); 
			}
			strcpy(buffer,"");
			sprintf(buffer,"ping %s -c 3",ip.c_str());
			char* temp_buffer = (char*) realloc(buffer,(sizeof(char) * strlen(buffer)) + 1);
			if(temp_buffer == nullptr){
                                   throw std::runtime_error("reallocation failed please try again !!!");
			}
		        buffer = temp_buffer;
			std::system(buffer);
			buffer = nullptr;
			free(buffer);
			std::cout << "Ip has been pinged successfully !!!" << std::endl;
	
                        break;
		     } 
              case 1 : { 
                                 std::cout << "give me class of IPV4 address" << std::endl;
				 std::cout << "1 . A" << std::endl;
				 std::cout << "2 . B" << std::endl;
				 std::cout << "3 . C" << std::endl;
				 std::cout << "4 . D" << std::endl;
				 std::cout << "5 . E" << std::endl;
				 std::string type;
				 std::cin >> type;
				 enum CLASS Type;
				 for (int i = 0;i< type.length();i++){
                                   if(type[i] >= "a"[0] && type[i] <= "e"[0] || type[i] >= "A"[0] && type[i] <= "E"[0]){
				      continue;
				   }else{
                                             std::cout << "enter a valid value" << std::endl;
					     terminal();
				   }
				   
				 } 
				 if(type ==  "A"){
				      Type = A;
				 }else if(type == "B"){
                                      Type = B;
				 }else if(type == "C"){
                                      Type = C;
				 }else if(type == "D") {
                                      Type = D;          
				 }else{
                                      Type = E;
				 }
				 std::cout << "Selected TYPE : " << Type << std::endl; 
			         generateIpAddress(Type,false);     	 
				 break;
			 }
	      case 3 : {
			   try{
			   std::cout << "Give the desired ip address : " << std::endl;
                           std::string ip; 
			   std::cin >> ip;
			   std::cout << "What is kinda of permission do you want !!! " << std::endl;
			   std::cout << "1 . ALLOW" << std::endl;
		           std::cout << "2 . DONT" << std::endl;	   
			   std::string perm;
			   std::cin >> perm;
			   std::cout << "\n" << std::endl;
			   char* str = (char*) malloc(sizeof(char) * strlen(ip.c_str()));
			   if(str == nullptr){
                                  throw std::runtime_error("Allocation failed please try again");
			   } 
			   switch(perm == "ALLOW"){
                                case true:{
				       std::cout << "PERMITTED TO PING" << std::endl;
                                       enum PERMISSION perms = ALLOW_PING;
				       strcpy(str,ip.c_str());
				       save_to_file(str,perms);
				       str = nullptr;
				       free(str);
				       std::cout << "\n" << get_file_content() << std::endl;
                                       break;
		                 }

				case false :{ 
					        std::cout << "PERMISSION TO PING DENIED" << std::endl; 
						enum PERMISSION perms = DONT_PING;
						strcpy(str,ip.c_str()); 
						save_to_file(str,perms);
						str = nullptr;
						free(str);
						std::cout << "\n" << get_file_content() << std::endl;
					}	
			   }
                           break;
			  
		           }catch(std::exception& e){
                              std::cout << "[ERROR] something went wrong : " << e.what() << std::endl;
			      terminal(); 
			   }
		       } 
	     case 4 :{
			     std::cout << "Recovering ip list" << std::endl;
			     sleep(1);
			     std::cout <<  get_file_content() << std::endl;
			     break;

		     }

             case 5 : { 
			      std::cout << "PINGING ALL IPS..." << std::endl;
			      sleep(1);
			      ping_all_ip();
			      break;

		      }
	      case 6:{
                        std::cout << "Deleting all file content..." << std::endl;
			sleep(1);
			delete_all_content();
			break;
		     }
	     case 7:{
                          std::cout << "Checking if you are online" << std::endl;
			  sleep(1);
			  verify_if_online();
		    }   
	      case 8: {
                         std::cout << "Exiting Terminal" << std::endl; 
			 std::exit(0);

		      } 
	 } 
	 
   std::cin.clear();
   }
}catch(std::exception& e){
 std::cout << e.what()  << std::endl;
 std::cout << "Please enter a valid choice !!! " << std::endl;
 terminal();
} 
}
int find_free_port(){
	std::random_device rd;
	std::uniform_int_distribution<int> random(0,30);
} 
void verify_if_online(){ // needs to be worked on 
	char* buffer = (char*) malloc(sizeof(char) * MAX_BUFFER);
	if(buffer == nullptr){
           throw std::runtime_error("memory allocation failed please try again !!! ");
	}
	strcpy(buffer,"ping 8.8.8.8 -c 1");
        char* temp_buffer = (char*) realloc(buffer,sizeof(char) * strlen(buffer));
        if(temp_buffer == nullptr){
            throw std::runtime_error("reallocation failed pls try again !!!");
	}
        buffer = temp_buffer;
	FILE* pipe = popen(buffer,"r");
	if(pipe == nullptr){
          pclose(pipe);
	  throw std::runtime_error("Pipe Failed to open...");
	}
	char* stored_data = (char*) malloc(sizeof(char) * MAX_BUFFER);
	if(stored_data == nullptr){
           throw std::runtime_error("please verify you input");
	}
          int c = 0;	
	while(fgets(stored_data,MAX_BUFFER,pipe)){
	   c++;
	}
	std::cout << "\n" << std::endl;
	// if there is an error in the pipeline the length of the stored_buffer = 0
	if(strlen(stored_data) == 0){
                std::cout << "YOU ARE OFFLINE [CONNECTION TO GOOGLE.COM HAS FAILED]";
		buffer = nullptr;
		stored_data = nullptr;
		free(buffer);
		free(stored_data);
		pclose(pipe);
	}else{
              std::cout << "YOU ARE ONLINE [CONNNECTION TO GOOGLE.COM HAS BEEN SUCCESSFULLY MADE]" << std::endl;
	      buffer = nullptr;
	      stored_data = nullptr;
	      free(buffer);
	      free(stored_data);
	      pclose(pipe);
	}
	terminal();
}
	

	
          
    // 1 . open a pipe for comunication between ping -c command and the used executable
    // 2
    //
	


       	//IPV4
 //watching jack stauber networking programming
 // understand socket programming !!! 
 // dont copy code just try to understand it and learn networking with it
 /*
 int sock = socket(AF_INET,SOCK_STREAM,0);
 if(sock < 0){
        throw std::runtime_error("sock failed to intisialize");
 }

 sockaddr server; 
 server.port_in = htons(8080);
	// to do tommorrow we will learn how to send http reque
	///sts using sockets
 // best practices to deal with argv params
 */
 
void terminal_with_params(char* argv[]){
 if(strlen(argv[0]) == 0){
         std::cout << "no params specified !!!" << std::endl;
	 std::cout << "here is command line list : " << std::endl;
	 std::cout << "terminal ping <ip>" << std::endl;
	 std::cout << "terminal save <ip> ALLOW | DONT" << std::endl;
	 std::cout << "terminal ping list (future idea)" << std::endl; 
	 std::cout << "Hope you like it :D" << std::endl;
	 std::exit(0);
 }
 for(int i = 0;i<sizeof(argv) / sizeof(argv[0]); i++){
        if(strcmp(argv[1],"ping") == 0){
               if(strlen(argv[2]) == 0){
		       throw std::runtime_error("please mention the ip to ping...");	       
	        }else{
                       char* buffer = (char*) malloc(sizeof(char) * strlen(argv[2]) + 1);
		       if(buffer == nullptr){
                              throw std::runtime_error("allocation failed");
		       }
		       char* command = (char*) malloc(sizeof(char) * MAX_BUFFER);
		       if(command == nullptr){
                            throw std::runtime_error("allocation failed");
		       }
		       strcpy(buffer,argv[2]);
		       sprintf(command,"ping %s",buffer);
		       char* command_temp = (char*) realloc(command,(strlen(command) * sizeof(char)) + 1);
		       if(command_temp == nullptr){
                             throw std::runtime_error("error of reallocation");
		       }
		       command = command_temp;
		       std::cout << "Pinging the address of : " << buffer << std::endl;
		       std::system(command);
		       buffer = nullptr;
		       command = nullptr;
		       free(buffer);
		       free(command);
		} 
	   }
	  if(strcmp(argv[1],"save")){
                  if(strlen(argv[2]) == 0){
                        throw std::runtime_error("No ip or Permission found !!!");
		  }else{
                        char* PERM = strdup(argv[3]);
			if(strcmp(PERM,"ALLOW") == 0){
                                  enum PERMISSION perms = ALLOW_PING;
				  save_to_file(argv[2],perms); 
			}
		      
		  } 
	   }  
 }
 
}


 int main(int argc, char* argv[]){
	 terminal();
	 //terminal_with_params(argv);

// terminal ping 1.1.1.1.1	               	
	/*
	enum CLASS cs = A;
	enum PERMISSION B = ALLOW_PING;
	char* ip = (char*) calloc(sizeof(char),MAX_BUFFER);
	strcpy(ip,"1.1.1.2");
	std::cout << "passing args : " << ip << std::endl;
	//save_to_file(ip,B); 
        read_perms("1.1.1.2");
        //generateIpAddress(cs,false); // works
	//bool p = find_ip(ip); // it worked
	//std::cout << "is it found annnnnnnnnnnd  : " << p << std::endl;
	*/ 
	return EXIT_SUCCESS;

}
