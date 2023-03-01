#include <iostream>

using namespace std;
#ifndef N
#define N 5
#endif

void pov(int b[], int i){
    int t, beg = 0;
    while (beg < i){
        t = b[beg];
        b[beg] = b[i];
        b[i] = t;
        beg = beg + 1;
        i = i - 1;
    }
}
  

int Max(int a[], int n)
{
    int mi;
    int i;
    for (mi = 0, i = 0; i < n; ++i)
        if (a[i] > a[mi])
            mi = i;
    return mi;
}


void doubleSelectSort(int (&a)[N]){
    for (int i = N; i > 1; i = i - 1){
        int mi = Max(a, i);
        if (mi != i - 1){
            pov(a, mi);
            pov(a, i - 1);
        }
    }
}
  

void print(int a[N]){
    for(int i = 0; i < N; i++){
        cout << a[i] << " ";
    }
}

void inputt(int (&a)[N]){
    int el;
    for(int i = 0; i < N; i++){
        cin >> el;
        a[i] = el;
    }
}

int main(){
    int a[N];
    inputt(a);
    doubleSelectSort(a);
    print(a);
}