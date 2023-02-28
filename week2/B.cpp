#include <iostream>

using namespace std;
#ifndef N
#define N 5
#endif

void shiftRight(int (&a)[N]){
    int el = a[N - 1];
    for(int i = 0; i < N - 1; i++){
        a[N - 1 - i] = a[N - 2 - i];
    }
    a[0] = el;
}

int main() {
    int n = N;
    int el;
    int a[N];
    for(int i = 0; i < N; i++){
        cin >> el;
        a[i] = el;
    }
    shiftRight(a);
    for(int i = 0; i < N; i++){
        cout << a[i] << " ";
    }
    
}