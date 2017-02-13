#include <bits/stdc++.h>

using namespace std;

class MergeSort{
public:
    static void merge(int *a, int *aux, int lo, int mid, int hi){
        for (int k = lo; k <= hi; k++)
            aux[k] = a[k];

        int i = lo, j = mid + 1;
        for (int k = lo; k <= hi; k++){
            if (i > mid)
                a[k] = aux[j++];
            else if (j > hi)
                a[k] = aux[i++];
            else if (aux[i] < aux[j])
                a[k] = aux[i++];
            else
                a[k] = aux[j++];
        }
    }
    static void sort(int *a, int *aux, int n){
        for (int len = 1; len <= n; len *= 2){
            for (int lo = 0; lo < n - len; lo += 2*len){
                int mid = lo + len - 1;
                int hi  = min(n-1, lo + 2 * len - 1);
                merge(a, aux, lo, mid, hi);
            }
        }
    }
    static void sort(int *a, int n){
        int *aux = new int[n + 5];
        sort(a, aux, n);
        delete aux;
    }
};

int main()
{
    int A[15] = {10, 5, 8, 1, 3, 4, 2, 6, 7, 9};
    MergeSort::sort(A, 10);
    for (int i = 0; i < 10; i++){
        cout << A[i] << " ";
    }
}
