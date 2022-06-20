/* This program simply reads the sequence of words in input
   and outputs the same sequence of words without repetitions,
   for example:
   INPUT: "The cat cat is on on on the the table table table"

   OUTPUT: "The cat is on the table"

*/

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <array>
#include <iomanip>

int main(int argc, char** argv){

  std::vector<std::string> vector{};

  for(unsigned int i=1; i < argc; i++){
  
  vector.push_back(argv[i]);
  }

  for(unsigned int k = 1; k <= vector.size(); k++){
  
    if(vector[k] != vector[k-1]){
      
      std::cout << vector[k-1] << std::endl;
    
    if(vector[k] != vector[k-1] && k==vector.size()){

      std::cout << vector[k] << std::endl;
    }
    }
  }

}
