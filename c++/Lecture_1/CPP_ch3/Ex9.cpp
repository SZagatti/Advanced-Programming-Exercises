#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

int main() {
  
  std::string num;
  std::cout << "Input a spelled out number:\n";
  std::cin >> num;
  
  if(num == "zero"){
    std::cout << "0\n";
  }
  else if(num == "one"){
    std::cout << "1\n";
  }
  else if(num == "two"){
    std::cout << "2\n";
  }
  else if(num == "three"){
    std::cout << "2\n";
  }
  else if(num == "four"){
    std::cout << "4\n";
  }
  else{
  std::cout << "Not a number that I know\n";
  }

}
