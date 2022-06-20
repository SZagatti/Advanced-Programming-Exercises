#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

int main() {
  
  std::cout<<"=== Miles to Kms converter ===\n";
  std::cout<<"Enter a distance in miles:\n";
  double miles= -1;
  std::cin>>miles;
  double kilometers= -1;
  kilometers = miles * 1.609;
  std::cout << miles << " Miles, are  " << kilometers << " Kilometers\n"; 
}
