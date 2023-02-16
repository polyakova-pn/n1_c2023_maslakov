#include <iostream>

using namespace std;
#ifndef n
#define n 3
#endif

void reverseArray(int (&a)[n]){
    int b;
    int e;
    for(int i = 0; i < n / 2; i++){
        b = a[i];
        e = a[n - i - 1];
        a[i] = e;
        a[n - i - 1] = b;
    }
}

int main() {
    int el;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> el;
        a[i] = el;
    }
    reverseArray(a);
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    
}