#include <bits/stdc++.h>

using namespace std;
bitset<100000000> sieve;
long long primes[1000000];
int n = 0;

bool prime(long long a){
    if (a == 2)return 1;
    if (a % 2 == 0)return 0;
    for (int i = 0; i < n && primes[i] * primes[i] <= a; i++){
        if (a % primes[i] == 0)
            return false;
    }
    for (int i = 5000001; i <= sqrt(a); i += 2){
        if (a % i == 0)
            return false;
    }
    return true;
}

int main()
{
    for (int i = 2; i <= 5000000; i++){
        if (!sieve[i]){
            primes[n++] = i;
            if (i >= 3000)continue;
            for (int j = i * i; j < 5000000; j += i)
                sieve[j] = 1;
        }
    }
    int t;
    cin >> t;
    while (t--){
        long long a;
        cin >> a;
        if (prime(a))cout << "prime\n";
        else cout << "composite\n";
    }
}
