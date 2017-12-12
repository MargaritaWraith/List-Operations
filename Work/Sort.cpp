#include "stdafx.h"
#include <iostream>
#include "Sort.h"

void CheckSort()
{
	int Array[15] = { 42,3,7,8,5,2,6,9,11,13,15,0,6,1,7 };
	Sort(Array, 0, 14);
	for (int i = 0; i < sizeof(Array) / sizeof(int); i++)
	{
		cout << Array[i] << "\t";
	}
}

void Swap(int* arr, int l, int r)
{
	int t = arr[l];
	arr[l] = arr[r];
	arr[r] = t;
}
	  
int SortM(int* arr, int l, int r, int m)
{
	while (l<m || r>m)
	{
		while (arr[l] < arr[m])
			l++;
		while (arr[r] >= arr[m] && r>m)
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

void Sort(int* arr, int l, int r)
{
	if (l >= r) return;
	int m = (l + r) / 2;
	m = SortM(arr, l, r, m);
	Sort(arr, l, m - 1);
	Sort(arr, m + 1, r);
}