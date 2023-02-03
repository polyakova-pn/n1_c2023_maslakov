#include <iostream>

int main() {
    int a = 15, b = 20;
    if(a > b){
    while(b > 0){
        int c = b;
        b = a % b;
        a = c;
    }} else{
        int d = a;
        a = b;
        b = d;
        while(b > 0){
            int c = b;
            b = a % b;
            a = c;
        }
    }
    std::cout << a <<std::endl;
}
