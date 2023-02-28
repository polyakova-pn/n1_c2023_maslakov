#include <iostream>

using namespace std;
#ifndef N
#define N 3
#endif

void reverseArray(int (&a)[N]){
    int b;
    int e;
    for(int i = 0; i < N / 2; i++){
        b = a[i];
        e = a[N - i - 1];
        a[i] = e;
        a[N - i - 1] = b;
    }
}

int main() {
    int n;
    n = N;
    
    int el;
    int a[N];
    for(int i = 0; i < N; i++){
        cin >> el;
        a[i] = el;
    }
    reverseArray(a);
    for(int i = 0; i < N; i++){
        cout << a[i] << " ";
    }
    
}