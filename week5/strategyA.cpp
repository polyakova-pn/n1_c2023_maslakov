#include <iostream>
#include <chrono>
#include <random>

using namespace std;




void print(int a[], int N){
    for(int i = 0; i < N; i++){
        cout << a[i] << " ";
    }
}


void rand_mass_lin(int a[], int N) {
    
    
    std::default_random_engine rng((int)time(0));
    std::uniform_int_distribution<unsigned>dstr(0, N);
    
    for (int counter = 0; counter < N; ++counter) {
        a[counter] = dstr(rng);
        
    }
    print(a, N);
}



int stA(int a[], int N, int x) {
    for (int i = 0; i < N; i++)
    {
        if (a[i] == x) {
            std::swap(a[i], a[0]);
            return i;
        } 
    } 
    return -1;
}

int tim(int a[],int N, int x) {
    auto begin = std::chrono::steady_clock::now();
    for(unsigned cnt = 10; cnt != 0 ; --cnt)
        stA(a, N, x);
    auto end = std::chrono::steady_clock::now();
    auto time_span =
    std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

    
    
    return time_span.count() ;
}


double perest(int a[],int N){
    double p = 0;
    for(int i; i < 20; i++){
        p = p + shell3p(a, N);
    }
    return p / 20;
}

int main(){
    
    
    for(int i = 1; i < 50; i++){
        int N = 100 * i;
        int * b = new int[n];
        rand_mass_lin(b, N);
        x = b[N/2];
        auto begin = std::chrono::steady_clock::now();
        int * a = new int[n];
        auto end = std::chrono::steady_clock::now();
        auto time_span =
        std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
        std::cout << "Время на выделение массива: " << time_span.count() << " нс";
        
    rand_mass_lin(a, N);
    int t = tim(a, N, x);
    std::cout << t << ' ';
    //double p = perest(a, N);
    //std::cout << p << ' ';
    delete[] a;}
}