// branko_fu (Branko Fulurija)
// Jump Search
// Find index of target value in a sorter array.
// The idea is to divide the array in blocks of certain size and jump around the blocks
// until we find one that possibly contains our target
// Now we can just do a linear search in that block.
// The optimal block size is the square root of the size of the array, because we wiil jump over no more
// than sqrt(N) blocks, and there are sqrt(N) elements in the block in which we do a linear search.
// Time complexity O(sqrt(N))

#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005
int n, A[MAXN];

int jumpSearch(int value){
    int BLOCK_SIZE = sqrt(n);

    int pos = 0;
    while (pos < n && A[pos + BLOCK_SIZE - 1] < value){
        pos += BLOCK_SIZE;
    }

    if (pos >= n) return -1;

    int limit = pos + BLOCK_SIZE;
    for (int i = pos; i < limit; i++){
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

    while (1){
    int val;
    cin >> val;
    cout << jumpSearch(val) << "\n";
}
}
