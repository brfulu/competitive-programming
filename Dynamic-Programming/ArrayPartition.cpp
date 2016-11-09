// branko_fu (Branko Fulurija)
// Array Partition (Dynamic Programming)
// Given a set of integers, the task is to divide it into two sets S1 and S2 such
// that the absolute difference between their sums is minimum.
// Time complexity O(maxn * maxsum)

#include <bits/stdc++.h>

using namespace std;

#define MAXN 1005
#define MAXSUM 10005
int n, A[MAXN];
bool dp[MAXSUM];
int sum = 0;

int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> A[i];
        sum += A[i];
    }
    dp[0] = 1;
    for (int i = 0; i < n; i++){
        for (int j = MAXSUM - 1; j >= 0; j--){
            if (j + A[i] >= MAXSUM || dp[j] == 0) continue;
            dp[j + A[i]] = 1;
        }
    }
    int minDiff = INT_MAX;

    for (int s = 0; s < MAXSUM; s++){
        if (dp[s] == 0) continue;
        minDiff = min(minDiff, abs(s - (sum - s)));
    }

    cout << minDiff << "\n";
}
