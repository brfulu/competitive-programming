#include <bits/stdc++.h>

using namespace std;
int n, q, A[100005];
int S[5000005], L[5000005], R[5000005];
map<int,int> M, RM;
int root[2000005];
int NEXT_FREE_INDEX = 1;
int ir = 1;

int update(int l, int r, int p, int id){
	int ID =  NEXT_FREE_INDEX ++; // index of the node in new version of segment tree
	if(l == r){
		S[ID] = 1;
		return ID;
	}
	int mid = (l+r)/2;
	L[ID] = L[id], R[ID] = R[id]; // in case of not updating the interval of left child or right child
	if(p <= mid)
		L[ID] = update(l, mid, p, L[id]);
	else
		R[ID] = update(mid + 1, r, p, R[id]);

    S[ID] = S[L[ID]] + S[R[ID]];
	return ID;
}

int query(int id1, int id2, int l, int r, int k){
    if (l == r){
        return l;
    }
    int mid = (l + r) / 2;
    int cnt = S[L[id1]] - S[L[id2]];
    if (cnt >= k)
        return query(L[id1], L[id2], l, mid, k);
    else
        return query(R[id1], R[id2], mid + 1, r, k - cnt);
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> A[i];
        M[A[i]] = 1;
    }
    int rnk = 0;
    for (auto it : M){
        M[it.first] = rnk;
        RM[rnk] = it.first;
        rnk++;
    }
    for (int i = 1; i <= n; i++){
        root[i] = update(0, rnk, M[A[i]], ir);
        ir = root[i];
    }
    while (q--){
        int l, r, k;
        cin >> l >> r >> k;
        int ans = query(root[r], root[l-1], 0, rnk, k);
		cout << RM[ans] << "\n";
    }
}
