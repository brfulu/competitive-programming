#include <bits/stdc++.h>

using namespace std;

void slidingWindow( int A[], int n,int w,int B[] ){
    deque<int> Q;
    for (int i = 0; i < w; i++){
        cout << i << endl;
        while (!Q.empty() && A[i] >= A[Q.back()]){
            Q.pop_back();
        }
        Q.push_back(i);
    }
    for (int i = w; i < n; i++){
        B[i - w] = A[Q.front()];
        while (!Q.empty() && A[i] >= A[Q.back()])
            Q.pop_back();
        while (!Q.empty() && Q.front() <= i - w)
            Q.pop_front();
        Q.push_back(i);
    }
    B[n - w] = A[Q.front()];
}

int main()
{
    int B[10];
    int A[5] = {3,4,1,5,3};
    slidingWindow(A, 5, 2, B);
    for (int i = 0; i < 5-2+1; i++){
        cout << B[i] << " ";
    }
    cout << "\n";
}
