#ifndef _SORT
#define	_SORT

using namespace std;
void CheckSort();

// ���������� Quick Sort
template <class T> int SortM(T* arr, int l, int r, int m); //������� �������� ����� �������� ������ �������
template <class T> void Swap(T* arr, int l, int r);		  //������ ������� ������� l � r
template <class T> void Sort(T* arr, int l, int r);		 //��������� �� ������� �� l �� r

// ���������� ��������
void Merge(int* dst, int* trg, int l1, int r1, int l2, int r2);  
void Sort(int* ar, int l, int r, int* tmp);

#endif