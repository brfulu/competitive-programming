#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
int n, m;
vector<pii> E[10005];
list<int> cycle;

void eulerTour(list<int>::iterator i, int u)
{
    for (int j = 0; j < (int)E[u].size(); j++)
    {
        pii &v = E[u][j];
        if (v.second)   // if this edge can still be used/not removed
        {
            v.second = 0; // make the weight of this edge to be 0 (‘removed’)
            for (int k = 0; k < (int)E[v.first].size(); k++)
            {
                pii &uu = E[v.first][k]; // remove bi-directional edge
                if (uu.first == u && uu.second)
                {
                    uu.second = 0;
                    break;
                }
            }
            eulerTour(cycle.insert(i, u), v.first);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        E[u].push_back(pii(v, 1));
        E[v].push_back(pii(u, 1));
    }
    eulerTour(cycle.begin(), 0);
    for (auto it : cycle)
        cout << it << "-";
    cout << "\n";
}
