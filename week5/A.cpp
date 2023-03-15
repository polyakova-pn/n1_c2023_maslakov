#include <iostream>

using namespace std;

int main(){
    int *ptr;
    int var = 0;
    ptr = &var;
    cout << &ptr << ' ';
    cout << *ptr << endl;
    ptr = ptr-3;
    cout << &ptr << ' ';
    cout << *ptr << endl;
    ptr = ptr+5;
    cout << &ptr << ' ';
    cout << *ptr << endl;
    return 0;
}