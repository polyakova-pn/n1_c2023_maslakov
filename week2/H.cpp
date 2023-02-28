#include <iostream>

using namespace std;
#ifndef N
#define N 2
#endif
#ifndef M
#define M 3
#endif


void inputt(int (&a)[N][M]){
    int el;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> el;
            a[i][j] = el;
        }
    }
}

void print(int a[N]){
    for(int i = 0; i < N; i++){
        cout << a[i] << " ";
    }
}

void print2d(int a[M][N]){
    for(int i = 0; i < M; i++){
        print(a[i]);
        cout << endl;
    }
}



void print_transposed(int (&a)[N][M]){
    int x;
    int y;
    int b[M][N];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            b[j][i] = a[i][j];
        }
    }
    print2d(b);
    
    
}

int main() {
    int n = N;
    int m = M;
    int a[N][M];
    inputt(a);
    print_transposed(a);
}