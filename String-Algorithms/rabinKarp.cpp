#include <iostream>

using namespace std;
#define MOD 34445333343437LL
#define P 101
typedef long long ll;

ll hext(ll h,int ch){
    return (h * P + ch) % MOD;
}

bool ssearch(string S,string T){
    ll thsh = 0;
    for (int i=0;i<T.size();i++)
        thsh = hext(thsh, T[i]);
    ll PM = 1;
    int M = T.size();
    for (int i=0;i<M-1;i++)
        PM = (PM * P) % MOD;
    ll hsh = 0;
    for (int i=0;i<M;i++)
        hsh = hext(hsh,S[i]);
    if (hsh == thsh)return true;
    for (int i=M;i<S.size();i++){
        hsh = (hsh + MOD - PM * (S[i - M]) % MOD) % MOD;
        hsh =  hext(hsh,S[i]);
        if (hsh == thsh)return true;
    }
    return false;
}

int main()
{
    string S,T;
    cin >> S >> T;
    if (ssearch(S,T)){
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}
