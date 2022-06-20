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

bool is_prime(unsigned int a){
 
  for(unsigned int i=2; i <= floor(sqrt(a)); i++){
  
    if ((a % i)==0){
    
      return false;
    }
  }
  return true;
}

unsigned int* incr_vec(unsigned int* oldv, std::size_t old_dim, unsigned int newn){

   auto tmp = new unsigned int[old_dim+1];

       for(unsigned int i=0; i<old_dim; i++){

         tmp[i] = oldv[i]; 
        }
       delete[] oldv;

       tmp[old_dim] = newn;

       return tmp;
}


int main() {
  
  auto primes = new unsigned int[0];
  unsigned int n_primes{0};
  int max;

  std::cout << "Enter the maximum number up to which you want to find prime numbers: ";
  std::cin >> max;

  for(unsigned int i=2; i<=max; i++){
    
    if(is_prime(i)==true){
    
      primes = incr_vec(primes, n_primes, i);
      
      n_primes++;
    }
  }

  std::cout << "There are " << n_primes << " prime numbers smaller than " << max << ":\n";
  //check: we print the values of the array

  for(unsigned int k=0; k<n_primes; k++){
    std::cout << primes[k] << ' ';
  }
  std::cout << std::endl;

  delete[] primes;
return 0;
}
