#include <bits/stdc++.h>
using namespace std;
int partition(int arr[] , int low ,int high)
{
    int c = low;
    int pivot = arr[high];
    for (int i = low ;i<high ; i++)
    {
        if(arr[i]<pivot)
        {
            swap(arr[c++],arr[i]);
        }
    }
    swap(arr[c],arr[high]);
    return c;
}
void quickSort(int arr[],int low , int high)
{
    if (low<=high)
    {
        int p = partition(arr,low,high);
        quickSort(arr,low,p-1);
        quickSort(arr,p+1,high);
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0 ; i<n ;i++)
    {
        cin >> arr[i];
    }
    quickSort(arr,0,n-1);
    for (int i:arr)
    {
        cout << i <<" ";
    }

}