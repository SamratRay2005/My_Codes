#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long

class ST {
public:
    vector<int> seg, lz;

    ST(int n) {
        seg.resize(4 * n + 1);
        lz.resize(4 * n + 1, 0); // Initialize lazy array to zero
    }

    void build(int ind, int low, int high, const vector<int>& arr) {
        if (low == high) {
            seg[ind] = arr[low];
            return;
        }
        int mid = (low + high) >> 1;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    void update(int ind, int low, int high, int l, int r, int val) {
        // Update the previous remaining update and propagate downwards
        if (lz[ind] != 0) {
            // Propagate the lazy update downwards
            seg[ind] += (high - low + 1) * lz[ind];
            if (low != high) {
                lz[2 * ind + 1] += lz[ind];
                lz[2 * ind + 2] += lz[ind];
            }
            lz[ind] = 0; // Clear the lazy value
        }

        // No overlap
        if (high < l || r < low) {
            return;
        }

        // Complete overlap
        if (low >= l && high <= r) {
            seg[ind] += (high - low + 1) * val;
            // Children update/downward propagation
            if (low != high) {
                lz[2 * ind + 1] += val;
                lz[2 * ind + 2] += val;
            }
            return;
        }

        // Partial overlap
        int mid = (low + high) >> 1;
        update(2 * ind + 1, low, mid, l, r, val);
        update(2 * ind + 2, mid + 1, high, l, r, val);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    int query(int ind, int low, int high, int l, int r) {
        // Update if any updates are remaining
        if (lz[ind] != 0) {
            seg[ind] += (high - low + 1) * lz[ind];
            if (low != high) {
                lz[2 * ind + 1] += lz[ind];
                lz[2 * ind + 2] += lz[ind];
            }
            lz[ind] = 0; // Clear the lazy value
        }

        // No overlap 
        if (high < l || r < low) {
            return 0;
        }

        // Complete overlap
        if (low >= l && high <= r) {
            return seg[ind];
        }

        // Partial overlap
        int mid = (low + high) >> 1;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return left + right;
    }
};

int main() {
    int n = 10; // Size of the array
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Example array

    ST segmentTree(n);
    segmentTree.build(0, 0, n - 1, arr);

    // Update range [2, 5] by adding 10
    segmentTree.update(0, 0, n - 1, 2, 5, 10);

    // Query the sum in range [0, 5]
    int result = segmentTree.query(0, 0, n - 1, 0, 5);
    cout << "Sum from index 0 to 5: " << result << endl; // Output the result

    return 0;
}