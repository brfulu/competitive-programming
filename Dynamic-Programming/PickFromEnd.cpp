// branko_fu (Branko Fulurija)
// Pick from end Game (Dynamic Programming)
// Problem statement: Consider a row of n coins of values v1 . . . vn, where n is even. We play a game against
// an opponent by alternating turns. In each turn, a player selects either the first or last coin from the row, removes it from the row permanently,
// and receives the value of the coin. Determine the maximum possible amount of money we can definitely win if we move first.
// Time Complexity O(n^2)

#include <bits/stdc++.h>

using namespace std;
int n;
int A[105];
pair<int,int> dp[105][105];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) dp[i][i].first = A[i];

    for (int len = 2; len <= n; len++){
        for (int i = 0; i + len - 1 < n; i++){
            int j = i + len - 1;
            int left1 = A[i] + dp[i+1][j].second;
            int left2 = dp[i+1][j].first;
            int right1 = A[j] + dp[i][j-1].second;
            int right2 = dp[i][j-1].first;
            if (left1 > right1){
                dp[i][j].first = left1;
                dp[i][j].second = left2;
            }
            else {
                dp[i][j].first = right1;
                dp[i][j].second = right2;
            }
        }
    }
    cout << dp[0][n-1].first << " " << dp[0][n-1].second << endl;
}
