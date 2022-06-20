#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

int main() {

  int a;
  std::cout << "Insert an integer value, I will tell you if it is odd or even!\n";
  std::cin >> a;
  if(a%2 == 0){
  std::cout << "The value " << a << " is an even number!\n";
  }else{
  std::cout << "The value " << a << " is an odd number!\n";
  }
}
