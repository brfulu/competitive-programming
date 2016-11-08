// branko_fu (Branko Fulurija)
// Ternary Search
// Given a unimodal function f(x) = 2x^2 - 12x + 7, and several intervals,
// for each interval find the minimum value for f(x) in that range.
// Time complexity O(log3(N))

#include <bits/stdc++.h>

using namespace std;

double f(double x){
    return 2*x*x - 12*x +7;
}

double ternarySearch(double lo, double hi){
    for (int i = 0; i < 200; i++){
        double mid1 = lo + (hi - lo) / 3;
        double mid2 = hi - (hi - lo) / 3;
        if (f(mid1) < f(mid2))
            hi = mid2;
        else
            lo = mid1;
    }
    double x = lo;
    return f(lo);
}

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        cout << ternarySearch(l, r) << "\n";
    }
}
