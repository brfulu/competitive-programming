#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    for (int i=2;i<=sqrt(n);i++){
        int cnt = 0;
        while (n % i == 0){
            n /= i;
            cnt++;
        }
        if (cnt == 0)continue;
        cout << i << "^" << cnt << " * ";
    }
    if (n > 1){
        cout << n << endl;
    }
    cout << endl;
}
