#include <iostream>

using namespace std;
#ifndef n
#define n 4
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
    int a[n];
    inputt(a);
    cout << findLastZero(a);
}