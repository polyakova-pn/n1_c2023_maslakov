#include <iostream>
#include <chrono>
#include <random>

using namespace std;







void rand_mass_lin(int a[], int N) {
    
    
    std::default_random_engine rng((int)time(0));
    std::uniform_int_distribution<unsigned>dstr(0, 10 * N);
    
    for (int counter = 0; counter < N; ++counter) {
        a[counter] = dstr(rng);
    }
}










void shell1(int a[], int N){
    
    int per = 0;
    int d = N / 2;
    while (d > 0){
        for (int i = 0; i < N - d; i++){
            int j = i;
            while (j >= 0 && a[j] > a[j + d]){
            std::swap(a[j], a[j + d]);
            per++;
            j--;
            }
        }
    d = d / 2;
}
//cout << per << " ";
}

void shell1p(int a[], int N){
    
    int per = 0;
    int d = N / 2;
    while (d > 0){
        for (int i = 0; i < N - d; i++){
            int j = i;
            while (j >= 0 && a[j] > a[j + d]){
            std::swap(a[j], a[j + d]);
            per++;
            j--;
            }
        }
    d = d / 2;
}

return per;
}

void shell2(int a[], int N){
    
    int per = 0;
    int d;
    int step = 1;
    while(step - 1 < N){
        step = step * 2;
    }
    for(int d = step - 1; d > 0; d = (d + 1) / 2 - 1){
        for (int i = 0; i < N - d; i++){
            int j = i;
            while (j >= 0 && a[j] > a[j + d]){
            std::swap(a[j], a[j + d]);
            per++;
            j--;
            }
        }
    }
    //cout << per << " ";
}

void shell2p(int a[], int N){
    
    int per = 0;
    int d;
    int step = 1;
    while(step - 1 < N){
        step = step * 2;
    }
    for(int d = step - 1; d > 0; d = (d + 1) / 2 - 1){
        for (int i = 0; i < N - d; i++){
            int j = i;
            while (j >= 0 && a[j] > a[j + d]){
            std::swap(a[j], a[j + d]);
            per++;
            j--;
            }
        }
    }
    return per;
}

void shell3(int a[], int N){
    
    int per = 0;
    int f1 = 1;
    int f2 = 1;
    while(f1 + f2 < N){
        int z = f2;
        f2 = f1 + f2;
        f1 = z;
    }
    int d = f2;
    int step = 1;
    
    while (d > 0){
        d = f2;
        for (int i = 0; i < N - d; i++){
            int j = i;
            while (j >= 0 && a[j] > a[j + d]){
            std::swap(a[j], a[j + d]);
            per++;
            j--;
            }
        }
        int z = f1;
        f1 = f2 - f1;
        f2 = z;
    }
    //cout << per << " ";
}


int shell3p(int a[], int N){
    
    int per = 0;
    int f1 = 1;
    int f2 = 1;
    while(f1 + f2 < N){
        int z = f2;
        f2 = f1 + f2;
        f1 = z;
    }
    int d = f2;
    int step = 1;
    
    while (d > 0){
        d = f2;
        for (int i = 0; i < N - d; i++){
            int j = i;
            while (j >= 0 && a[j] > a[j + d]){
            std::swap(a[j], a[j + d]);
            per++;
            j--;
            }
        }
        int z = f1;
        f1 = f2 - f1;
        f2 = z;
    }
    return per;
}

int tim(int a[],int N) {
    auto begin = std::chrono::steady_clock::now();
    for(unsigned cnt = 10; cnt != 0 ; --cnt)
        shell3p(a, N);
    auto end = std::chrono::steady_clock::now();
    auto time_span =
    std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

    
    
    return time_span.count() ;
}


double perest(int a[],int N){
    double p = 0;
    for(int i; i < 20; i++){
        p = p + shell1(a, N);
    }
    return p / 20;
}

int main(){
    
    
    for(int i = 1; i < 50; i++){
        int N = i * 1000;
        int a[N];
        rand_mass_lin(a, N);
        
    
    //int t = tim(a, N);
    //std::cout << t << ' ';
    double p = perest(a, N);
    std::cout << p << ' ';
    }
}