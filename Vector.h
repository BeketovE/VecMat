#pragma once
#include"Matrix.h"
#include <iostream>
#include <clocale>
#include <iomanip>
using namespace std;

template <class V>
class Vector
{
protected:
 int size;
 V* mass;
public:
 Vector();
 Vector(int r, V* A);
 Vector(Vector& B);
 ~Vector();
 void SetVector(V* C);
 V* GetVector();
 void SetSize(int n);
 int GetSize();
 Vector<V> operator+(const Vector& oth);
 Vector<V> operator-(const Vector<V>& oth);
 V operator*(const Vector<V>& oth);
 Vector<V> operator/(Vector<V>& oth);
 Vector<V> operator=(const Vector<V>& oth);
 bool operator==(const Vector<V>& oth);
 V operator[](const int i);
 template <class V>
 friend ostream& operator<<(ostream& os, const Vector<V>& vec);
 template <class V>
 friend istream& operator>>(istream& is, Vector<V>& vec);
 int Find(V p);
 clock_t BubbleSort();
 clock_t InserSort();
 clock_t QuickSort(int f, int l);
};

template<class V>
Vector<V>::Vector()
{
 size = 1;
 mass = new V[1];
 V a = 0;
 mass[0] = a;
}

template<class V>
Vector<V>::Vector(int r, V* A)
{
 mass = nullptr;
 try {
  if (r > 0)
  {
   size = r;
   mass = new V[size];
   for (int i = 0; i < size; i++)
   {
    mass[i] = A[i];
   }
  }
  else throw 1;
 }
 catch (int i)
 {
  cout << "Error mas=0" << "\n";
  exit(0);
 }
}

template<class V>
Vector<V>::Vector(Vector& B)
{
 mass = nullptr;
 size = B.GetSize();
 mass = new V[size];
 for (int i = 0; i < size; i++)
 {
  mass[i] = B.mass[i];
 }
}

template<class V>
Vector<V>::~Vector()
{
 if (mass != 0)
 {
  mass = 0;
  delete[] mass;
 }
 size = 0;
}

template<class V>
void Vector<V>::SetVector(V* C)
{
 int i = strlen(C);
 if (mass != 0)
 {
  mass = 0;
  delete[] mass;
 }
 size = i;
 mass = new V[size];
 for (int k = 0; k < i; k++)
 {
  mass[k] = C[k];
 }
}

template<class V>
V* Vector<V>::GetVector()
{
 return mass;
}

template<class V>
void Vector<V>::SetSize(int n)
{
 size = n;
}

template<class V>
int Vector<V>::GetSize()
{
 return size;
}

template<class V>
Vector<V> Vector<V>::operator+(const Vector& oth)
{
 if (size == oth.size)
 {
  Vector<V> vector(size, oth.mass);
  for (int i = 0; i < size; i++)
   vector.mass[i] = mass[i] + oth.mass[i];
  return vector;
 }
 else
  throw - 1;
}

template<class V>
Vector<V> Vector<V>::operator-(const Vector<V>& oth)
{
 if (size == oth.size)
 {
  Vector<V> vector(size, oth.mass);
  for (int i = 0; i < size; i++)
   vector.mass[i] = mass[i] - oth.mass[i];
  return vector;
 }
 else
  throw - 1;
}

template<class V>
V Vector<V>::operator*(const Vector<V>& oth)
{
 V res = 0;
 if (size == oth.size)
 {
  for (int i = 0; i < size; i++)
   res = res + (mass[i] * oth.mass[i]);
  return res;
 }
 else
  throw - 1;
}

template<class V>
Vector<V> Vector<V>::operator/( Vector<V>& oth)
{

 if (size != oth.GetSize())throw length_error("Error");
 Vector<V> K;
 K = *this;
 for (int i = 0; i < size; i++)
 {
  if (K.mass[i] != 0)
  {
   K.mass[i] = K.mass[i] / oth.mass[i];
  }

 }
 return K;

}

template<class V>
Vector<V> Vector<V>::operator=(const Vector<V>& oth)
{
 if (*this == oth)
  return *this;
 delete[] mass;
 this->size = oth.size;
 mass = new V[size];
 for (int i = 0; i < size; i++)
  mass[i] = oth.mass[i];
 return *this;
}

template<class V>
bool Vector<V>::operator==(const Vector<V>& oth)
{
 int k = 0;
 if (size == oth.size)
 {
  for (int i = 0; i < size; i++)
  {
   if (mass[i] == oth.mass[i])
   {
    k = k + 1;
   }
  }
  if (k == size)
  {
   return true;
  }
  else return false;
 }
 else
  return false;
}

template<class V>
V Vector<V>::operator[](const int i)
{
 return mass[i];
}

template<class V>
ostream& operator<<(ostream& os, const Vector<V>& vec)
{
 os << "(";
 for (int i = 0; i < vec.size; i++)
 {
  os << vec.mass[i];
  if (i < vec.size - 1)
   os << " ";
 }
 os << ")^T";
 return os;
}

template<class V>
istream& operator>>(istream& is, Vector<V>& vec)
{
 cout << "Size:" << "\n";
 is >> vec.size;
 V* mas;
 mas = new V[vec.size];
 for (int i = 0; i < vec.size; i++)
 {
  cout << "[" << i << "]" << "\n";
  is >> mas[i];
 }
 Vector<V> Vec(vec.size, mas);
 vec = Vec;
 mas = 0;
 delete[] mas;
 return is;
}

template<class V>
int Vector<V>::Find(V a)
{
 int kol = 0;
 for (int i = 0; i < size; i++)
 {
  if (mass[i] == a)
  {
   kol = kol + 1;
  }
 }
 return kol;
}

template<class V>
clock_t Vector<V>::BubbleSort()
{
 clock_t start, finish;
 start = clock();
 V tmp = 0;
 int i, j = 0;
 start = clock();
 for (int i = 0; i < size; i++)
 {
  for (int j = 0; j < i; j++)
  {
   if (mass[j] > mass[j + 1])
   {
    tmp = mass[j];
    mass[j] = mass[j + 1];
    mass[j + 1] = tmp;
   }
  }
 }
 finish = clock();
 return (finish - start);
}

template<class V>
clock_t Vector<V>::InserSort()
{
 int k = 0;
 clock_t start, finish;
 start = clock();
 V tmp;

 for (int i = 1; i < size; i++)
 {
  tmp = mass[i];
  k = i - 1;
  while (k >= 0 && mass[k] > tmp)
  {
   mass[k + 1] = mass[k];
   k = k - 1;
  }
  mass[k + 1] = tmp;
 }
 finish = clock();
 return (finish - start);
}

template<class V>
clock_t Vector<V>::QuickSort(int f, int l)
{
 clock_t t1, t2, t3;
 t1 = clock();
 int i = f, j = l;
 V tmp;
 V x = mass[(f + l) / 2];

 do {
  while (mass[i] < x)
   i++;
  while (mass[j] > x)
   j--;

  if (i <= j)
  {
   if (i < j)
   {
    tmp = mass[i];
    mass[i] = mass[j];
    mass[j] = tmp;
   }
   i++;
   j--;
  }
 } while (i <= j);

 if (i < l)
  t3 = QuickSort(i, l);
 if (f < j)
  t3 = QuickSort(f, j);
 t2 = clock();
 return t2 - t1;
}