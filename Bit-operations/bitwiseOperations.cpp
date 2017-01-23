#include <bits/stdc++.h>

using namespace std;

// __builtin_clz      (count leading zeros)
// __builtin_ctz      (count trailing zeros)
// __builtin_popcount (count turned bits)
//
//  x         00101100        the original x value
//x & -x      00000100        extract lowest bit set
//x | -x      11111100        create mask for lowest-set-bit & bits to its left
//x ^ -x      11111000        create mask bits to left of lowest bit set
//x & (x-1)   00101000        strip off lowest bit set
//                            --> useful to process words in O(bits set)
//                                instead of O(nbits in a word)
//x | (x-1)   00101111        fill in all bits below lowest bit set
//x ^ (x-1)   00000111        create mask for lowest-set-bit & bits to its right
//~x & (x-1)  00000011        create mask for bits to right of lowest bit set
//x | (x+1)   00101101        toggle lowest zero bit
//x / (x&-x)  00001011        shift number right so lowest set bit is at bit 0

bool powerOfTwo(int x){
    return (x && !(x & (x - 1)));
}

int rightmostBit(int x){
    return (x & (-x));
}

int largestPowerTwo(int x){
    x = x | (1 >> 2);
    x = x | (1 >> 4);
    x = x | (1 >> 8);
    x = x | (1 >>16);
    return (x + 1) >> 1;
}

int turnNthBit(int x,int n){
    return (x | (1 << n));
}

int countTurnedBits(int n){
    int res = 0;
    while (n){
        n = n & (n - 1);
        res++;
    }
    return res;
}

void generateSubsets(int n){
    for (int i=0;i<(1 << n);i++){
        for (int j=0;j<n;j++){
            if (i & (1 << j)){
                cout << "1";
            }
            else {
                cout << "0";
            }
        }
        cout << endl;
    }
}

int main()
{
    int x;
    cin >> x;
    bitset<32> bits1(5);
    cout << bits1.to_ulong() << endl;
    bitset<32> bits2(-5);
    cout << bits2.to_ulong() << endl;
    cout << __builtin_ctz(x) << endl;
    cout << powerOfTwo(x) << endl;
    cout << largestPowerTwo(x) << endl;
    cout << rightmostBit(x) << endl;
    cout << countTurnedBits(x) << endl;
   // generateSubsets(x);

}
