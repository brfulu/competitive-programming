#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<int> E[1005];
vector<int> S;
int visited[10005], dfsNum[1005], dfsLow[10005];
int dfsCounter = 1;

void dfs(int u){
    dfsNum[u] = dfsLow[u] = dfsCounter++;
    S.push_back(u);
    visited[u] = 1;

    for (int i = 0; i < E[u].size(); i++){
        int v = E[u][i];
        if (!dfsNum[v])
            dfs(v);
        if (visited[v])
            dfsLow[u] = min(dfsLow[u], dfsLow[v]);
    }


    if (dfsNum[u] == dfsLow[u]){
        cout << endl;
        while (1){
            int v = S.back();
            S.pop_back();
            visited[v] = 0;
            cout << v << "->";
            if (u == v)break;
        }
        cout << endl;
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
    }
    dfs(0);
}
