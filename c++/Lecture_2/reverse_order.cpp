#include <iostream>

template <typename T>
T* read_array(std::size_t size){

  T* array{new T[size]};

  std::cout << "Type the elements of the array:" << std::endl;
  for(int i=0; i<size; i++){
  std::cin >> array[i];
  }
  
  return array;
}

template <typename T>
void print_reverse(T* array, std::size_t size){

  std::cout << "Array in the reverse order:" << std::endl;
  for(int i=size-1; i>=0; i--){
    std::cout << array[i] << ' ';
  }
  std::cout << std::endl;
}

int main(){

  double* a;
  std::size_t size;
  std::cout << "Type the size of the array:" << std::endl;
  std::cin >> size;
  a = read_array<double>(size);

  std::cout << std::endl;

  print_reverse(a, size);

  delete[] a;

  return 0;
}
