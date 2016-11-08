// branko_fu (Branko Fulurija)
// Binary Search algorithm
// Finds the first index of a given number in a sorted array, returns -1 if not present in array
// Time complexity O(logN)

#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005

int n, arr[MAXN];

int binarySearch(int value){
    int lo = 0, hi = n - 1;
    while (lo < hi){
        int mid = (lo + hi) / 2;
        if (arr[mid] < value)
            lo = mid + 1;
        else
            hi = mid;
    }
    if (arr[lo] == value)
        return lo;
    else
        return -1;
}

int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int value;
    cin >> value;
    cout << "First index of " << value << " = " <<  binarySearch(value) << "\n";
}
