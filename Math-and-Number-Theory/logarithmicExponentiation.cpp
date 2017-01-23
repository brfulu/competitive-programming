#include <iostream>

using namespace std;

long long logPow(long long a,int n){
    long long res = 1;
    while (n){
        if (n & 1)
            res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

int main()
{
    int a, n;
    cin >> a >> n;
    cout << logPow(a, n) << "\n";
}
