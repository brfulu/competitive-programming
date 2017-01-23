#include <iostream>

using namespace std;
#define MAXN 305
int mat[MAXN][MAXN];
int V,E,u,v,w;

int main()
{
    cin >> V >> E;
    for (int i=0;i<V;i++)
        for (int j=0;j<V;j++)
            mat[i][j] = 1e8;
    for (int i=0;i<V;i++)
        mat[i][i] = 0;
    for (int i=0;i<E;i++){
        cin >> u >> v >> w;
        mat[u][v] = w;
    }
    for (int k=0;k<V;k++)
        for (int i=0;i<V;i++)
            for (int j=0;j<V;j++)
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);

    cout << endl;
    for (int i=0;i<V;i++){
        for (int j=0;j<V;j++){
            cout << mat[i][j] << " " ;
        }
        cout << endl;
    }
}
