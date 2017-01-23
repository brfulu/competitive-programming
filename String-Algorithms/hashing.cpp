#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

#define MOD 1000000007
#define p 101

int hext(int h,int ch){
    return (1ll * h * p + ch) % MOD;
}

int main()
{
    int N;
    while (cin >> N){
        string T,S;
        cin >> T >> S;
        int HAPW[T.size()+5];
        HAPW[0] = 1;
        for (int i=1;i<=T.size();i++){
            HAPW[i] = (1ll * HAPW[i-1] * p) % MOD;
        }
        int thsh = 0;
        for (int i=0;i<T.size();i++){
            thsh = hext(thsh,T[i]);
        }
        int pref[S.size()];
        int shsh = 0;
        for (int i=0;i<S.size();i++){
            shsh = hext(shsh,S[i]);
            pref[i] = shsh;
        }
        for (int i=0;i<S.size();i++){
            int hsh = (MOD +  0ll +  pref[i+T.size()-1] - (( 1ll * (i > 0 ? pref[i-1] : 0) * HAPW[T.size()]) % MOD ) ) % MOD;
            if (hsh == thsh){
                cout << i << endl;
            }
        }

        cout << endl;
    }
}
