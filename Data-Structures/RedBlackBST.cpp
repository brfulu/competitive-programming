#include <bits/stdc++.h>

using namespace std;

class redBlackBST{
private:
    static const bool RED = true;
    static const bool BLACK = false;
    int n;

    class Node{
    public:
        string key;
        int value;
        bool color;
        Node* left;
        Node* right;
        Node(string key, int value){
            this->key = key;
            this->value = value;
            left = right = NULL;
            color = BLACK;
        }
    };
    Node* root;

    Node* rotateLeft(Node* h){
        Node* x = h->right;
        h->right = x->left;
        x->color = h->color;
        x->left = h;
        h->color = RED;
        return x;
    }

    Node* rotateRight(Node* h){
        Node* x = h->left;
        h->left = x->right;
        x->color = h->color;
        x->right = h;
        h->color = RED;
        return x;
    }

    void flipColors(Node* h){
        h->color = RED;
        h->left->color = BLACK;
        h->right->color = BLACK;
    }

    Node* balance(Node* h){
        if (h == NULL || h->right == NULL || h->left == NULL) return h;

        if (isRed(h->right))
            h = rotateLeft(h);
        if (h->left->left != NULL && isRed(h->left) && isRed(h->left->left))
            h = rotateRight(h);
        if (isRed(h->left) && isRed(h->right))
            flipColors(h);
        return h;
    }

public:
    redBlackBST(){
        root = NULL;
        n = 0;
    }

    bool containts(string key){
        return get(key) != -1;
    }

    bool isEmpty(){
        return n == 0;
    }

    bool isRed(Node* cur){
        if (cur == NULL) return false;
        return cur->color == RED;
    }

    int getSize(){
        return n;
    }

    int get(string key){
        Node* cur = root;
        while (cur != NULL){
            if (key < cur->key)
                cur = cur->left;
            else if (key > cur->key)
                cur = cur->right;
            else
                return cur->value;
        }
        return -1;
    }

    void put(string key, int value){
        if (!containts(key)) n++;
        root = put(root, key, value);
    }

    Node* put(Node* h, string key, int value){
        if (h == NULL) return new Node(key, value);
        if      (key < h->key) h->left  = put(h->left, key, value);
        else if (key > h->key) h->right = put(h->right, key, value);
        else                   h->value = value;

        if (isRed(h->right) && !isRed(h->left))     h = rotateLeft(h);
        if (isRed(h->left) && isRed(h->left->left)) h = rotateRight(h);
        if (isRed(h->left) && isRed(h->right))      flipColors(h);

        return h;
    }

    Node* findMin(Node* root){
        if (root->left == NULL)
            return root;
        else
            return findMin(root->left);
    }

    void deleteKey(string key){
        root = deleteKey(root, key);
        n--;
    }

    Node* deleteKey(Node* root, string key){
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
        return balance(root);
    }
};

int main()
{
    redBlackBST bst;
    while (1){
        int type;
        cin >> type;
        if (type == 1){
            string key;
            int value;
            cin >> key >> value;
            bst.put(key, value);
        }
        if (type == 2){
            string key;
            cin >> key;
            cout << bst.get(key) << "\n";
        }
        if (type == 3){
            string key;
            cin >> key;
            bst.deleteKey(key);
        }
        if (type == 4){
            cout << bst.getSize() << "\n";
        }
    }
}
