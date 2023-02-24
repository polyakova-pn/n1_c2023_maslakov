#include <iostream>

using namespace std;
#ifndef N
#define N 2
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


int findLastZero(int (&a)[n]){
    int beg = 0;
    int end = n - 1;
    while(end > beg){
        i = (beg + end) / 2
        if(a[i] = 0){
            beg = i;
        }else{end = i}
    }
    return a[beg]
    
    
}

int main() {
    int n = N;
    int a[n];
    inputt(a);
    cout << findLastZero(a);
}