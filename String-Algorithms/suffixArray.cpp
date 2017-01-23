#include <bits/stdc++.h>

using namespace std;
#define MAXN 2005
string S, T;
int n, stp, cnt;
int P[MAXN][20];
int SA[MAXN];

struct entry{
    int rnk[2], i;
}L[MAXN];

bool cmp(entry e1, entry e2){
    return (e1.rnk[0] == e2.rnk[0] ? e1.rnk[1] < e2.rnk[1] : e1.rnk[0] < e2.rnk[0]);
}

int lcp(int x,int y){
    int res = 0;
    for (int k = stp - 1; k >= 0 && x < n && y < n; k--)
        if (P[k][x] == P[k][y])
            res += 1 << k, x += 1 << k, y += 1 << k;
    return res;
}

int main()
{
    cin >> S >> T;
    int m = S.size();
    S += "$";
    n = S.size();

    for (int i = 0; i < n; i++)
        P[0][i] = S[i] - 'a';

    for (stp = 1, cnt = 1; cnt >> 1 < n; stp++, cnt <<= 1){
        for (int i = 0; i < n; i++){
            L[i].rnk[0] = P[stp-1][i];
            L[i].rnk[1] = (i + cnt < n ? P[stp-1][i+cnt] : -1);
            L[i].i = i;
        }
        sort(L, L + n, cmp);
        for (int i = 0; i < n; i++)
            P[stp][L[i].i] = (i > 0 && L[i].rnk[0] == L[i-1].rnk[0] && L[i].rnk[1] == L[i-1].rnk[1]) ? P[stp][L[i-1].i] : i;
    }
}
