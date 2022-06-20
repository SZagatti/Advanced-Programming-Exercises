/* The choice on how to implement the array that stores the prime numbers depends
   on what is the scope of our program. If the scope is to simply satisfy the
   requirement of the exercise, namely to populate an array with the prime numbers
   smaller than 100, then we can check how many prime numbers we will obtain (in 
   this case 25), allocate a static array of that size and then populate it.
   If we are less lazy, we may want the program to find the prime numbers smaller
   than a number typed by the user on the standard input, in that case it is not
   possible to know how large the array will be (some approximated formulas are
   available but we want a precise result) , so the only option is to resize
   the array each time a new prime number is found. 
*/

#include <iostream>
#include <cmath>
#include <vector>

bool is_prime(unsigned int a){
 
  for(unsigned int i=2; i <= floor(sqrt(a)); i++){
  
    if ((a % i)==0){
    
      return false;
    }
  }
  return true;
}

int main() {
  
  std::vector<unsigned int> primes;

  int max;

  std::cout << "Enter the maximum number up to which you want to find prime numbers: ";
  std::cin >> max;

  for(unsigned int i=2; i<=max; i++){
    
    if(is_prime(i)==true){
    
      primes.push_back(i);
      
    }
  }

  std::cout << "There are " << primes.size() << " prime numbers smaller than " << max << ":\n";
  //check: we print the values of the array

  for(unsigned int k : primes){
    std::cout << k << ' ';
  }
  std::cout << std::endl;

return 0;
}
