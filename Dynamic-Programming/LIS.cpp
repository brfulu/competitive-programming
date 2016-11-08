// branko_fu (Branko Fulurija)
// Longest Increasing Subsequnce (Dynamic Programming)
// Return the length of the longest increasing subsequence in an array
// Time complexity O(n^2)

#include <bits/stdc++.h>

using namespace std;

#define MAXN 1005
int n, A[MAXN], dp[MAXN];

int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> A[i];
    }

    for (int i = 0; i < n; i++){
        dp[i] = 1; // base case
    }
    // comput dp table
    for (int i = 0; i < n; i++){
        for (int j = 0; j < i; j++){
            if (A[i] > A[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++){
        res = max(res, dp[i]);
    }

    cout << "LIS = " << res << "\n";
}
