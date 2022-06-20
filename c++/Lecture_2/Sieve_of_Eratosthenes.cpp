#include <iostream>
#include <cmath>
#include <vector>
#include <string>

int main() {

  int n;
  std::cout << "Print all the prime numbers up to ";
  std::cin >> n;

  bool* primes = new bool[n-1];

  for(unsigned int i=0; i<n; i++){

    primes[i]=true;
  }
  
  for(unsigned int i = 2; i*i < n; i++){
  
    if(primes[i] == true){

      for(unsigned int j=i*i; j<n; j += i){

        primes[j] = false;
      }
    }
  }

  for(unsigned int k=2; k<n; k++){

    if(primes[k]==true){
    
      std::cout << k << '\n';
    }
  }
}
