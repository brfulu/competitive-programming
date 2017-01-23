#include <bits/stdc++.h>
#include <set>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

#define x second
#define y first
#define mp make_pair
typedef pair<long long,long long> pii;
int N;
double d = INFINITY;

set<pii> s;
map<pii,int> mapa;

double dist(pii p, pii q){
    long long d1 = p.x - q.x;
    long long d2 = p.y - q.y;
    return sqrt((double)d1*d1 + d2*d2);
}

int main()
{
    cin >> N;
    vector<pii> points;
    points.resize(N);
    for (int i=0;i<N;i++){
        cin >> points[i].x >> points[i].y;
        mapa[points[i]] = i;
    }
    sort(points.begin(),points.end());
    s.insert(points[0]);
    int l = 0;
    pii a,b;
    for (int i=1;i<N;i++){
        while (l < i && points[i].x - points[l].x > d){
            s.erase(points[l]);
            l++;
        }
        for (auto it = s.lower_bound(pii(points[i].y - d, points[i].x - d)); it != s.end() && it->y <= points[i].y + d; it++){
            if (dist(*it, points[i]) < d){
                d = dist(*it, points[i]);
                a = *it;
                b = points[i];
            }
        }
        s.insert(points[i]);
    }
    cout << min(mapa[a],mapa[b]) << " " << max(mapa[a],mapa[b]) << " " << fixed << setprecision(6) << d << endl;
}
