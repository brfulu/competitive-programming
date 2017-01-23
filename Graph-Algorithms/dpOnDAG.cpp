#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
#define MAXN 1105
int n, m, k;
int fish[MAXN];
vector<pii> E[MAXN];
long long dist[MAXN][MAXN];

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++){
        int t;
        cin >> t;
        int mask = 0;
        for (int j = 0; j < t; j++){
            int x;
            cin >> x;
            x--;
            mask |= 1 << x;
        }
        fish[i] = mask;
    }
    for (int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        E[u].push_back(pii(v, w));
        E[v].push_back(pii(u, w));
    }

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= 1024; j++)
            dist[i][j] = 10000000;
    dist[1][fish[1]] = 0;

    queue<pii> Q;
    Q.push(pii(1, fish[1]));
    while (!Q.empty()){
        int u = Q.front().first;
        int mask = Q.front().second;
        Q.pop();
        for (int i = 0; i < E[u].size(); i++){
            int v = E[u][i].first, w = E[u][i].second;
            int newMask = mask | fish[v];

            if (dist[u][mask] + w < dist[v][newMask]){
                dist[v][newMask] = dist[u][mask] + w;
                Q.push(pii(v, newMask));
            }
        }
    }
    long long mini = INT_MAX;
    for (int mask1 = 0; mask1 < 1024; mask1++)
        for (int mask2 = 0; mask2 < 1024; mask2++)
            if ( ((mask1 | mask2) == (1 << k) - 1) )
                mini = min(mini, max(dist[n][mask1], dist[n][mask2]));
    cout << mini << "\n";
}
