#include <bits/stdc++.h>

using namespace std;

class hashST{
private:
    class Node{
    public:
        string key;
        int value;
        Node* next;
    };
    int n;
    int mod;
    Node **heads;

public:
    hashST(int m){
        mod = m;
        heads = new Node*[m + 1];
        for (int i = 0; i < m; i++)
            heads[i] = NULL;
    }

    int hashValue(string key){
        int hsh = 0;
        for (int i = 0; i < key.size(); i++){
            hsh = (hsh * 31 + key[i]) % mod;
        }
        return hsh;
    }

    bool isEmpty(){
        return n == 0;
    }

    bool contains(string key){
        return get(key) != -1;
    }

    void put(string key, int value){
        int hsh = hashValue(key);

        if (contains(key)){
            Node* cur = heads[hsh];
            while (cur != NULL){
                if (cur->key == key){
                    cur->value = value;
                    break;
                }
                cur = cur->next;
            }
            return;
        }

        Node* oldHead = heads[hsh];
        heads[hsh] = new Node;
        heads[hsh]->key = key;
        heads[hsh]->value = value;
        heads[hsh]->next = oldHead;
        n++;
    }

    int get(string key){
        int hsh = hashValue(key);
        Node* cur = heads[hsh];
        while (cur != NULL){
            if (cur->key == key)
                return cur->value;
            cur = cur->next;
        }
        return -1;
    }

    void deleteKey(string key){
        int hsh = hashValue(key);
        Node* cur = heads[hsh];
        if (!contains(key)) return;

        if (heads[hsh]->key == key){
            heads[hsh] = heads[hsh]->next;
            delete cur;
            return;
        }

        Node* prev;
        while (cur->key != key){
            prev = cur;
            cur = cur->next;
        }

        prev->next = cur->next;
        delete cur;
        n--;
    }
};

int main()
{
    hashST st(10);
    while (1){
        int type;
        cin >> type;
        if (type == 1){
            string key;
            int value;
            cin >> key >> value;
            st.put(key, value);
        }
        if (type == 2){
            string key;
            cin >> key;
            cout << st.get(key) << "\n";;
        }
        if (type == 3){
            string key;
            cin >> key;
            st.deleteKey(key);
        }
        if (type == 4){
            break;
        }
    }
}
