#include <bits/stdc++.h>

using namespace std;

struct Person{
    string name;
    int age;
};

bool cmp(Person a, Person b){
    if (a.age != b.age)
        return a.age > b.age;
    else
        return a.name < b.name;
}

int main(){
    Person arr[10005];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> arr[i].name >> arr[i].age;
    }
    sort(arr, arr + n, cmp);
    for (int i = 0; i < n; i++){
        cout << arr[i].age << " " << arr[i].name << "\n";
    }
}
