// branko_fu (Branko Fulurija)
// Segment Tree, range minimum query
// You have an array on numbers, point update and range minimum query
// Build O(n)
// Update O(logn)
// Query O(logn)

#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005
int n, A[MAXN];

struct node{
    int val;
}tree[4 * MAXN];

node merge(node l, node r){
    node res;
    res.val = min(l.val, r.val);
    return res;
}

void build(int lo, int hi, int pos){
    if (lo == hi){
        tree[pos].val = A[lo];
        return;
    }
    int mid = (lo + hi) / 2;
    build(lo, mid, pos * 2);
    build(mid + 1, hi, pos * 2 + 1);
    tree[pos] = merge(tree[pos * 2], tree[pos * 2 + 1]);
}

void update(int lo, int hi, int idx, int val, int pos){
    if (lo == hi){
        tree[pos].val = val;
        return;
    }
    int mid = (lo + hi) / 2;

    if (idx <= mid)
        update(lo, mid, idx, val, pos * 2);
    else
        update(mid + 1, hi, idx, val, pos * 2 + 1);

    tree[pos] = merge(tree[pos * 2], tree[pos * 2 + 1]);
}

node query(int lo, int hi, int qlo, int qhi, int pos){
    if (lo >= qlo && hi <= qhi)
        return tree[pos];
    int mid = (lo + hi) / 2;

    if (qhi <= mid)
        return query(lo, mid, qlo, qhi, pos * 2);
    else if (qlo > mid)
        return query(mid + 1, hi, qlo, qhi, pos * 2 + 1);
    else
        return merge(query(lo, mid, qlo, qhi, pos * 2), query(mid + 1, hi, qlo, qhi, pos * 2 + 1));
}

int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> A[i];
    }
    build(0, n - 1, 1);

    while (1){
        int type;
        cin >> type;

        if (type == 1){
            int idx, val;
            cin >> idx >> val;
            update(0, n - 1, idx, val, 1);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << query(0, n - 1, l, r, 1).val << "\n";
        }
    }
}
