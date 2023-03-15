#include <iostream>

using namespace std;

bool reserve_memory(int n, int* ptr) {
    if (n) {
        ptr = new int[n];
        return true;
    }
    else return false;
}


void free_memory(int* ptr) {
    if (ptr)
        delete [] ptr;
}

int main() {
    int n = 0;
    int* ptr = nullptr;
    cin >> n;
    cout << reserve_memory(n, ptr) << endl;
    free_memory(ptr);
    return 0;
}