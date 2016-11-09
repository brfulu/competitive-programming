// branko_fu (Branko Fulurija)
// Cover Distance (Dynamic Programming)
// Given a distance ‘dist, count total number of ways to cover the distance with 1, 2 and 3 steps.
// Tyme complexity O(n)

#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005

int n, dp[MAXN];

int main(){
    cin >> n;

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    cout << dp[n] << "\n";
}
