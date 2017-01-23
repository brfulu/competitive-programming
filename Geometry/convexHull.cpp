#include <bits/stdc++.h>

using namespace std;
#define MAXN 100005
int n;

struct point{
    int x, y, i;
    bool operator < (point other) const{
        return x < other.x;
    }
}P[MAXN];

point pivot;

bool collinear(point p1, point p2, point p3){
    int val = (p2.y - p1.y) * (p3.x - p2.x) - (p3.y - p2.y) * (p2.x - p1.x);
    return val == 0;
}

bool ccw(point p1, point p2, point p3){
    int val = (p2.y - p1.y) * (p3.x - p2.x) - (p3.y - p2.y) * (p2.x - p1.x);
    return val < 0;
}

double dist(point p1, point p2){
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

bool cmp(point p1, point p2){
    if (collinear(pivot, p1, p2))
        return dist(pivot, p1) < dist(pivot, p2);
    return ccw(pivot, p1, p2);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        set<pair<int,int> > used;
        cin >> n;
        int j = 0;
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            point p;
            cin >> p.x >> p.y;
            p.i = i + 1;
            if (!used.count(make_pair(p.x,p.y))){
                P[k] = p;
                k++;
            }
            used.insert(make_pair(p.x,p.y));
        }
        n = k;
        for (int i = 0; i < n; i++){
            if (P[i].y < P[j].y || (P[i].y == P[j].y && P[i].x < P[j].x))
                j = i;
        }
        swap(P[0], P[j]);
        pivot = P[0];
        sort(P + 1, P + n, cmp);

        vector<point> CH;
        CH.push_back(P[0]);
        if (n > 1)
        CH.push_back(P[1]);
        for (int i = 2; i < n; i++)
        {
            while (CH.size() > 1 && !ccw(CH[CH.size() - 2], CH[CH.size() - 1], P[i]))
            {
                CH.pop_back();
            }
            CH.push_back(P[i]);
        }
        CH.push_back(P[0]);
        double res = 0;
        for (int i = 0; i < CH.size() - 1; i++)
        {
            res += dist(CH[i], CH[i + 1]);
        }
        cout << fixed << setprecision(2) << res << "\n";
        for (int i = 0; i < CH.size() - 1; i++)
        {
            cout << CH[i].i << " ";
        }
        cout << "\n\n";
    }
}
