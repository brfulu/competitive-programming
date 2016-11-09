// branko_fu (Branko Fulurija)
// Longest Path in Matrix (Dynamic Programming)
// Given a n*n matrix where numbers all numbers are distinct and are distributed from range 1 to n2,
// find the maximum length path (starting from any cell) such that all cells along the path are increasing order with a difference of 1.
// Time Complexity O(n^2)

#include <bits/stdc++.h>

using namespace std;

#define MAXN 1005

int n, mat[MAXN][MAXN], dp[MAXN][MAXN];
int dx[4] = {1, -1, 0,  0};
int dy[4] = {0,  0, 1, -1};

int solve(int x, int y){

    int &ref = dp[x][y];
    if (ref != -1) return ref;

    ref = 1;

    for (int i = 0; i < 4; i++){
        int curx = x + dx[i];
        int cury = y + dy[i];
        if (curx < 0 || cury < 0 || curx >= n || cury >= n) continue;

        if (mat[curx][cury] == mat[x][y] + 1){
            ref += solve(curx, cury);
        }
    }

    return ref;
}

int main(){
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    memset(dp, -1, sizeof dp);
    int maxPath = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (dp[i][j] == -1)
                solve(i, j);
            maxPath = max(maxPath, dp[i][j]);
        }
    }

    cout << maxPath << "\n";
}
