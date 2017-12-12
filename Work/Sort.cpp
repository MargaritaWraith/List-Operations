#include "stdafx.h"
#include <iostream>
#include "Sort.h"

void CheckSort()
{

}

void Swap(int* arr, int l, int r)
{
	int t;
	t = arr[l];
	arr[l] = arr[r];
	arr[r] = t;
}


int SortM(int* arr, int l, int r, int m)
{
	while (l<m || r>m)
	{
		while (l < m)
			if (arr[l] < arr[m]) l++;
		while (r > m)
			if (arr[r] >= arr[m]) r--;
		if (l<m && r>m)
		{
			Swap(arr, l, r);
			++l;
			--r;
		}
		else
		{
			if (l < m && m == r)
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