#include <iostream>
#include <random>

using namespace std;

struct pr {
    int x = 0; // stoder value
    int y = 0;
    int m = 0; // pointer to next Node
};


int chvcx(int ch, int N){
    int x = ch % N;
    //int y = ch / N;
    return x;
}

int chvcy(int ch, int N){
    //int x = ch % N;
    int y = ch / N;
    return y;
}

int cvch(int x, int y, int n){
    return n * y + x;
}

void rand_mass_linn(int aaa[], int N, int sd) {
    unsigned seed = sd;
    
    std::default_random_engine rng(seed);
    std::uniform_int_distribution<unsigned>dstr(0, N);
    
    for (int counter = 0; counter < N; ++counter) {
        aaa[counter] = dstr(rng);
    }
}

void rand_mass_lin(int aaa[], int N) {
    
    
    std::default_random_engine rng((int)time(0));
    std::uniform_int_distribution<unsigned>dstr(0, N);
    
    for (int counter = 0; counter < N; ++counter) {
        aaa[counter] = dstr(rng);
    }
}

void print(int a[], int N){
    for(int i = 0; i < N; i++){
        cout << a[i] << " ";
    }
}

void move(int a[], int n, int k, int t){
    int x;
    int y;
    int aa[8];
    for (int i = 0; i < 8; i++){
        aa[i] = i;
    }
    
    for(int i = 0; i < k; i++){
        x = chvcx(a[i], n);
        y = chvcy(a[i], n);
        rand_mass_linn(aa, 8, t + 0 + 0);
        //print(aa, 8);
        //cout << endl;
        //cout << t;
        //cout << endl;
        int rp = aa[5];
        if(rp % 4 == 0){
            x--;
        }
        if(rp % 4 == 1){
            y--;
        }
        if(rp % 4 == 2){
            x++;
        }
        if(rp % 4 == 3){
            y++;
        }
        a[i] = cvch(x, y, n);
    }
}



int konec(int a[], int n, int k){
    int ans = 1;
    int x;
    int y;
    for(int i = 0; i < k; i++){
        x = chvcx(a[i], n);
        y = chvcy(a[i], n);
        if (x > 0 and x < n){
            ans = 0;
        }
        if (y > 0 and y < n){
            ans = 0;
        }
    }
    return ans;

}


int main(){
    
    
    for(int j = 10; j < 1000; j = j + 10){
    //int j = 20;
    int a[1];
    int k = 1;
    a[0] = cvch(j / 2, j / 2, j);
    int t = 0;
    int konecc = 0;
    while(konecc == 0){
        move(a, j, k, t + 1);
        konecc = konec(a, j, k);
        t++;
        //cout << t << " " << a[0] << " ";
        //cout << endl;
        
    }
    cout << t << " ";
    }
    
}

