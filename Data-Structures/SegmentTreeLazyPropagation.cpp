// branko_fu (Branko Fulurija)
// Segment tree Lazy Propagation
// Update - increase every number in range by val - O(logn)
// Query  - get sum in range O(logn)

#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005
int n;

struct node{
    int val, lazy;
    node (){
        val = 0;
        lazy = 0;
    }
}tree[4*MAXN];

void propagate(int pos, int val){
    tree[pos*2].lazy += val;
    tree[pos*2].lazy += val;
}

void update(int lo, int hi, int qlo, int qhi, int val, int pos){
    if (tree[pos].lazy != 0){
        tree[pos].val += (hi - lo + 1) * tree[pos].lazy;
        if (lo != hi)
            propagate(pos, tree[pos].lazy);
        tree[pos].lazy = 0;
    }

    if (lo > qhi || hi < qlo || lo > hi)
        return;

    if (lo >= qlo && hi <= qhi){
        tree[pos].val += (hi - lo + 1) * val;
        if (lo != hi)
            propagate(pos, val);
        return;
    }

    int mid = (lo + hi) / 2;
    update(lo, mid, qlo, qhi, val, pos * 2);
    update(mid + 1, hi, qlo, qhi, val, pos * 2 + 1);

    tree[pos].val = tree[pos*2].val + tree[pos*2+1].val;
}

int query(int lo, int hi, int qlo, int qhi, int pos){
    if (tree[pos].lazy != 0){
        tree[pos].val += (hi - lo + 1) * tree[pos].lazy;
        if (lo != hi)
            propagate(pos, tree[pos].lazy);
        tree[pos].lazy = 0;
    }

    if (lo > qhi || hi < qlo || lo > hi)
        return 0;

    if (lo >= qlo && hi <= qhi)
        return tree[pos].val;

    int mid = (lo + hi) / 2;
    return query(lo, mid, qlo, qhi, pos * 2) + query(mid + 1, hi, qlo, qhi, pos * 2 + 1);
}

int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        int val;
        cin >> val;
        update(0, n - 1, i, i, val, 1);
    }

    cout << query(0, n - 1, 1, 4, 1) << "\n";
    update(0, n - 1, 1, 4, 2, 1);
    cout << query(0, n - 1, 1, 4, 1) << "\n";
}
