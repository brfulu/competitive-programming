// branko_fu (Branko Fulurija)
// Binary Indexed Tree
// Point update O(logn), range sum O(logn)

#include <bits/stdc++.h>

using namespace std;
#define MAXN 100005
int n, A[MAXN], bit[MAXN];

void add(int idx, int val){
    for (int i = idx; i < MAXN; i += i & -i)
        bit[i] += val;
}

int sum(int idx){
    int res = 0;
    for (int i = idx; i > 0; i -= i & -i)
        res += bit[i];
    return res;
}

int sum(int l, int r){
    return sum(r) - sum(l - 1);
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> A[i];
        add(i, A[i]);
    }

    add(1, 5);
    cout << sum(3, 5) << "\n";
    add(2, -4);
    cout << sum(1, 5) << "\n";

}
