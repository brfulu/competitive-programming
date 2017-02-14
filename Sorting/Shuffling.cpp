#include <bits/stdc++.h>

using namespace std;

class Shuffle{
public:
    static void shuffle(int *A, int n){
        srand(time(0));
        for (int i = 0; i < n; i++){
            int k = rand() % (i + 1);
            swap(A[k], A[i]);
        }
    }
};

int main()
{
    int A[10] = {1, 2, 3, 4, 5, 6, 7, 8 ,9 ,10};
    Shuffle::shuffle(A, 10);
    for (int i = 0; i < 10; i++){
        cout << A[i] << " ";
    }
}
