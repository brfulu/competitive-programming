#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
int V,E,u,v,d,w;
vector<pii> graph[10005];
vector<int> dist(1000,1e9);

int main()
{
    cin >> V >> E;
    for (int i=0;i<E;i++){
        cin >> u >> v >> w;
        graph[u].push_back(pii(w,v));
    }
    dist[0]=0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(pii(0,0));
    while (!pq.empty()){
        u = pq.top().second; d = pq.top().first;
        pq.pop();
        if (d > dist[u])continue;
        for (int i=0;i<graph[u].size();i++){
            w = graph[u][i].first; v = graph[u][i].second;
            if (dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.push(pii(dist[v],v));
            }
        }
    }
    cout << endl;
    for (int i=0;i<V;i++){
        cout << dist[i] << " ";
    }
    cout << endl;
}
