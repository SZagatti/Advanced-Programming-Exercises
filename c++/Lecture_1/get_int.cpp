#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

int get_int();

int main() {

  int i=0;
  std::cout << "Input an integer value:\n";
  i = get_int();
  std::cout << i <<"\n";
}

int get_int(){
  int i;
  while(!(std::cin >> i)){
  std::cin.clear();
  std::cin.ignore();
  }
  return i;
}
