#include <iostream>

using namespace std;
#ifndef n
#define n 2
#endif


void inputt(int (&a)[n]){
    int el;
    for(int i = 0; i < n; i++){
        cin >> el;
        a[i] = el;
    }
}


void print(int a[n]){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}


void mergeArrays(int (&a)[n], int (&b)[n], int (&c)[2 * n]){
    for(int i = 0; i < n; i++){
        c[i] = a[i];
    }
    for(int i = 0; i < n; i++){
        c[n + i] = b[i];
    }
    
    
}

int main() {
    int a[n];
    int b[n];
    inputt(a);
    inputt(b);
    int c[2 * n];
    mergeArrays(a, b, c);
    for(int i = 0; i < 2 * n; i++){
        cout << c[i] << " ";
    }
    
}