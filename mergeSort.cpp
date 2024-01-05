#include <bits/stdc++.h>
using namespace std;
void merge(int arr[] , int s , int e)
{
	int mid = s + (e-s)/2;
	int left_end = mid;
	int l1 = mid-s+1;
	int l2 = e-mid;
	int a[l1];
	int b[l2];
	int k = s;
	for (int i=0 ;i<l1 ;i++)
	{
		a[i] = arr[k++];
	}
	for (int i = 0 ; i<l2 ; i++){
		b[i] = arr[k++];
	}

	int l = 0;
	int r = 0;
	int c = s;
	while (l<l1 && r<l2)
	{
		if(a[l]<b[r])
		{
			arr[c++] = a[l++];
		}
		if(b[r]<a[l])
		{
			arr[c++] = b[r++];
		}
		if(a[l]==b[r])
		{
			arr[c++] = a[l++];
			arr[c++] = b[r++];
		}
	}
	while (l<l1)
	{
		arr[c++] = a[l++];
	}
	while (r<l2)
	{
		arr[c++] = b[r++];
	}
}
void mergeSort(int arr[] ,int s , int e)
{
	if (s>=e)
	{
		return;
	}
	int mid = s + (e-s)/2;
	mergeSort(arr,s,mid);
	mergeSort(arr,mid+1,e);
	merge(arr,s,e);
}
int main()
{
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0 ;i<n ;i++)
	{
		cin >> arr[i];
	}
	mergeSort(arr,0,n-1);
	for (int i:arr)
	{
		cout << i <<" ";
	}
}
