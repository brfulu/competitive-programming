// https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/rhezo-and-prime-problems/
#include <bits/stdc++.h>

using namespace std;
#define MAXN 5005
int n, A[MAXN], res;
int sum[MAXN];
int dp[MAXN];

bool isPrime(int x){
    if (x < 2)return 0;
    for (int i = 2; i <= sqrt(x); i++){
        if (x % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> A[i];
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i-1] + A[i];

    for (int i = 1; i <= n; i++){
        dp[i] = dp[i-1];
        for (int j = 1; j <= i; j++){
            if (!isPrime(i - j + 1))continue;
            dp[i] = max(dp[i], sum[i] - sum[j-1] + (j - 2 >= 0 ? dp[j-2] : 0));
        }
        res = max(res, dp[i]);
    }
    cout << res;
}
