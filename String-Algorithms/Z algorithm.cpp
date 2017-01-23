#include <bits/stdc++.h>

using namespace std;
int Z[100005];

void computeZ(string txt){
    int l = 0, r = 0;
    for (int k = 1; k < txt.size(); k++){
        if (k > r){
            l = r = k;
            while (r < txt.size() && txt[r] == txt[r - l]) r++;
            Z[k] = r - l;
            r--;
        }
        else {
            int k1 = l - k;
            if (Z[k1] + k <= r)
                Z[k] = Z[k1];
            else {
                l = k;
                while (r < txt.size() && txt[r] == txt[r - l]) r++;
                Z[k] = r - l;
                r--;
            }
        }
    }
}

int main()
{
    string txt, pat;
    cin >> txt >> pat;
    txt += "#";
    txt += pat;
    computeZ(txt);
    cout << txt << endl;
    for (int i = 0; i < txt.size(); i++)
        cout << Z[i] << " ";
    cout << endl;
}
