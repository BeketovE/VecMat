#pragma once
#include "Vector.h"
#include "Matrix.h"
#include <iostream>
using namespace std;

template <class T>
Vector<T> operator*(Matrix<T>& matrix, Vector<T>& vector)
{
 if (matrix.GetM() == vector.GetSize())
 {
  T* mas = new T[matrix.GetM()];
  T** mas_matrix = matrix.GetMatrix();
  T* mas_vector = vector.GetVector();
  for (int i = 0; i < matrix.GetM(); i++)
  {
   mas[i] = 0;
   for (int j = 0; j < matrix.GetN(); j++)
   {
    mas[i] = mas[i] + (mas_matrix[i][j] * mas_vector[j]);

   }
  }
  Vector<T> result(matrix.GetN(), mas);
  delete[] mas;
  return result;
 }
 else
  throw - 1;
};

template <class T>
Matrix<T> operator*(Vector<T>& vector, Matrix<T>& matrix)
{
 if (matrix.GetN() == vector.GetSize() && matrix.GetM() == 1)
 {
  T** mas = new T * [matrix.GetN()];
  for (int i = 0; i < vector.GetSize(); i++)
   mas[i] = new T[vector.GetSize()];

  for (int i = 0; i < vector.GetSize(); i++)
   for (int j = 0; j < matrix.GetN(); j++)
   {
    mas[i][j] = (matrix[0][j] * vector[i]);
   }
  Matrix<T> result(matrix.GetN(), vector.GetSize(), mas);


  for (int i = 0; i < vector.GetSize(); i++)
   delete[] mas[i];
  delete[] mas;
  return result;
 }
 else
  throw - 1;
};