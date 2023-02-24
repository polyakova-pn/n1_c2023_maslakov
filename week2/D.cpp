#include <iostream>

using namespace std;
#ifndef N
#define N 5
#endif
void print(int a[n]){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}
void moveNegativeToEnd(int (&a)[n]){
    int k = 0;
    
    for(int i = 0; i < n; i++){
        if(a[i] > 0){
            ++k;
        }
    }
    
    int beg[k];
    int end[n - k];
    int ip = 0;
        int in = 0;
    for(int i = 0; i < n; i++){
        
        if(a[i] > 0){
        beg[ip] = a[i];
        ++ip;
        }else{
            end[in] = a[i];
            ++in;
        }
    }
    
    for(int i = 0; i < k; i++){
        a[i] = beg[i];
    }
    for(int i = 0; i < n - k; i++){
        a[k + i] = end[i];
    }
}

int main() {
    int n = N;
    int el;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> el;
        a[i] = el;
    }
    moveNegativeToEnd(a);
    print(a);
    
}