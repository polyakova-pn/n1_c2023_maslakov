#include <iostream>

using namespace std;
#ifndef n, m
#define n 4
#define m 3
#endif


void inputt(int (&a)[n][m]){
    int el;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> el;
            a[i][j] = el;
        }
    }
}


void print(int a[n]){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}


void print_transposed(int (&a)[n]){
    int beg = 0;
    int end = n - 1;
    int i;
    while(end > beg){
        i = (beg + end) / 2 + 1;
        if(a[i] == 0){
            beg = i;
        }else{
            end = i - 1;
        }
    }
    return beg;
    
    
}

int main() {
    int a[n][m];
    inputt(a);
    cout << findLastZero(a);
}