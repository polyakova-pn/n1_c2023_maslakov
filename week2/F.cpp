#include <iostream>

using namespace std;
#ifndef N
#define N 5
#endif


void inputt(int (&a)[N]){
    int el;
    for(int i = 0; i < N; i++){
        cin >> el;
        a[i] = el;
    }
}


void print(int a[N]){
    for(int i = 0; i < N; i++){
        cout << a[i] << " ";
    }
}


int findLastZero(int (&a)[N]){
    int beg = 0;
    int end = N - 1;
    int i;
    while(end > beg){
        
        i = (beg + end) / 2 + 1;
        if(a[i] == 1){
            end = i - 1;
        }else{beg = i;}
    }
    return beg;
    
    
}

int main() {
    int n = N;
    int a[N];
    inputt(a);
    cout << findLastZero(a);
}