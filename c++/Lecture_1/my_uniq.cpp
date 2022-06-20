#include <iostream>
#include <string>

int main(){
  
  std::string line;
  std::string previous_line;
  
  std::getline(std::cin, previous_line);
  
  int i = 1;
  while(std::getline(std::cin,line)){

    if(line != previous_line){
      std::cout << "\t" << i << " " << previous_line << "\n";
      previous_line = line;
      i = 1;
    }
    else{
      i++;
    }
  }
}
