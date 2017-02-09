#include <iostream>

using namespace std;

class UF{
private:
    int id[100005];
    int sz[100005];
    int cnt;
public:
    UF(int n){
        cnt = n;
        for (int i = 0; i < n; i++){
            id[i] = i;
            sz[i] = 0;
        }
    }

    int find(int u){
        if (id[u] == u)
            return u;
        else {
            id[u] = find(id[u]);
            return id[u];
        }
    }

    int noOfComponents(){
        return cnt;
    }

    bool connected(int u, int v){
        return find(u) == find(v);
    }

    void unite(int u, int v){
        int U = find(u);
        int V = find(v);
        if (U == V) return;

        if (sz[U] < sz[V]){
            id[U] = V;
        }
        else {
            id[V] = U;
            if (sz[U] == sz[V])
                sz[U]++;
        }
        cnt--;
    }

};

int main()
{
    int n;
    cin >> n;
    UF obj(n);

    while (1){
        int type;
        cin >> type;
        if (type == 1){
            cout << "Number of components = " << obj.noOfComponents() << "\n";
        }
        if (type == 2){
            int u, v;
            cin >> u >> v;
            obj.unite(u, v);
        }
        if (type == 3){
            int u, v;
            cin >> u >> v;
            if (obj.connected(u, v))
                cout << "Connected\n";
            else
                cout << "Not connected\n";
        }
    }
}
