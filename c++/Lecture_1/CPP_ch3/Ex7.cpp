#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

int main() {
  
  std::string a, b, c, temp;

  std::cout << "enter three strings:\n";
  std::cin >> a >> b >> c;

  if(a>b && a>c){
    temp=c;
    c=a;
    a=temp;
    
    if(a>b){
      temp=b;
      b=a;
      a=temp;
    }
  }
  if(b>a && b>c){
    temp=c;
    c=b;
    b=temp;
  }
  std::cout << a << ',' << b << ',' << c <<"\n";
}
