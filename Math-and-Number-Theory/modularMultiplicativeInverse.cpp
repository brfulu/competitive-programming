#include <bits/stdc++.h>

using namespace std;
#define MOD 1000000007

int modPow(long long a, int n){
    long long res = 1;
    while (n){
        if (n & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        n >>= 1;
    }
    return res % MOD;
}

int main()
{
    int a;
    cin >> a;
    cout << modPow(a, MOD - 2) % MOD << "\n";
}
