#include <bits/stdc++.h>

using namespace std;

class QuickSort{
public:
    static int partition(int *a, int lo, int hi){
        int pivot = a[lo];
        int i = lo;
        int j = hi + 1;
        while (true){
            while (a[++i] < pivot)
                if (i == hi) break;
            while (pivot < a[--j])
                if (j == lo) break;

            if (i >= j) break;
            swap(a[i], a[j]);
        }
        swap(a[lo], a[j]);
        return j;
    }
    static void sort(int *a, int lo, int hi){
        if (hi <= lo) return;
        int k = partition(a, lo, hi);
        sort(a, lo, k - 1);
        sort(a, k + 1, hi);
    }
    static void sort(int *a, int n){
        sort(a, 0, n - 1);
    }
};

int main()
{
    int A[15] = {10, 4, 8, 1, 4, 4, 2, 6, 7, 9};
    QuickSort::sort(A, 10);
    for (int i = 0; i < 10; i++){
        cout << A[i] << " ";
    }
}
