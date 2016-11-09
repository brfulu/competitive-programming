// branko_fu (Branko Fulurija)
// 0/1 Knapsack (Dynamic Programming)
// Given weights and values of n items, put these items in a
// knapsack of capacity C to get the maximum total value in the knapsack.
// Time Complexity O(n * C)

#include <bits/stdc++.h>

using namespace std;
#define MAXN 2005
int N,C,v[MAXN],w[MAXN],dp[MAXN][MAXN];

int main()
{
    cin >> C >> N;
    for (int i=1;i<=N;i++){
        cin >> w[i] >> v[i];
    }
    for (int i=1;i<=N;i++){
        for (int j=0;j<=C;j++){
            if (w[i] > j)dp[i][j] = dp[i-1][j];
            else {
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]] + v[i]);
            }
        }
    }
    cout << dp[N][C] << endl;
}
