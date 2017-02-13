#include <bits/stdc++.h>

using namespace std;

class Queue{
private:
    class Node{
    public:
        int data;
        Node* next;
    };
    Node *head, *tail;
    int sz;

public:
    Queue(){
        head = tail = NULL;
        sz = 0;
    }
    int getSize(){
        return sz;
    }
    bool isEmpty(){
        return sz == 0;
    }
    void enqueue(int data){
        Node* oldTail = tail;
        tail = new Node;
        tail->data = data;
        tail->next = NULL;
        if (isEmpty())
            head = tail;
        else
            oldTail->next = tail;
        sz++;
    }
    int dequeue(){
        Node* oldHead = head;
        int data = head->data;
        head = head->next;
        delete oldHead;
        sz--;
        if (isEmpty()) tail = NULL;
        return data;
    }
};

int main()
{
    Queue Q;
    for (int i = 0; i < 5; i++){
        int x;
        cin >> x;
        Q.enqueue(x);
    }
    cout << Q.getSize() << "\n";
    while (!Q.isEmpty()){
        cout << Q.dequeue() << " ";
    }
}
