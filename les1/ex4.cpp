#include <iostream>

int main() {
    int n = 24;
    int k;
    k = n / 2;
    int ans1 = 0, ans2 = 0;
    for (int i = 1; i < k; ++i){
        for (int j = 1; j < n; ++j){
            if(n  == i * i + j * j){
                ans1 = i;
                ans2 = j;
            }
    }}
    if(ans1 != 0){
        std::cout << n << "="<< ans1 << "^2 + " << ans2 << "^2" <<std::endl;
    } else{
        std::cout << "ne predstavimo" <<std::endl;
    }
}