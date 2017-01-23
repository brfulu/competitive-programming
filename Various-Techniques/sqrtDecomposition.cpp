
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
#define MAXN 311111
#define BLOCK 450
int n, q, A[MAXN];
long long ans[MAXN];
long long cnt[1111111];
long long answer = 0;

struct node {
    int L, R, i;
}Q[MAXN];

set<int> S;

bool cmp(node a, node b){
    if (a.L / BLOCK != b.L / BLOCK)
        return a.L / BLOCK < b.L / BLOCK;
    else
        return a.R < b.R;
}

void add(int pos){
    int v = A[pos];
    cnt[v]++;
    long long c = cnt[A[pos]];
    answer += -1 * (c - 1) * (c - 1) * v + c * c * v;
}

void remove(int pos){
    int v = A[pos];
    cnt[v]--;
    long long c = cnt[v];
    answer += -1 * (c + 1) * (c + 1) * v + c * c * v;
}

int main()
{
    scanf("%d", &n);
    scanf("%d", &q);

    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    for (int i = 0; i < q; i++){
        scanf("%d %d", &Q[i].L, &Q[i].R);
        Q[i].L--; Q[i].R--;
        Q[i].i = i;
    }

    sort(Q, Q + q, cmp);

    int currL = 0, currR = 0;

    for (int i = 0; i < q; i++){
        int L = Q[i].L, R = Q[i].R;
        while (currL < L){
            remove(currL);
            currL++;
        }
        while (currL > L){
            add(currL - 1);
            currL--;
        }
        while (currR <= R){
            add(currR);
            currR++;
        }
        while (currR > R + 1){
            remove(currR - 1);
            currR--;
        }
        ans[Q[i].i] = answer;
    }

    for (int i = 0; i < q; i++)
        printf("%I64d\n", ans[i]);
}
