#include <bits/stdc++.h>

using namespace std;
#define MAXN 55
int n;
char grid[MAXN][MAXN];
int dist[MAXN][MAXN];

int main()
{
    cin >> n;
    // ucitaj grid n x n

    int sx = 0, sy = 0; // sx i sy su koordinate pocetne tacke
    queue< pair<int,int> > Q;
    Q.push(make_pair(sx, sy));
    memset(dist, -1, sizeof dist); // popuni dist sa -1, to znaci da nismo do njega dosli
    dist[sx][sy] = 0; // odavde krecemo, pa je udaljenost 0;

    while (!Q.empty()){
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        for (int i = 0; i < 4; i++){
            int curx = x + dx[i];
            int cury = y + dy[i];
            if (curx < 0 || cury < 0 || curx >= n || cury >= 0)continue; // izasao sa table
            if (dist[curx][cury] == -1){// samo ako nismo obisli ovo polje
                dist[curx][cury] = dist[x][y] + 1;
                Q.push(make_pair(curx, cury));
            }
        }
    }

    // posle ovoga, dist[x][y] predstavlja udaljesto (x,y) od (sx,sy), a ako je -1 onda ne mozemo doci do njega
}
