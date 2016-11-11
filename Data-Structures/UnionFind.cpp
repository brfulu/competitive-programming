// branko_fu (Branko Fulurija)
// Union Find - Disjoint Set
//

#include <bits/stdc++.h>

using namespace std;
#define MAXN 100005
int id[MAXN], rnk[MAXN];

void init(int n){
    for (int i = 0; i <= n; i++){
        id[i] = i;
        rnk[i] = 0;
    }
}

int find(int i){
    if (i == id[i])
        return i;
    else
        return id[i] = find(id[i]);
}

bool isSameSet(int u, int v){
    return find(u) == find(v);
}

void unite(int u, int v){
    int U = find(u);
    int V = find(v);

    if (U != V){
        if (rnk[U] < rnk[V]){
            id[U] = V;
        }
        else {
            id[V] = U;
            if (rnk[U] == rnk[V])
                rnk[U]++;
        }
    }
}

int main(){
    int n;
    cin >> n;
    init(n);

    unite(0, 1);
    unite(1, 2);
    unite(3, 4);
    unite(5, 6);
    unite(6, 3);

    cout << isSameSet(0, 2) << "\n";
    cout << isSameSet(3, 5) << "\n";
    cout << isSameSet(1, 6) << "\n";
}
