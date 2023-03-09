#include <iostream>

using namespace std;
#ifndef N
#define N 5
#endif

void forward_step(int beg, int end){
    for (int i = beg; i < end; i++) {
        int vsp;
        if (a[i] > a[i + 1]){
            vsp = a[i];
            a[i] = a[i + 1];
            a[i + 1] = vsp;
        }
    }
    end--;
    
}

void backward_step(int beg, int end){
    for (int i = end; i > beg; i--) {
        int vsp;
        if (a[i] < a[i - 1]){
            vsp = a[i];
            a[i] = a[i - 1];
            a[i-1] = vsp;
        }
    }
    beg++;
}

void shakersort(int (&a)[N]){
    int beg = 0;
    int end = size - 1;
    while (beg <= end){
        forward_step(beg, end);
        backward_step(beg, end);
    }
    
}

bool test_sort(int (&a)[N]){
    for (int i = 0; i < size - 1; i++){
        if (a[i] > a[i+1]){
            return false;
        }
    }
    return true;
}


int main(){
    int a[N];
    inputt(a);
    shakersort(a);
    print(a);
}








void shakersort(int (&a)[N]) {
    int control = N - 1;
	int left  = 0;
	int right = N - 1;
	while(left < right){
		for (int i = left; i < right; i++) {
			if (a[i] > a[i + 1]) {
                std::swap(a[i], a[i + 1]);
                control = i;
			}
		}
		right = control;
		for (int i = right; i > left; i--) {
			if (a[i] < a[i - 1]){
                std::swap(a[i], a[i - 1]);
                control = i;
			}
		}
		left = control;
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
    shakersort(a);
    print(a);
}