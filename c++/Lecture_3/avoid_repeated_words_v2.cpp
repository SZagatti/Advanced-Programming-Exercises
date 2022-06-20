/* This program takes as an input a sequence of words and
   returns the words without the repetitions, for example:
   INPUT: "The cat is on the table the dog is under the table"

   OUTPUT: "The cat is on the table dog under"
*/

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <array>
#include <iomanip>

int main(int argc, char** argv){

  std::vector<std::string> sequence{};
  std::vector<std::string> words{};
  
  for(unsigned int i=1; i < argc; i++){
    sequence.push_back(argv[i]);
  }
  
  words.push_back(sequence[0]);
  
  for(unsigned int k = 0; k < sequence.size(); k++){
  
    if(sequence[k] != sequence[k+1]){

        for(unsigned int j=0; j< words.size(); j++){
      
          if(sequence[k] == words[j]){
            break;
          }

          if(j == (words.size()-1)){
            words.push_back(sequence[k]);
          }
        }
    
      /*if(k==(sequence.size()-1)){

        for(unsigned int j=0; j< words.size(); j++){
      
          if(words[j] != sequence[k]){
          
            words.push_back(sequence[k]);
          }
        }
      }*/
    }
  }
  
  for(unsigned int i=0; i<words.size(); i++){

    std::cout << words[i] << std::endl;
  }
}
