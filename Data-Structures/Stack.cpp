#include <bits/stdc++.h>

using namespace std;

class Stack{
private:
    class Node{
    public:
        int data;
        Node* next;
    };
    Node* head;
    int sz;

public:
    Stack(){
        head = NULL;
        sz = 0;
    }
    int getSize(){
        return sz;
    }
    bool isEmpty(){
        return sz == 0;
    }
    void push(int data){
        Node* oldHead = head;
        head = new Node;
        head->data = data;
        head->next = oldHead;
        sz++;
    }
    int top(){
        return head->data;
    }
    void pop(){
        Node* oldHead = head;
        head = head->next;
        delete oldHead;
        sz--;
    }
};

int main()
{
    Stack st;
    for (int i = 0; i < 10; i++){
        int x;
        cin >> x;
        st.push(x);
    }
    cout << st.getSize() << "\n";
    while (!st.isEmpty()){
        cout << st.top() << "\n";
        st.pop();
    }
}
