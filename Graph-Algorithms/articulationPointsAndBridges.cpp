#include <bits/stdc++.h>

using namespace std;
#define MAXN 100005
int n, m, dfsNum[MAXN], dfsLow[MAXN], par[MAXN];
vector<int> E[MAXN];
int dfsCounter = 1;
bool artVrtx[MAXN];

void dfs(int u){
    dfsNum[u] = dfsLow[u] = dfsCounter++;
    for (int i = 0; i < E[u].size(); i++){
        int v = E[u][i];
        if (!dfsNum[v]){
            par[v] = u;
            dfs(v);
            if (dfsLow[v] >= dfsNum[u])
                artVrtx[u] = 1;
            if (dfsLow[v] > dfsNum[u])
                cout << "EDGE: " << u << "-" << v << "\n";
            dfsLow[u] = min(dfsLow[u], dfsLow[v]);
        }
        else if (v != par[u])
            dfsLow[u] = min(dfsLow[u], dfsNum[v]);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
        if (artVrtx[i])
            cout << i << " ";
    cout << endl;
}
