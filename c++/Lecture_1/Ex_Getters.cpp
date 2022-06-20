#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

int get_int(){
  int i;
  while(!(std::cin >> i)){
  std::cin.clear();
  std::cin.ignore();
  }
  return i;
}

double get_double(){
  double d;
  while(!(std::cin >> d)){
  std::cin.clear();
  std::cin.ignore();
  }
  return d;
} 

double get_double();

int main() {

  int j;
  double k;
  std::cout << "Input an integer value:\n";
  j = get_int();
  std::cout << "Input a double value:\n";
  k = get_double();
  std::cout << "The integer is: " << j << "\n";
  std::cout << "The double is: " << k << "\n";

  return 0;
}
