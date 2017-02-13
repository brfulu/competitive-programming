#include <bits/stdc++.h>

using namespace std;

class Node{
public:
    int data;
    Node* next;
};

class Bag{
private:
    class Node{
    public:
        int data;
        Node* next;
    };
    Node* head;
    int sz;

public:
    Bag(){
        head = NULL;
        sz = 0;
    }
    int getSize(){
        return sz;
    }
    bool isEmpty(){
        return sz == 0;
    }
    void add(int x){
        Node* oldHead = head;
        head = new Node;
        head->data = x;
        head->next = oldHead;
        sz++;
    }
    void printAll(){
        Node* cur = head;
        while (cur != NULL){
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << "\n";
    }
};

int main()
{
    Bag* bag = new Bag();
    for (int i = 0; i < 10; i++){
        int x;
        cin >> x;
        bag->add(x);
    }
    cout << bag->getSize() << "\n";
    bag->printAll();
}
