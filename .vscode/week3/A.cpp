#include <iostream>

using namespace std;
#ifndef N
#define N 5
#endif

void selectSort(int (&a)[N]){
    for (int i = 0; i < N - 1; i++){
        int mi = i;
        for (int j = i + 1; j < N; j++){
            if (a[j] < a[mi]){
                mi = j;
            }
        }
        if (mi != i){
            swap(a[i], a[mi]);
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
    selectSort(a);
    print(a);
}