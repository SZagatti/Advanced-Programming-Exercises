#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

int main() {
  
  double a=0,b=0, result=0;
  std::string op;
  
  std::cout << "Insert an operation followed by two operands:\n";
  std::cin >> op >> a >> b;
  
  if( op == "+" || op == "plus"){
  result = a+b;
  std::cout << "The result is "<< result << "\n";
  }
  else if(op == "-" || op == "minus"){
  result = a-b;
  std::cout << "The result is "<< result << "\n";
  }
  else if(op == "*" || op == "mul"){
  result = a*b;
  std::cout << "The result is "<< result << "\n";
  }
  else if(op == "/" || op == "div"){
  result = a/b;
  std::cout << "The result is "<< result << "\n";
  }
  else{
  std::cout << "Not an operation that I know\n";
  }

}

