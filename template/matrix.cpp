/*#include "matrix.h"
#include <iostream>
using namespace std;

template <typename T1>Matrix<T1>::Matrix(){
   rows = MAXROWS;
   cols = MAXCOLS;
   for (int i=0; i< rows; i++){
      for(int j=0; j< cols; j++){
	      doubleArray[i][j] = '\0';
      }
   }
}   

template <typename T1> void Matrix<T1>::printMatrix(){
   for (int i=0; i< rows; i++){
      for(int j=0; j< cols; j++){
	      cout << doubleArray[i][j] << "   ";
      }
      cout << endl;
   }
}

template <typename T1> void Matrix<T1>::setMatrix(T1 otherArray[][MAXCOLS]){
   for (int i=0; i< rows; i++){
      for(int j=0; j< cols; j++){
	      doubleArray[i][j] = otherArray[i][j];
      }
   }
}

template <typename T1> void Matrix<T1>::addMatrix(T1 otherArray[][MAXCOLS]){
   for (int i=0; i< rows; i++){
      for(int j=0; j< cols; j++){
	      doubleArray[i][j] += otherArray[i][j];
      }
   }
}

template <typename T1> void Matrix<T1>::addMatrix(Matrix otherMatrix){
   addMatrix(otherMatrix.doubleArray);
}
*/