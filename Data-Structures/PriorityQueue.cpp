#include <bits/stdc++.h>

using namespace std;

class PQ{
private:
    int *pq;
    int n;
    void swim(int k){
        while (k > 1 && pq[k/2] < pq[k]){
            swap(pq[k/2], pq[k]);
            k /= 2;
        }
    }
    void sink(int k){
        while (2 * k <= n){
            int j = 2 * k;
            if (j < n && pq[j] < pq[j+1]) j++;
            if (pq[j] < pq[k]) break;
            swap(pq[j], pq[k]);
            k = j;
        }
    }

public:
    PQ(int cap){
        n = 0;
        pq = new int[cap+5];
    }
    bool isEmpty(){
        return n == 0;
    }
    int getSize(){
        return n;
    }
    void push(int x){
        pq[++n] = x;
        swim(n);
    }
    int delMax(){
        int maxi = pq[1];
        swap(pq[1], pq[n]);
        n--;
        sink(1);
        pq[n+1] = NULL;
        return maxi;
    }

};

int main()
{
    PQ pq(10);
    for (int i = 0; i < 10; i++){
        int x;
        cin >> x;
        pq.push(x);
    }
    while (!pq.isEmpty()){
        cout << pq.delMax() << " ";
    }
}
