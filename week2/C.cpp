#include <iostream>

using namespace std;
#ifndef n
#define n 5
#endif

void shiftRight(int (&a)[n], int k){
    int beg[k];
    int end[n - k];
    for(int i = 0; i < k; i++){
        beg[i] = a[n - k + i];
    }
    for(int i = 0; i < n - k; i++){
        end[i] = a[i];
    }
    for(int i = 0; i < k; i++){
        a[i] = beg[i];
    }
    for(int i = 0; i < n - k; i++){
        a[k + i] = end[i];
    }
}

int main() {
    int el;
    int k;
    cin >> k;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> el;
        a[i] = el;
    }
    shiftRight(a, k);
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    
}