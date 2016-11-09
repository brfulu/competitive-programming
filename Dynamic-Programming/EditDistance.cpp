// branko_fu (Branko Fulurija)
// Edit Distance (Dynamic Programming)
// Given 2 strings, and and operations (insert, remove, replace), return the
// minimum number of operations to make the strings equal
// Time complexity O(n^2)

#include <bits/stdc++.h>

using namespace std;

#define MAXN 5005
int dp[MAXN][MAXN];

int editDistance(string s1, string s2){
    int n = s1.size();
    int m = s2.size();

    for (int i = 0; i <= n; i++)
        dp[i][0] = i;
    for (int j = 0; j <= m; j++)
        dp[0][j] = j;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
        }
    }

    return dp[n-1][m-1];
}

int main(){
     string s1, s2;
     cin >> s1 >> s2;
     cout << editDistance(s1, s2) << "\n";
}
