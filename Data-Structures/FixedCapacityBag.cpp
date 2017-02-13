#include <iostream>

using namespace std;

class BagFixedCapacity{
private:
    int *arr;
    int sz;
public:
    BagFixedCapacity(int n){
        arr = new int[n];
        sz = 0;
    }
    int getSize(){
        return sz;
    }
    void add(int x){
        arr[sz] = x;
        sz++;
    }
    void printAll(){
        cout << "Bag: ";
        for (int i = 0; i < sz; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main()
{
    int n;
    cin >> n;
    BagFixedCapacity bag(n);
    for (int i = 0; i < 10; i++){
        int x;
        cin >> x;
        bag.add(x);
    }
    cout << bag.getSize() << "\n";
    bag.printAll();
}
