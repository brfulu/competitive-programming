#include <bits/stdc++.h>

using namespace std;
int n;

int main()
{
    cin >> n;
    double res = n;
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0)res *= (1.0 - 1.0 / (double)i);
        while (n % i == 0) n /= i;
    }
    if (n > 1) res *= (1.0 - 1.0 / (double)n);
    cout << int(res) << "\n";
}
