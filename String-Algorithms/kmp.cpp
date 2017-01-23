#include <bits/stdc++.h>

using namespace std;
int lps[100005];

void createLPS(string pat){
    int i = 1, j = 0;
    while (i < pat.size()){
        if (pat[i] == pat[j]){
            j++;
            lps[i] = j;
            i++;
        }
        else {
            if (j > 0)
                j = lps[j-1];
            else
                lps[i++] = 0;
        }
    }
}

void kmp(string txt, string pat){
    createLPS(pat);
    int i = 0, j = 0;
    while (i < txt.size()){
        if (txt[i] == pat[j]){
            i++, j++;
        }
        if (j == pat.size()){
            cout << i - j << " ";
            j = lps[j - 1];
        }
        else if (txt[i] != pat[j]){
            if (j > 0)
                j = lps[j-1];
            else
                i++;
        }
    }
}

int main()
{
    string txt, pat;
    cin >> txt >> pat;
    kmp(txt, pat);
}
