#include <iostream>
using namespace std;

int main() {
    int* ptr1 = new int[1];
    int el, n = 1;
    cin >> el;
    ptr1[0] = el;
    while (el != 0) {
        cin >> el;
        if (n == 1 && el != 0) {
            int* ptr2 = new int[2];
            ptr2[0] = ptr1[0];
            ptr2[1] = el;
            delete[] ptr1;
            ptr1 = ptr2;
            n = 2; 
        }
        else if (el != 0) {
            int* ptr2 = new int[n + 1]; 
            for (int i = 0; i < n; i++) {
                ptr2[i] = ptr1[i];
            }
            ptr2[n] = el;
            delete[] ptr1;
            ptr1 = ptr2;
            n++;
        }
    }

    for (int i = 0; i < n - 1; i++) { 
        cout << ptr1[i] - ptr1[i+1] << " ";
    }

    delete[] ptr1;
    return 0;
}