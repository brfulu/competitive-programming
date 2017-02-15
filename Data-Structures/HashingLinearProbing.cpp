#include <bits/stdc++.h>

using namespace std;

class hashST{
private:
    int n;
    int mod;
    pair<string,int> *st;

public:
    hashST(int m){
        mod = m;
        st = new pair<string,int>[m + 1];
        for (int i = 0; i < m; i++)
            st[i] = make_pair("", -1);
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

    void resizeST(int len){
        st = (pair<string,int>*)realloc(st, len * sizeof(pair<string,int>));
    }

    void put(string key, int value){
        int hsh = hashValue(key);

        if (contains(key)){
            cout << "usao\n";
            for (int i = hsh; i < mod; i++){
                if (st[i].first == key)
                    st[i].second = value;
            }
            for (int i = 0; i < hsh; i++){
                if (st[i].first == key)
                    st[i].second = value;
            }
            return;
        }

        n++;
        if (n == mod){
            mod *= 2;
            resizeST(mod);
        }

        int i = hsh;
        while (st[i].second != -1){
            i = (i + 1) % mod;
        }
        st[i] = make_pair(key, value);
    }

    int get(string key){
        int hsh = hashValue(key);
        for (int i = hsh; i < mod; i++){
            if (st[i].first == key)
                return st[i].second;
            else if (st[i].second == -1)
                return -1;
        }
        for (int i = 0; i < hsh; i++){
            if (st[i].first == key)
                return st[i].second;
            else if (st[i].second == -1)
                return -1;
        }
    }

    void deleteKey(string key){
        int hsh = hashValue(key);
        n--;
        if (n == mod / 4){
            mod /= 4;
            resizeST(mod);
        }

        for (int i = hsh; i < mod; i++){
            if (st[i].first == key){
                st[i] = make_pair("", -1);
                return;
            }
        }
        for (int i = 0; i < hsh; i++){
            if (st[i].first == key){
                st[i] = make_pair("", -1);
                return;
            }
        }
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
