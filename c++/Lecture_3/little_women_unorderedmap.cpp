#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <array>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <map>
#include <unordered_map>

int main(int argc, char** argv){
  
  auto t0 = std::chrono::high_resolution_clock::now();  
  std::unordered_map<std::string, unsigned int> words{};
  std::vector<std::string> sequence{};
 
  std::fstream file("./LittleWomen.txt");
    std::string word;
    while(file >> word){
        sequence.push_back(word);
    }
  
  for(unsigned int k = 0; k < sequence.size(); k++){
     words[sequence[k]]++;
  }
  
  for(const auto& [key, value]:words){

    std::cout << key <<" "<< value << std::endl;
  }

auto t1 = std::chrono::high_resolution_clock::now();

auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(t1-t0);
std::cout << "Elapsed " << elapsed.count() << " [milliseconds]" << std::endl;

}
