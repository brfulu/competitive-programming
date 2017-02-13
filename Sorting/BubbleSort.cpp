#include <bits/stdc++.h>

using namespace std;

class Bubble{
public:
    static void sort(int *A, int n){
        int swaped = 0;
        do {
            swaped = 0;
            for (int i = 1; i < n; i++){
                if (A[i] < A[i-1]){
                    swap(A[i], A[i-1]);
                    swaped++;
                }
            }
        }while(swaped > 0);
    }
};

int main()
{
    int A[10] = {1, 4, 3 ,2 , 6, 7, 3, 11, 8, 9};
    Bubble::sort(A, 10);
    for (int i = 0; i < 10; i++){
        cout << A[i] << " ";
    }
}
