// http://www.usaco.org/index.php?page=viewproblem2&cpid=99

#include <bits/stdc++.h>

using namespace std;
#define MAXN 5005
int n, m, X[MAXN], C[MAXN];
int dp[MAXN];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> X[i];
    }
    sort(X + 1, X + 1 + n);
    for (int i = 1; i <= m; i++){
        cin >> C[i];
    }
    for (int i = m - 1; i > 0; i--){
        C[i] = min(C[i], C[i+1]);
    }

    memset(dp, 63, sizeof dp);
    dp[0] = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++){
            dp[i] = min(dp[i], C[X[i] - X[j] + 1] + dp[j-1]);
        }
    }
    cout << dp[n];
}
