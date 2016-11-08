// branko_fu (Branko Fulurija)
// Longest Increasing Subsequnce (Dynamic Programming)
// Return the length of the longest increasing subsequence in an array
// Time complexity O(nlogn)

#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005
int n, A[MAXN];
vector<int> vec;
vector<int>::iterator it;

int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> A[i];
    }

    for (int i = 0; i < n; i++){
        it = lower_bound(vec.begin(), vec.end(), A[i]);
        if (it == vec.end())
            vec.push_back(A[i]);
        else
            *it = A[i];
    }

    cout << (int)vec.size() << "\n";
}
