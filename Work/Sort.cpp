#include "stdafx.h"
#include <iostream>
#include "Sort.h"

void CheckSort()
{
	int Array[15] = { 42,3,7,8,5,2,6,9,11,13,15,0,6,1,7 };
	int TempAr[15] = { 0 };
	Sort(Array, 0, 14, TempAr);
	for (int i = 0; i < sizeof(Array) / sizeof(int); i++)
	{
		cout << Array[i] << "   ";
	}
}

template <class T> void Swap(T* arr, int l, int r)
{
	int t = arr[l];
	arr[l] = arr[r];
	arr[r] = t;
}

template <class T>
int SortM(T* arr, int l, int r, int m)
{
	while (l<m || r>m)
	{
		while (arr[l] < arr[m])
			l++;
		while (arr[r] >= arr[m] && r > m)
			r--;
		if (l<m && r>m)
		{
			Swap(arr, l, r);
			++l;
			--r;
		}
		else if (l < m && m == r)
		{
			Swap(arr, l, m);
			m = l;
		}
		else if (r > m && l == m)
		{
			Swap(arr, r, m);
			m = r;
		}
	}
	return m;
}

template <class T> void Sort(T* arr, int l, int r)
{
	if (l >= r) return;
	int m = (l + r) / 2;
	m = SortM(arr, l, r, m);
	Sort(arr, l, m - 1);
	Sort(arr, m + 1, r);
}

void Merge(int* dst, int* trg, int l1, int r1, int l2, int r2)
{										
	/*cout << endl<<"-----Merge--start----" << endl;
	for (int i = l1; i <= r1; i++)	cout << dst[i] << ' ';
	cout << "    "<<endl;
	for (int i = l2; i <= r2; i++)	cout << dst[i] << ' ';
	cout << endl;*/

	int i1 = l1, i2 = l2, j = l1;
	while (i1 <= r1 && i2 <= r2)
	{
		if (dst[i1] < dst[i2])
		{
			trg[j] = dst[i1]; j++; i1++;
		}
		else
		{
			trg[j] = dst[i2]; j++, i2++;
		}
	}
	if (i1 > r1 && i2 <= r2)
		for (; i2 <= r2; i2++, j++)
			trg[j] = dst[i2];
	else		for (; i1 <=r1; i1++, j++)			trg[j] = dst[i1];	for (int i = l1; i <= r2; i++) cout << trg[i] << ' ';//	cout << "---merge--end---" << endl;}

void Sort(int* ar, int l, int r, int* tmp)
{
	if (l >= r) return;
	int m = (l + r) / 2;
	Sort(ar, l, m, tmp);
	Sort(ar, m + 1, r, tmp);
	Merge(ar, tmp, l, m, m + 1, r);
	for (int i = l; i <= r; i++)
		ar[i] = tmp[i];
	return;
}