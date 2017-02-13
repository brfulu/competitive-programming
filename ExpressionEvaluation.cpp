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
    Stack val, op;
    string exp;
    cin >> exp;

    for (int i = 0; i < exp.size(); i++){
        if (exp[i] == '('){

        }
        else if (exp[i] == ')'){
            int a = val.top();
            val.pop();
            int b = val.top();
            val.pop();
            int res;
            char c = op.top();
            op.pop();
            if (c == '+') res = a + b;
            if (c == '-') res = a - b;
            if (c == '*') res = a * b;
            if (c == '/') res = a / b;
            val.push(res);
        }
        else {
            if (isdigit(exp[i]))
                val.push(exp[i]-'0')    ;
            else
                op.push(exp[i]);
        }
    }

    cout << val.top();
}
