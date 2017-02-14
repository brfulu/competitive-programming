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
    static void sort(int *a, int *aux, int lo, int hi){
        if (hi <= lo) return;
        int mid = lo + (hi - lo) / 2;
        sort(a, aux, lo, mid);
        sort(a, aux, mid + 1, hi);
        if (a[mid+1] >= a[mid]) return;
        merge(a, aux, lo, mid, hi);
    }
    static void sort(int *a, int n){
        int *aux = new int[n + 5];
        sort(a, aux, 0, n - 1);
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
