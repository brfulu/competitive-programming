#include <bits/stdc++.h>

using namespace std;

class BST{
private:
    class Node{
    public:
        int key, value;
        Node *left;
        Node *right;
    };
    Node* root;
    int sz;

public:
    BST(){
        sz = 0;
        root = NULL;
    }

    bool isEmpty(){
        return sz == 0;
    }

    int getSize(){
        return sz;
    }

    bool contains(int key){
        return get(key) != NULL;
    }

    void put(int key, int value){
        Node* newNode = new Node;
        newNode->key = key;
        newNode->value = value;
        newNode->left = newNode->right = NULL;
        root = put(root, newNode);
        sz++;
    }

    Node* put(Node* root, Node* newNode){
        if (root == NULL){
            root = newNode;
            return root;
        }
        if (newNode->key < root->key)
            root->left = put(root->left, newNode);
        else if (newNode->key > root->key)
            root->right = put(root->right, newNode);
        else
            root->value = newNode->value;
    }

    int get(int key){
        return get(root, key);
    }

    int get(Node* root, int key){
        if (root == NULL) return NULL;
        if (key < root->key)
            return get(root->left, key);
        else if (key > root->key)
            return get(root->right, key);
        else
            return root->value;
    }

    Node* findMin(Node* root){
        if (root->left == NULL)
            return root;
        else
            return findMin(root->left);
    }

    void deleteKey(int key){
        root = deleteKey(root, key);
        sz--;
    }

    Node* deleteKey(Node* root, int key){
        if (root == NULL) return root;
        else if (key < root->key) root->left  = deleteKey(root->left, key);
        else if (key > root->key) root->right = deleteKey(root->right, key);
        else {
            if (root->left == NULL && root->right == NULL){
                delete root;
                root = NULL;
            }
            else if (root->left == NULL){
                Node* temp = root;
                root = root->right;
                delete temp;
            }
            else if (root->right == NULL){
                Node* temp = root;
                root = root->left;
                delete temp;
            }
            else {
                Node* mini = findMin(root->right);
                root->key = mini->key;
                root->value = mini->value;
                root->right = deleteKey(root->right, mini->key);
            }
        }
        return root;
    }
};

int main()
{
    BST bst;
    while (1){
        int type;
        cin >> type;
        if (type == 1){
            int key, value;
            cin >> key >> value;
            bst.put(key, value);
        }
        if (type == 2){
            int key;
            cin >> key;
            cout << bst.get(key) << "\n";
        }
        if (type == 3){
            int key;
            cin >> key;
            bst.deleteKey(key);
        }
        if (type == 4){
            cout << bst.getSize() << "\n";
        }
    }
}
