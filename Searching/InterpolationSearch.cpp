// branko_fu (Branko Fulurija)
// Interpolation Search
// Find the index of some number, return -1 if not present in array.
// Works better than Binary Search when the elements of the array are uniformly distributed.
// Binary Search always checks the middle element, but interpolation search may go to
// different locations depending on the key value being searched.
// It uses a formula that for values closer to A[hi] gives a higher pos, and a smaller otherwise.
// Time complexity O(log log n)

#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005
int n, A[MAXN];

int interpolationSearch(int value){
    int lo = 0, hi = n - 1;
    while (lo < hi){
        int pos = lo + ((double)(hi-lo) / (A[hi]-A[lo])) * (value - A[lo]);

        if (pos < lo)
            return -1;

        if (A[pos] == value)
            return pos;

        if (A[pos] < value)
            lo = pos + 1;

        else
            hi = pos - 1;
    }
    return -1;
}

int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> A[i];
    }

    int val;
    cin >> val;
    cout << interpolationSearch(val) << "\n";
}
