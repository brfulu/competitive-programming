
#include <iostream>

using namespace std;

struct point{
    double x,y;
};

bool onSegment(point p, point q, point r){ // q lies on segment pr
    if (q.x >= min(p.x,r.x) && q.x <= max(p.x,r.x) &&
        q.y >= min(p.y,r.y) && q.y <= max(p.y,r.y))
        return true;
    else
        return false;
}

int orientation(point p1, point p2, point p3){ // c, ccw, or colinear
    int val = (p2.y - p1.y) * (p3.x - p2.x) - (p3.y - p2.y) * (p2.x - p1.x);
    if (val == 0)return 0;
    return (val > 0 ? 1 : 2);
}

bool doIntersect(point p1,point q1,point p2,point q2){ // p1q1 intersects p2q2 ?
    int o1 = orientation(p1,q1,p2);
    int o2 = orientation(p1,q1,q2);
    int o3 = orientation(p2,q2,p1);
    int o4 = orientation(p2,q2,q1);
    if (o1 != o2 && o3 != o4)
        return true;
    if (o1 == 0 && onSegment(p1,p2,q1))return true;
    if (o2 == 0 && onSegment(p1,q2,q1))return true;
    if (o3 == 0 && onSegment(p2,p1,q2))return true;
    if (o4 == 0 && onSegment(p2,q1,q2))return true;
    return false;
}

bool parallel(point p1,point q1,point p2,point q2){ // parallel lines ?
    int A1 = q1.y - p1.y;
    int B1 = p1.x - q1.x;
    int C1 = A1*p1.x + B1*p1.y;
    int A2 = q2.y - p2.y;
    int B2 = p2.x - q2.x;
    int C2 = A2*p2.x + B2*p2.y;
    int det = A1*B2 - A2*B1;
    return (det == 0);
}

point intersectionPoint(point p1,point q1,point p2,point q2){
    int A1 = q1.y - p1.y;
    int B1 = p1.x - q1.x;
    int C1 = A1*p1.x + B1*p1.y;
    int A2 = q2.y - p2.y;
    int B2 = p2.x - q2.x;
    int C2 = A2*p2.x + B2*p2.y;
    int det = A1*B2 - A2*B1;
    double x = (B2*C1 - B1*C2) / det;
    double y = (A1*C2 - A2*C1) / det;
    return {x,y};
}

int main()
{
    struct point p1 = {1, 1}, q1 = {10, 1};
    struct point p2 = {1, 2}, q2 = {10, 2};

    doIntersect(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n";

    p1 = {10, 0}, q1 = {0, 10};
    p2 = {0, 0}, q2 = {10, 10};
    doIntersect(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n";

    p1 = {-5, -5}, q1 = {0, 0};
    p2 = {1, 1}, q2 = {10, 10};
    doIntersect(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n";
    point p = intersectionPoint({1,0},{2,0},{1,1},{2,2});
    cout << parallel({1,0},{2,0},{1,1},{2,1}) << endl;
    cout << p.x << " " << p.y << endl;
}
