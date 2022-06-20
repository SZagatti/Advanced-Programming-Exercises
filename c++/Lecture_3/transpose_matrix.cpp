#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <array>
#include <iomanip>

template <typename T>
void print_matrix(const T& p, unsigned int row, unsigned int col){
  for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
   
    std::cout << std::setw(3) << p[i*col + j] << " ";
    }
  std::cout << std::endl;
  }
}

template <typename T>
std::array<double, 30> transpose(const T& p, unsigned int row, unsigned int col){
  
  std::array<double,30> transposed_p;
  
  for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
      transposed_p[j*row+i] = p[i*col + j];
    }
  }
  return transposed_p;
}

int main(){
  
  unsigned int nrow{5};
  unsigned int ncol{6};
  const unsigned int N{30};

  std::array<double, N> matrix;
  std::array<double, N> transposed_matrix;
  
  for(int i=0; i<nrow; i++){
    for(int j=0; j<ncol; j++){

      matrix[i*ncol + j] = i*ncol + j;
    }
  }
 
  std::cout<<"Original Matrix: " << std::endl;
  
  print_matrix(matrix, nrow, ncol);

  transposed_matrix = transpose(matrix, nrow, ncol);

  std::swap(nrow, ncol);
  
  std::cout<<"Original Matrix: " << std::endl;

  print_matrix(transposed_matrix, nrow, ncol);

  return 0;
}
