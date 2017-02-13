#include <bits/stdc++.h>

using namespace std;

class FixedCapacityStack{
private:
    int *arr;
    int sz;

public:
    FixedCapacityStack(int n){
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
        arr[sz] = x;
        sz++;
    }
    int pop(){
        sz--;
        return arr[sz];
    }
};

int main()
{
    FixedCapacityStack st(10);
    for (int i = 0; i < 10; i++){
        int x;
        cin >> x;
        st.push(x);
    }
    while (!st.isEmpty()){
        cout << st.pop() << " ";
    }
}
