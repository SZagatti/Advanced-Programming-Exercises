#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <array>
#include <iomanip>
#include <fstream>
#include <chrono>

int main(int argc, char** argv){
  
  auto t0 = std::chrono::high_resolution_clock::now();  
  std::vector<std::string> sequence{};
  std::vector<std::string> words{};
  std::vector<unsigned int> count{};
 
  std::fstream file("./LittleWomen.txt");
    std::string word;
    while(file >> word){
        sequence.push_back(word);
    }

  words.push_back(sequence[0]);
  count.push_back(1);
  
  for(unsigned int k = 0; k < sequence.size(); k++){
  
    if(sequence[k] != sequence[k+1]){

        for(unsigned int j=0; j< words.size(); j++){
      
          if(sequence[k] == words[j]){
            count[j]++;
            break;
          }

          if(j == (words.size()-1)){
            words.push_back(sequence[k]);
            count.push_back(0);
          }
        }
    }
  }
  
  for(unsigned int i=0; i<words.size(); i++){

    std::cout << words[i] <<" "<< count[i] << std::endl;
  }

auto t1 = std::chrono::high_resolution_clock::now();

auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(t1-t0);
std::cout << "Elapsed " << elapsed.count() << " [milliseconds]" << std::endl;

}
