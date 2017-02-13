#include <bits/stdc++.h>

using namespace std;

class Selection{
public:
    static void sort(int *A, int n){
        for (int i = 0; i < n - 1; i++){
            int k = i + 1;
            for (int j = i + 2; j < n; j++){
                if (A[j] < A[k])
                    k = j;
            }
            if (A[k] < A[i])
                swap(A[i], A[k]);
        }
    }
};

int main()
{
    int A[10] = {1, 4, 3 ,2 , 6, 7, 3, 11, 8, 9};
    Selection::sort(A, 10);
    for (int i = 0; i < 10; i++){
        cout << A[i] << " ";
    }
}
