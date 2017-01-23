#include <iostream>

using namespace std;

struct point {
    int x,y;
};

int orientation(point p,point q,point r){
    int val = (q.y - p.y) * (r.x - q.x) - (r.y - q.y) * (q.x - p.x);
    if (val == 0)return 0;
    return (val > 0 ? 1 : 2);
}

bool onSegment(point p,point q,point r){
    if (q.x >= min(p.x,r.x) && q.x <= max(p.x,r.x) && q.y >= min(p.y,r.y) && q.y <= max(p.y,r.y))
        return true;
    else
        return false;
}

bool doIntersect(point p1,point q1,point p2,point q2){
    int o1 = orientation(p1,q1,p2);
    int o2 = orientation(p1,q1,q2);
    int o3 = orientation(p2,q2,p1);
    int o4 = orientation(p2,q2,q1);
    if (o1 != o2 && o3 != o4) return true;
    if (o1 == 0 && onSegment(p1,p2,q1))return true;
    if (o2 == 0 && onSegment(p1,q2,q1))return true;
    if (o3 == 0 && onSegment(p2,p1,q2))return true;
    if (o4 == 0 && onSegment(p2,q1,q2))return true;
    return false;
}

bool isInside(point polygon[], int n,point p){
    if (n < 3)return false;
    point extreme = {10000,p.y};
    int cnt = 0, i = 0;
    do {
        int next = (i + 1) % n;

        if (doIntersect(polygon[i],polygon[next],p,extreme)){
            if (orientation(polygon[i],polygon[next],p) == 0){
                return onSegment(polygon[i],p,polygon[next]);
            }
            cnt++;
        }

        i = next;
    }while (i!=0);
    return (cnt % 2 == 1);
}

int main()
{
    point polygon1[] = {{0, 0}, {10, 0}, {10, 10}, {0, 10}};
    int n = sizeof(polygon1)/sizeof(polygon1[0]);
    point p = {20, 20};
    isInside(polygon1, n, p)? cout << "Yes \n": cout << "No \n";

    p = {5, 5};
    isInside(polygon1, n, p)? cout << "Yes \n": cout << "No \n";

    point polygon2[] = {{0, 0}, {5, 5}, {5, 0}};
    p = {3, 3};
    n = sizeof(polygon2)/sizeof(polygon2[0]);
    isInside(polygon2, n, p)? cout << "Yes \n": cout << "No \n";

    p = {5, 1};
    isInside(polygon2, n, p)? cout << "Yes \n": cout << "No \n";

    p = {8, 1};
    isInside(polygon2, n, p)? cout << "Yes \n": cout << "No \n";

    point polygon3[] =  {{0, 0}, {10, 0}, {10, 10}, {0, 10}};
    p = {-1,10};
    n = sizeof(polygon3)/sizeof(polygon3[0]);
    isInside(polygon3, n, p)? cout << "Yes \n": cout << "No \n";

    return 0;
}
