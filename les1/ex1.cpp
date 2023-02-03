#include <iostream>

int main() {
    int a = 0, b = 20, c = 300;
    int d = b * b - 4 * a * c;
    if(a != 0 and d >= 0){
    std::cout << (-b + d) / 2 / a<<std::endl;
    std::cout << (-b - d) / 2 / a<<std::endl;
    } else{if(a == 0){
        std::cout << -1 * c / b <<std::endl;
    }}
}