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
std::vector<double> transpose(const T& p, unsigned int row, unsigned int col){
  
  std::size_t N;
  N=row*col;
  std::vector<double> transposed_p(N, 0);
  
  for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
      transposed_p[j*row+i] = p[i*col + j];
    }
  }
  return transposed_p;
}

int main(){

  unsigned int nrow, ncol;
  std::size_t N;
  std::cout << "Number of rows: "; 
  std::cin >> nrow;
  std::cout << "Number of columns: ";
  std::cin >> ncol;
  
  N=nrow*ncol;
  std::vector<double> matrix(N, 0);

  for(int i=0; i<nrow; i++){
    for(int j=0; j<ncol; j++){
      
      matrix[i*ncol + j]=i*ncol+j;
    }
  }
  std::cout << "Original matrix:" << std::endl;
  print_matrix(matrix, nrow, ncol);

  //Transpose the matrix
  
  std::vector<double> transposed(N, 0);
  
  transposed = transpose(matrix, nrow, ncol);

  std::swap(nrow, ncol);
  std::cout << "Transposed matrix:" << std::endl;
  
  print_matrix(transposed, nrow, ncol);
  return 0;
}
