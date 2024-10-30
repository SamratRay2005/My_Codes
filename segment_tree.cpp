#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long

void built(int ind , int low , int high, int arr[] , int seg[])
{
    if (low == high)
    {
        seg[ind] = arr[low];
        return;
    }
    int mid = (low + high)/2;
    built(2*ind + 1 , low , mid , arr , seg);
    built(2*ind + 2 , mid + 1 , high , arr , seg);
    seg[ind] = min(seg[2*ind + 1], seg[2*ind + 2]); 
}

// l and r are the ranges given in quary
int quary(int ind , int low , int high ,int l , int r , int seg[])
{
    // no overlap case (r<low || high<l)
    if (l > high || r < low)
    {
        return INT_MAX;
    }
    // complete overlap
    if (low>=l && high>=r)
    {
        return seg[ind];
    }
    // partial overlap (go left then go right then min of both)
    int mid = (low + high)/2;
    int left = quary(2*ind+1 , low , mid ,l ,r , seg);
    int right = quary(2*ind+1 , mid+1 , high ,l ,r , seg);
    return min(left,right);
}
int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   ll n;
   cin >> n;
   int arr[n];
   for (int i = 0 ; i<n ;i++)
   {
        cin >> arr[i];
   }
   // 4*n is proved to be the safe size of segment tree
   int seg[4*n];
   built(0 , 0 , n-1 , arr, seg);
   int q;
   cin >> q;
   while (q--)
   {
    int l , r;
    cin >> l >> r;
    cout << quary(0 , 0 , n-1 , l-1 , r-1 , seg) << endl;
   }

}