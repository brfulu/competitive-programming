#include <bits/stdc++.h>

using namespace std;
int n;

struct point{
    int x,y;
    bool operator < (point other) const{
        return (x == other.x ? y > other.y : x < other.x);
    }
}P[105];

point pivot;

double dist(point p1, point p2){
    return sqrt( (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y) );
}

int orientation(point p1, point p2, point p3){
    int val = (p2.y - p1.y) * (p3.x - p2.x) - (p3.y - p2.y) * (p2.x - p1.x);
    if (val == 0)return 0;
    return (val > 0 ? 1 : 2);
}

bool cmp(point p1, point p2){
    int val = orientation(pivot, p1, p2);
    if (val == 0)return dist(pivot, p1) < dist(pivot, p2);
    return (val == 2);
}

int dp[105][105][3];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> P[i].x >> P[i].y;
    pivot.x = pivot.y = 0;
    sort(P + 1, P + 1 + n, cmp);
    P[0] = pivot;
    int maxi = 3;
    for (int i = 0; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            for (int k = j + 1; k <= n; k++)
                dp[j][k][orientation(P[i], P[j], P[k])] = 3;
    for (int i = 0; i <= n; i++){
        for (int j = 0; j < i; j++){
            for (int k = 0; k < j; k++){
                int val = orientation(P[k], P[j], P[i]);
                dp[j][i][val] = max(dp[j][i][val], dp[k][j][val] + 1);
              //  cout << i << " " << val << " " << dp[i][val] << endl;
                if (val)
                maxi = max(maxi, dp[j][i][val]);
            }
        }
    }
    cout << maxi << endl;
}
