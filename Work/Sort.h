#ifndef _SORT
#define	_SORT

using namespace std;
void CheckSort();

int SortM(int* arr, int l, int r, int m); //находит итоговое место элемента внутри массива
void Swap(int arr, int l, int r);		  //меняет местами границы l и r
void Sort(int* arr, int l, int r);		 //сортирует на отрезке от l до r


#endif