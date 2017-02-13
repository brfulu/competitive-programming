#include <bits/stdc++.h>

using namespace std;

class FixedCapacityStack{
private:
    int *arr;
    int sz;
    int n;

public:
    FixedCapacityStack(int n){
        this->n = n;
        sz = 0;
        arr = new int[n];
    }
    bool isEmpty(){
        return sz == 0;
    }
    int getSize(){
        return sz;
    }
    void push(int x){
        if (sz == n){
            arr = (int*)realloc(arr, 2 * n * sizeof(int));
            n *= 2;
        }
        arr[sz] = x;
        sz++;
    }
    int pop(){
        sz--;
        if (sz > 0 && sz == n / 4){
            arr = (int*)realloc(arr, n / 2 * sizeof(int));
            n /= 2;
        }
        return arr[sz];
    }
};

int main()
{
    FixedCapacityStack st(3);
    for (int i = 0; i < 10; i++){
        int x;
        cin >> x;
        st.push(x);
    }
    while (!st.isEmpty()){
        cout << st.pop() << " ";
    }
}
