#include <iostream>

using namespace std;
char *resize(const char *ptr, int size1, int size2)
{
    char *a2 = new char [size2];
    int N;
    if (size1 <= size2){
        N = size1;
    }
    else{
        N = size2;
    }
    for (int i = 0; i < N; i++){
        a2[i] = ptr[i];
    }
    delete [] ptr;
    return a2;
}

int main() {
    int size1, size2;
    cin >> size1 >> size2;
    char *a1 = new char[size1];
    char *a2;
    a2 = resize(a1, size1, size2);
    delete[] a2;
}