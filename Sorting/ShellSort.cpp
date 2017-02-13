#include <bits/stdc++.h>

using namespace std;

class Insertion{
public:
    static void sort(int *A, int n){
        int h = 1;
        while (h < n/3){
            h = 3*h + 1;
        }
        while (h > 0){
            for (int i = h; i < n; i++){
                int j = i;
                while (j >= h && A[j] < A[j-h]){
                    swap(A[j], A[j-h]);
                    j-=h;
                }
            }
            h /= 3;
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
