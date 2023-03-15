#include <iostream>

using namespace std;

void input_array(int* ptr, int N) {
    for (int i = 0; i < N; i++) {
        cin >> ptr[i];
    }
}

void reverse(int* ptr, int N) {
    for (int i = 0; i < N/2; i++) {
        int vsp = ptr[i];
        ptr[i] = ptr[N-1-i];
        ptr[N-1-i] = vsp;
    }
}

void print(const int* ptr, int N) {
    for (int i = 0; i < N; i++) {
        cout << ptr[i] << " ";
    }
    cout << endl;
}

int main() {
    int N = 0;
    cin >> N;
    int* ptr = new int[N];
    input_array(ptr, N);
    reverse(ptr, N);
    print(ptr, N);
    delete[] ptr;
    return 0;
}