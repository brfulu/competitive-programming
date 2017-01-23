    #include <bits/stdc++.h>

using namespace std;
long long n;
vector<int> primes = {2, 3, 11 ,13};

long long gcd(long long a, long long b){
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main()
{
    cin >> n;
    long long res = 0;
    for (int mask = 1; mask < 1 << (int)primes.size(); mask++){
        long long cur = 1;
        long long add = -1;
        for (int j = 0; j < 10; j++){
            if (mask & (1 << j)){
                add *= -1;
                cur *= primes[j];
            }
        }
        res += add * (n / cur);
    }
    cout << res / gcd(res, n) << " " << n / gcd(res, n) << "\n";
}
