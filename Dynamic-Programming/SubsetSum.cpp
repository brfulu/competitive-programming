// branko_fu (Branko Fulurija)
// Subset Sum (Dynamic Programming)
// Given a set of non-negative integers, and a value sum, determine
// if there is a subset of the given set with sum equal to given sum.
// Time Complexity (n * sum)

#include <bits/stdc++.h>

using namespace std;

#define MAXSUM 20005
#define MAXN 1005

int n, sum, A[MAXN];
bool dp[MAXSUM];

int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> A[i];
    }

    cin >> sum;
    dp[0] = 1;
    for (int i = 0; i < n; i++){
        for (int s = sum; s >= 0; s--){
            if (!dp[s]) continue;
            dp[s + A[i]] = 1;
        }
    }

    if (dp[sum])
        cout << "Found subset\n";
    else
        cout << "Not found\n";
}
