#include <bits/stdc++.h>

using namespace std;

int gcdExt(int a,int b,int *x,int *y){
    if (a == 0){
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdExt(b % a, a, &x1, &y1);

    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

int main()
{
    int a, b, x, y;
    cin >> a >> b;
    int g = gcdExt(a, b, &x, &y);
    printf("%d * %d + %d * %d = %d\n", a,x,b,y,g);
}
