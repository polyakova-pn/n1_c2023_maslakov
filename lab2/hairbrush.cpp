#include <iostream>
#include <chrono>
#include <random>

using namespace std;

void rand_mass_lin(int a[], int N) {
    
    
    std::default_random_engine rng((int)time(0));
    std::uniform_int_distribution<unsigned>dstr(0, 100 * N);
    
    for (int counter = 0; counter < N; ++counter) {
        a[counter] = dstr(rng);
    }
}

void hairbrush(int a[], int N)
{
	double factor = 1.2473309;
    factor = 2;
	int step = N - 1;
	while (step >= 1)
	{
		for (int i = 0; i + step < N; i++){
			if (a[i] > a[i + step]){
				std::swap(a[i], a[i + step]);
				}
			}
			step = step / factor;
		}
	}

int hairbrush_p(int a[], int N)
{
    int per = 0;
	double factor = 1.2473309;
    factor = 2;
	int step = N - 1;
	while (step >= 1)
	{
		for (int i = 0; i + step < N; i++){
			if (a[i] > a[i + step]){
				std::swap(a[i], a[i + step]);
                per++;
				}
			}
			step = step / factor;
		}
    return per;
}

int tim(int a[],int N) {
    auto begin = std::chrono::steady_clock::now();
    for(unsigned cnt = 10; cnt != 0 ; --cnt)
        hairbrush(a, N);
    auto end = std::chrono::steady_clock::now();
    auto time_span =
    std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);    
    return time_span.count() ;
}

double perest(int a[],int N){
    double p = 0;
    for(int i; i < 20; i++){
        p = p + hairbrush_p(a, N);
    }
    return p / 20;
}


void print(int a[],int N){
    for(int i = 0; i < N; i++){
        cout << a[i] << " ";
    }

}


int main(){
    
    
    for(int i = 1; i < 50; i++){
        int N = i * 1000;
        int a[N];
        rand_mass_lin(a, N);
        
    
    int t = tim(a, N);
    std::cout << t << ' ';
    //double p = perest(a, N);
    //std::cout << p << ' ';
    }
}