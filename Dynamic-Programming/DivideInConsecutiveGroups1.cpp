#include <bits/stdc++.h>

using namespace std;
#define MAXN 2005
int n, H[MAXN], W[MAXN], L;
int dp[MAXN];
int sum[MAXN][MAXN];
int maxi[MAXN][MAXN];

int main()
{
    cin >> n >> L;
    for (int i = 1; i <= n; i++){
        cin >> H[i] >> W[i];
    }

    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            sum[i][j] = W[j] + sum[i][j-1];

    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            maxi[i][j] = max(H[j], maxi[i][j-1]);

    memset(dp, 63, sizeof dp);
    dp[0] = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++){ // zadnja grupa je [j, i]
            if (sum[j][i] <= L)
                dp[i] = min(dp[i], maxi[j][i] + dp[j-1]);
        }
    }
    cout << dp[n];
}
