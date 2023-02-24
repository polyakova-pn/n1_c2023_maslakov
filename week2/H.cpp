#include <iostream>

using namespace std;
#ifndef N
#define N 2
#endif
#ifndef M
#define M 3
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

void print2d(int a[m][n]){
    for(int i = 0; i < m; i++){
        print(a[i]);
        cout << endl;
    }
}



void print_transposed(int (&a)[n][m]){
    int x;
    int y;
    int b[m][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            b[j][i] = a[i][j];
        }
    }
    print2d(b);
    
    
}

int main() {
    int n = N;
    int m = M;
    int a[n][m];
    inputt(a);
    print_transposed(a);
}