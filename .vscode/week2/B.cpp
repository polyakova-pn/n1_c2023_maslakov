#include <iostream>

using namespace std;
#ifndef n
#define n 5
#endif

void shiftRight(int (&a)[n]){
    int el = a[n - 1];
    for(int i = 0; i < n - 1; i++){
        a[n - 1 - i] = a[n - 2 - i];
    }
    a[0] = el;
}

int main() {
    int el;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> el;
        a[i] = el;
    }
    shiftRight(a);
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    
}