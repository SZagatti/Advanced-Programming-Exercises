#include <cmath>  
#include <iomanip>
#include <iostream>
#include <string>

int main() {
  
  double value;
  std::string unit;
  std::cout << "Enter a lenght value with the unit of measure for the conversion:" << "\n";
  std::cin >> value >> unit;

  //we can also add other ways to express the word inches that maybe I don't know
  if (unit == "inch" || unit == "inches" || unit == "in"){
    value *= 2.54;
    unit = "m";
    std::cout << "Converted value is: " << value << " " << unit << "\n" ;
  }
  else {
    std::cout << "I don't know how to convert this unit, please enter a measure in inches!\n";
  }
  // We can develop the code futher by adding new non-SI measures and their ratio of conversion
  // by adding other else if statements before the else
}
