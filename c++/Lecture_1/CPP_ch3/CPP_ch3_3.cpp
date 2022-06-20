#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

int main() {

  std::cout<<"Please enter your name and age\n";
  std::string name="???";
  double age =-1;
  std::cin>>name>>age;
  age *= 12;
  std::cout << "Hello, "<< name <<"(age "<<age<<" months)\n"; 

}
