#include <iostream>

using namespace std;
#ifndef N
#define N 5
#endif

void shiftRight(int (&a)[N], int k){
    int beg[k];
    int end[N - k];
    for(int i = 0; i < k; i++){
        beg[i] = a[N - k + i];
    }
    for(int i = 0; i < N - k; i++){
        end[i] = a[i];
    }
    for(int i = 0; i < k; i++){
        a[i] = beg[i];
    }
    for(int i = 0; i < N - k; i++){
        a[k + i] = end[i];
    }
}

int main() {
    int n = N;
    int el;
    int k;
    cin >> k;
    int a[N];
    for(int i = 0; i < N; i++){
        cin >> el;
        a[i] = el;
    }
    shiftRight(a, k);
    for(int j = 0; j < N; j++){
        cout << a[j] << " ";
    }
    
}