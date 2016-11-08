// branko_fu (Branko Fulurija)
// Linear Search
// Find the first index of some number, return -1 if not present in array
// Time complexity O(n)

#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005
int n, A[MAXN];

int linearSearch(int value){
    for (int i = 0; i < n; i++){
        if (A[i] == value)
            return i;
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
    cout << linearSearch(val) << "\n";
}
