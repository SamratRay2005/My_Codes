#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long

class SGTree{
    public:
    vector<int> seg;
    SGTree(int n)
    {
        // 4*n is proved to be the safe size of segment tree
        seg.resize(4*n+1);
    }
    void built(int ind , int low , int high, int arr[])
    {
        if (low == high)
        {
            seg[ind] = arr[low];
            return;
        }
        int mid = (low + high)/2;
        built(2*ind + 1 , low , mid , arr);
        built(2*ind + 2 , mid + 1 , high , arr);
        seg[ind] = min(seg[2*ind + 1], seg[2*ind + 2]); 
    }

    // l and r are the ranges given in quary
    int quary(int ind , int low , int high ,int l , int r)
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
        int left = quary(2*ind+1 , low , mid ,l ,r);
        int right = quary(2*ind+1 , mid+1 , high ,l ,r);
        return min(left,right);
    }
    void update(int ind , int low ,int high , int i , int val)
    {
        if (low == high)
        {
            seg[ind] = val;
            return;
        }
        int mid = (low + high)/2;
        if (i<=mid) update(2*ind+1 , low , mid ,i ,  val);
        else update(2*ind+2 , mid+1 , high ,i ,   val);
        seg[ind] = min(seg[2*ind + 1], seg[2*ind + 2]); 
    }
};

int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   ll n;
   cin >> n;
   int arr[n];
   for (int i = 0 ; i<n ;i++)
   {
        cin >> arr[i];
   }
   SGTree sg1(n);
   sg1.built(0 , 0 , n-1 , arr);
   int q;
   cin >> q;
   while (q--)
   {
    int l , r;
    cin >> l >> r;
    cout << sg1.quary(0 , 0 , n-1 , l-1 , r-1) << endl;
   }

}
