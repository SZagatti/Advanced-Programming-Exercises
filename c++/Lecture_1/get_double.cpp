#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

double get_double();

int main() {

  double d=0;
  std::cout << "Input a double value:\n";
  d = get_double();
  std::cout << d <<"\n";
}

double get_double(){
  double d;
  while(!(std::cin >> d)){
  std::cin.clear();
  std::cin.ignore();
  }
  return d;
}

