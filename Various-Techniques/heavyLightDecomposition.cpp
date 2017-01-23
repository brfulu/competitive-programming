#include <bits/stdc++.h>

using namespace std;
#define MAXN 100005
int n, q;
vector<int> E[MAXN];
// ST
int tree[4 * MAXN], segPos[MAXN], segArr[MAXN];
// DFS
int depth[MAXN], par[MAXN], subSize[MAXN];
// HLD
int chainNo = 0, chainHead[MAXN], chainPos[MAXN], chainSize[MAXN], chain[MAXN], m = 0;
// LCA
int P[MAXN][30];

void dfs(int cur, int prev, int d){
    par[cur] = prev;
    depth[cur] = d;
    subSize[cur] = 1;
    for (int i = 0; i < E[cur].size(); i++){
        int nxt = E[cur][i];
        if (nxt != prev){
            dfs(nxt, cur, d + 1);
            subSize[cur] += subSize[nxt];
        }
    }
}

void HLD(int cur){
    if (chainHead[chainNo] == -1) chainHead[chainNo] = cur;
    chain[cur] = chainNo;
    segPos[cur] = m;
    segArr[m++] = cur;
    chainPos[cur] = chainSize[chainNo];
    chainSize[chainNo]++;

    int spcl = -1, maxi = -1;
    for (int i = 0; i < E[cur].size(); i++){
        int nxt = E[cur][i];
        if (nxt != par[cur] && subSize[nxt] > maxi){
            maxi = subSize[nxt];
            spcl = nxt;
        }
    }

    if (spcl >= 0) HLD(spcl);

    for (int i = 0; i < E[cur].size(); i++){
        int nxt = E[cur][i];
        if (nxt != spcl && nxt != par[cur]){
            chainNo++;
            HLD(nxt);
        }
    }
}

void precompute(){
    memset(P, -1, sizeof P);

    for (int i = 1; i <= n; i++)
        P[i][0] = par[i];

    for (int j = 1; 1 << j <= n; j++)
        for (int i = 1; i <= n; i++)
            if (P[i][j-1] != -1)
                P[i][j] = P[P[i][j-1]][j-1];
}

int LCA(int u, int v){
    if (depth[u] < depth[v]) swap(u, v);
    int log;
    for (log = 1; 1 << log <= n; log++);
    log--;
    for (int i = log; i >= 0; i--)
        if (depth[u] - (1 << i) >= depth[v])
            u = P[u][i];
    if (u == v) return u;
    for (int i = log; i >= 0; i--)
        if (P[u][i] != -1 && P[u][i] != P[v][i])
            u = P[u][i], v = P[v][i];
    return par[u];
}

void update(int lo, int hi, int idx, int val, int pos){
    if (lo == hi){
        tree[pos] += val;
        return;
    }
    int mid = (lo + hi) / 2;
    if (idx <= mid)
        update(lo, mid, idx, val, pos * 2);
    else
        update(mid + 1, hi, idx, val, pos * 2 + 1);
    tree[pos] = max(tree[pos * 2], tree[pos * 2 + 1]);
}

int query(int lo, int hi, int qlo, int qhi, int pos){
    if (lo >= qlo && hi <= qhi)
        return tree[pos];
    int mid = (lo + hi) / 2;
    if (qhi <= mid)
        return query(lo, mid, qlo, qhi, pos * 2);
    else if (qlo > mid)
        return query(mid + 1, hi, qlo, qhi, pos * 2 + 1);
    else
        return max( query(lo, mid, qlo, qhi, pos * 2) , query(mid + 1, hi, qlo, qhi, pos * 2 + 1) );
}

int crawl(int u, int v){
    int res = 0;
    while (true){
        if (chain[u] == chain[v]){
            res = max(res, query(0, m, segPos[v], segPos[u], 1));
            break;
        }
        else {
            res = max(res, query(0, m, segPos[chainHead[chain[u]]], segPos[u], 1));
            u = par[ chainHead[chain[u]] ];
        }
    }
    return res;
}

int findMax(int u, int v){
    int lca = LCA(u, v);
    return max(crawl(u, lca), crawl(v, lca));
}

int main()
{
    memset(tree, 0, sizeof tree);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    memset(chainHead, -1, sizeof chainHead);
    dfs(1, 0 ,0);
    HLD(1);
    precompute();
    cin >> q;
    while (q--){
        char c;
        int u, v;
        cin >> c >> u >> v;
        if (c == 'I'){
            // update
            update(0, m, segPos[u], v, 1);
        }
        else {
            // query
            cout << findMax(u, v) << "\n";
        }
    }
}
