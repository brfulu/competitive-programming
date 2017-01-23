#include <bits/stdc++.h>

using namespace std;

struct node{
    node *children[26];
    bool isLeaf;
};

node *getNode(void){
    node *pNode = NULL;
    pNode = (struct node*)malloc(sizeof (node));
    pNode->isLeaf = 0;
    for (int i = 0; i < 26; i++)
        pNode->children[i] = NULL;
    return pNode;
}

void insertWord(node *root, string S){
    int len = S.size();
    node *current = root;

    for (int level = 0; level < len; level++){
        int index = S[level] - 'a';
        if (!current->children[index])
            current->children[index] = getNode();
        current = current->children[index];
    }
    current->isLeaf = true;
}

node *searchWord(node *root, string S){
    int len = S.size();
    node *current = root;

    for (int level = 0; level < len; level++){
        int index = S[level] - 'a';
        if (!current->children[index])
            return NULL;
        current = current->children[index];
    }
    return current;
}

bool isFreeNode(node *pNode){
    for (int i = 0; i < 26; i++)
        if (pNode->children[i])
            return 0;
    return 1;
}

bool deleteWord(node *pNode, string S,int level, int len){
    if (pNode){
        if (level == len){
            if (pNode->isLeaf){
                pNode->isLeaf = 0;
                if (isFreeNode(pNode))
                    return true;
                return false;
            }
        }
        else {
            int index = S[level] - 'a';
            if (deleteWord(pNode->children[index], S, level + 1, len)){
                pNode->children[index] = NULL;
                return (!pNode->isLeaf && isFreeNode(pNode));
            }
        }
    }
    return false;
}

bool found = 0;

void findAllWords(node *current, string res){
    if (current != NULL){
        if (current->isLeaf){
            found = 1;cout << res << "\n";
        }
        for (int i = 0; i < 26; i++)
            if (current->children[i])
                findAllWords(current->children[i], res + char(i + 'a'));
    }
}

int main()
{
//    freopen("ulaz.in", "r", stdin);
    ios::sync_with_stdio(false);
    node *root = getNode();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        insertWord(root, s);
    }
    cin >> n;
    for (int i = 1; i <= n; i++){
        cout << "Case #" << i << ":\n";
        string s;
        cin >> s;
        found = 0;
        node *pNode = searchWord(root, s);
        if (pNode != NULL)
        for (int i = 0; i < 26; i++)
            findAllWords(pNode->children[i], s + char(i + 'a'));
        if (!found)
            cout << "No match.\n";
    }
}
