#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

int main() {

  std::cout<<"Enter two integer values\n";
  int val1=-1, val2=-1;
  std::cin>>val1>>val2;

  double ratio = double(val1)/double(val2);
  int sum = val1+val2;
  int  diff = val1-val2;
  int  prod = val1*val2;
  int int_ratio = val1/val2;

    if(val1>val2)
      std::cout << val1 <<" is the larger, "<< val2 <<" the smaller\n";
    if(val1<val2)
      std::cout << val2 <<" is the larger, "<< val1 <<" the smaller\n";

    std::cout <<"The sum is "<< sum <<", the difference is " << diff << "\n";
    std::cout <<"The product is "<< prod <<", the integer ratio is " << int_ratio << ", the ratio is "<< ratio << "\n";
}
