#include "Header.h"
#include "Matrix.h"
#include "Vector.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <clocale>
#include <malloc.h>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
 cout << "Vector1" << "\n";
 Vector<int> A;
 cin >> A;
 cout << "Vozmem Vector1" << "\n";
 cout << A << "\n";
 int K = 0;
 int arr[] = { 1,2,3,4,5,6,7 };
 int arrr[] = { 4,5,6,7,8,9,10 };
 Vector<int> B(5, arr);
 Vector<int> C(5, arrr);
 Vector<int> D;
 cout << "++++" << "\n";
 D = B + C;
 cout << D << "\n";
 cout << "****" << "\n";
 K = B * C;
 cout << K << "\n";
 cout << "----" << "\n";
 D = B - C;
 cout << D << "\n";
 cout << "////" << "\n";
 D = C / B;
 cout << D << "\n";
 cout << "SORTS" << "\n" << "\n";
 cout << "BubbleSort" << "\n";
 int t = clock();
 int arrrre[] = { 9,2,3,4,5,6,7 };
 Vector<int> AH(5, arrrre);
 t = AH.BubbleSort();
 cout << "TimeSort:" << t << "\n";
 cout << "SortVec:" << "\n";
 cout << AH << "\n" << "\n";
 int arrrr[] = { 6,7,8,9,1,2,3 };
 Vector<int> U(6, arrrr);
 cout << "QuickSort" << "\n";
 int o = clock();
 o = U.QuickSort(0, B.GetSize() - 1);
 cout << "TimeSort:" << o << "\n";
 cout << "SortVerc:" << "\n";
 cout << U << "\n" << "\n";
 int arrrra[] = { 4,5,6,7,8,9,1 };
 Vector<int> E(4, arrrra);
 cout << "InserSort" << "\n";
 int w = clock();
 w = E.InserSort();
 cout << "TimeSort:=" << w << "\n";
 cout << "SortVec:" << "\n";
 cout << E << "\n" << "\n";
 cout << "/*-----------------------------------------------------------------------------------------------------*/" << "\n";
 cout << "Matrix1" << "\n";
 Matrix<int> AB;
 cin >> AB;
 cout << "KvadratnayaMatrix" << AB << "\n";
 cout << "Matrix toy dzhe razmer!!!!";
 cout << "Matrix2" << "\n";
 Matrix<int> AC;
 cin >> AC;
 cout << "KvadratnayaMatrix" << AB << "\n";
 Matrix<int> ABC;
 cout << "++++" << "\n";
 ABC = AB + AC;
 cout << ABC << "\n";
 cout << "****" << "\n";
 ABC = AB * AC;
 cout << ABC << "\n";
 cout << "----" << "\n";
 ABC = AB - AC;
 cout << ABC << "\n";
 cout << "Vhosjdeniaa" << "\n";
 cout << "Vector*Matrix" << "\n";
 int arrar[] = { 1,2,3 };
 Vector<int> V1(3, arrar);
 Matrix<int> V2;
 Matrix<int> V3;
 cout << "Razmernost (1*3)" << "\n";
 cin >> V2;
 V3 = V1 * V2;
 cout << V3 << "\n";
 cout << "Matrix*Vector" << "\n";
 Matrix<int> VV;
 cout << "Razmernost (3*3)" << "\n";
 cin >> VV;
 int arrereq[] = { 9,8,7 };
 Vector<int> IO(1, arrereq);
 Vector<int> I;
 I = VV * IO;
 cout << I << "\n";
 int uu;
 uu = E.Find(3);
 cout << uu << "\n";
 int rr;
 rr = AB.Find(2);
 cout << rr << "\n";
 return 0;
}