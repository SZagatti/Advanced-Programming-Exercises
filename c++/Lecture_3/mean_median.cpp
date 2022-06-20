#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <array>
#include <iomanip>
#include <fstream>

double vector_mean(std::vector<double> vec){
  double sum{};
  
  for(auto x : vec){
    sum += x;
  } 
  return(sum/vec.size());
}

double vector_median(std::vector<double> vec){
  
  std::vector<double> ordered{vec};
  double median{};

  std::sort(ordered.begin(), ordered.end());
  
  if(!(ordered.size() % 2)){ //even
    median = (ordered[ordered.size()/2] + ordered[ordered.size()/2-1])/2;
  }else if(ordered.size() % 2){
    median = ordered[(ordered.size()/2)];
  }
  return median;
}

int main() {
  
  std::string line{};
  std::vector<double> temperatures{};
  double mean, median;
  
  std::ifstream myfile ("temperatures.txt");
  for(std::string line; std::getline(myfile, line); ){
    temperatures.push_back(std::stod(line));
  }

  mean = vector_mean(temperatures);

  median = vector_median(temperatures);
  
  std::cout<< "Mean: " << mean << "\nMedian: " << median << std::endl;
  return 0;
}
