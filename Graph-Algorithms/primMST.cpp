#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
int n, m, mst = 0, used[100005];
vector<pii> E[10005];
priority_queue<pii, vector<pii>, greater<pii> > pq;

void process(int u){
    used[u] = 1;
    for (auto v : E[u])
        if (!used[v.first])
            pq.push(pii(v.second, v.first));
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        E[u].push_back(pii(v, w));
        E[v].push_back(pii(u, w));
    }
    process(0);
    while (!pq.empty()){
        pii top = pq.top();
        pq.pop();
        if (!used[top.second]){
            mst += top.first;
            process(top.second);
        }
    }
    cout << mst << "\n";
}
