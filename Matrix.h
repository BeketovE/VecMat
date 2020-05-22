#pragma once
#include <iostream>
using namespace std;

template<class M>
class Matrix
{
private:
 void MemSize(int w, int l)
 {
  mass = new M * [m];
  for (int i = 0; i < w; i++) this->mass[i] = new M[l];
 }
protected:
 int m, n;
 M** mass;
public:
 Matrix();
 Matrix(int a, int b);
 Matrix(int c, int d, M** mas);
 Matrix(const Matrix<M>& oth);
 ~Matrix();

 void SetMatrix(M** el);
 M** GetMatrix();
 int GetM();
 int GetN();
 Matrix<M> operator+(const Matrix<M>& oth);
 Matrix<M> operator-(const Matrix<M>& oth);
 Matrix<M> operator*(const Matrix<M>& oth);
 Matrix<M> operator=(const Matrix<M>& oth);
 bool operator==(const Matrix<M>& oth);
 M*& operator[](const int i);
 template <class M>
 friend ostream& operator<<(ostream& os, const Matrix<M>& mat);
 template <class M>
 friend istream& operator>>(istream& in, Matrix<M>& mat);
 void SetRaz(int w, int l);
 int Find(M el);
};

template<class M>
Matrix<M>::Matrix()
{
 m = 1;
 n = 1;
 MemSize(m, n);
 mass[0][0] = 0;
}

template<class M>
Matrix<M>::Matrix(int a, int b)
{
 m = a;
 n = b;
 MemSize(m, n);
 for (int i = 0; i < m; i++)
 {
  for (int j = 0; j < n; j++)
  {
   mass[i][j] = 0;
  }
 }
}

template<class M>
Matrix<M>::Matrix(int c, int d, M** mas)
{
 m = c;
 n = d;
 MemSize(c, d);
 for (int i = 0; i < m; i++)
  for (int j = 0; j < n; j++)
   mass[i][j] = mas[i][j];
}

template<class M>
Matrix<M>::Matrix(const Matrix<M>& oth)
{
 m = oth.n;
 n = oth.m;
 MemSize(m, n);
 for (int i = 0; i < m; i++)
  for (int j = 0; j < n; j++)
   mass[i][j] = oth.mass[i][j];
}

template<class M>
Matrix<M>::~Matrix()
{
 if (mass != 0)
 {
  for (int i = 0; i < m; i++)
  {
   mass[i] = 0;
   delete[] mass[i];
  }
  mass = 0;
  delete[] mass;
  n = 0;
  m = 0;
 }
}

template<class M>
void Matrix<M>::SetMatrix(M** el)
{
 for (int i = 0; i < m; i++)
  for (int j = 0; j < n; j++)
   mass[i][j] = el[i][j];
}

template<class M>
M** Matrix<M>::GetMatrix()
{
 return mass;
}

template<class M>
int Matrix<M>::GetM()
{
 return m;
}

template<class M>
int Matrix<M>::GetN()
{
 return n;
}

template<class M>
Matrix<M> Matrix<M>::operator+(const Matrix<M>& oth)
{
 if (n == oth.n && m == oth.m)
 {
  Matrix<M> F(m, n, oth.mass);
  for (int i = 0; i < m; i++)
  {
   for (int j = 0; j < n; j++)
   {
    F.mass[i][j] = oth.mass[i][j] + mass[i][j];
   }
  }
  return F;
 }
 else
  throw - 1;
}

template<class M>
Matrix<M> Matrix<M>::operator-(const Matrix<M>& oth)
{
 if (n == oth.n && m == oth.m)
 {
  Matrix<M> F(m, n);
  for (int i = 0; i < m; i++)
   for (int j = 0; j < n; j++)
    F.mass[i][j] = mass[i][j] - oth.mass[i][j];
  return F;
 }
 else
  throw - 1;
}

template<class M>
Matrix<M> Matrix<M>::operator*(const Matrix<M>& oth)
{
 if (n == oth.m)
 {
  Matrix<M> mat(m, (oth.n));
  for (int i = 0; i < mat.m; i++)
   for (int j = 0; j < mat.n; j++)
   {
    mat.mass[i][j] = 0;
    for (int k = 0; k < n; k++)
    {
     mat.mass[i][j] = mat.mass[i][j] + (mass[i][k] * oth.mass[k][j]);
    }
   }
  return mat;
 }
 else
  throw - 1;

}

template<class M>
Matrix<M> Matrix<M>::operator=(const Matrix<M>& oth)
{
 if (*this == oth)
  return *this;
 for (int i = 0; i < m; i++)
 {
  mass[i] = 0;
  delete[] mass[i];
 }
 delete[] mass;
 mass = 0;
 m = oth.m;
 n = oth.n;
 MemSize(m, n);
 for (int i = 0; i < m; i++)
 {
  for (int j = 0; j < n; j++)
  {
   mass[i][j] = oth.mass[i][j];
  }
 }
 return *this;
}

template<class M>
bool Matrix<M>::operator==(const Matrix<M>& oth)
{
 if (m == oth.m && n == oth.n)
 {

  for (int i = 0; i < m; i++)
   for (int j = 0; j < n; j++)
    if (mass[i][j] != oth.mass[i][j])
     return false;
  return true;
 }
 else
  return false;
}

template<class M>
M*& Matrix<M>::operator [](const int i)
{
 return mass[i];
}

template<class M>
ostream& operator<<(ostream& os, const Matrix<M>& mat)
{
 cout << "\n";
 for (int i = 0; i < mat.m; i++)
 {
  if (i > 0) os << endl;
  os << "|";
  for (int j = 0; j < mat.n; j++)
   os << mat.mass[i][j] << " ";
  os << "|";
 }
 return os;
}

template<class M>
istream& operator>>(istream& in, Matrix<M>& mat)
{
 if ((mat.GetM() != 0) || (mat.GetN() != 0))
 {
  for (int i = 0; i < mat.m; i++)
   delete[] mat.mass[i];
  delete[] mat.mass;
 }
 cout << "Enter size" << "\n";
 cout << "m = " << "\n";
 in >> mat.m;
 cout << "n = " << "\n";
 in >> mat.n;
 mat.MemSize(mat.m, mat.n);
 for (int i = 0; i < mat.m; i++)
 {
  cout << "Enter " << i + 1 << " line" << "\n";
  for (int j = 0; j < mat.n; j++)
   in >> mat.mass[i][j];
 }
 return in;
}

template<class M>
void Matrix<M>::SetRaz(int w, int l)
{
 m = w;
 n = l;
}

template<class M>
int Matrix<M>::Find(M el)
{
 int kol = 0;
 for (int i = 0; i < m; i++)
 {
  for (int j = 0; j < n; j++)
  {
   if (mass[i][j] == el)
   {
    kol = kol + 1;
   }
  }
 }
 return kol;
}