#include <bits/stdc++.h>

using namespace std;

class Insertion{
public:
    static void sort(int *A, int n){
        for (int i = 1; i < n; i++){
            int j = i;
            while (j > 0 && A[j] < A[j-1]){
                swap(A[j], A[j-1]);
                j--;
            }
        }
    }
};

int main()
{
    int A[10] = {1, 4, 3 ,2 , 6, 7, 3, 11, 8, 9};
    Insertion::sort(A, 10);
    for (int i = 0; i < 10; i++){
        cout << A[i] << " ";
    }
}
