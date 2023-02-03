#include <iostream>

int main() {
    int n = 14;
    int k;
    k = n / 2;
    int ans = 0;
    for (int i = 2; i < k; ++i){
        if(n % i == 0){
            ans = 1;
        }
    }
    if(ans == 1){
        std::cout << "ne prostoe" <<std::endl;
    } else{
        std::cout << "prostoe" <<std::endl;
    }
}