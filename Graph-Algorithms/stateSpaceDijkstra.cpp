#include <iostream>
#include <climits>
#include <vector>
#include <cstdio>
#include <queue>

using namespace std;
#define MAXN 1005
#define INF 1000000
typedef pair<int,int> pii;
struct state{
    int node,cost,fuel;
    state(){}
    state(int I, int G, int W) : node(I), cost(G), fuel(W) {}
    bool operator < (const state &that) const{
            return this->cost > that.cost;
    }
};
int V,E,Q,S,F,from,to,cost,C,d,c,u,v,w,tank,fuel,price[MAXN];
int dist[1005][105];
vector<pii> graph[MAXN];
state now = {0,0,0};
state top = {0,0,0};

int dijkstra(const int src,const int dest,const int capacity){
    int dd = dest;
    for (int i=0;i<=V;i++)
        for (int j=0;j<=capacity;j++)
            dist[i][j] = INF;
    priority_queue<state> pq;
    pq.push(state(src,0,0));
    dist[src][0] = 0;

    while (!pq.empty()){
        top = pq.top();
        from = top.node;
        pq.pop();

        if (from == dd)return top.cost;

        if (dist[from][top.fuel] < top.cost)continue;

        if (dist[from][top.fuel + 1] > top.cost + price[from] && top.fuel < capacity){
            dist[from][top.fuel + 1] = top.cost + price[from];
            pq.push(state(from,top.cost + price[from],top.fuel + 1));
        }
        vector<pii> &v = graph[from];
        for (int i=0;i<v.size();i++){
            to = v[i].first;
            w  = v[i].second;
            if (w <= top.fuel && dist[to][top.fuel - w] > top.cost){
                dist[to][top.fuel - w] = top.cost;
                pq.push(state(to,top.cost,top.fuel-w));
            }
        }
    }
    return -1;
}

int main()
{
    scanf("%d %d",&V,&E);
    for (int i=0;i<V;i++){
        scanf("%d",price + i);
    }
    for (int i=0;i<E;i++){
        scanf("%d %d %d",&u,&v,&w);
        graph[u].push_back(pii(v,w));
        graph[v].push_back(pii(u,w));
    }
    scanf("%d",&Q);
    while (Q--){
        scanf("%d %d %d",&C,&from,&to);
        int ans = dijkstra(from,to,C);
        if (ans == -1)
            printf("impossible\n");
        else
            printf("%d\n",ans);
    }
}
