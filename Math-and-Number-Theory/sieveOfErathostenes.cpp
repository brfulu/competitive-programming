#include <bits/stdc++.h>

using namespace std;
vector<int> primes;
vector<int> sieve(10000005);

int main()
{
    int N;
    cin >> N;
    sieve[0] = sieve[1] = 1;
    for (int i=2;i<=10000000;i++){
        if (sieve[i])continue;
        primes.push_back(i);
        for (int j=i+i;j<=10000000;j+=i){
            sieve[j] = 1;
        }
    }
    for (int i=0;primes[i] <= N;i++){
        cout << primes[i] << " ";
    }
    cout << endl;
}
