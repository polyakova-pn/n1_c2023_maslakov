#include <iostream>

using namespace std;

int max_min(int n, int a0) {
    int a;
    int in = 0;
    int ax = 0;
    for(int i = 1; i < n; ++i){
        cin >> a;
        if(a < a0){
            ++in;
        } else{
            if(a > a0){
                ++ax;
            }
        }
        a0 = a;
    }
    if(ax > in){
        return 1;
    } else{
        return 0;
    }
}

int main() {
    int n, a0;
    cin >> n >> a0;
    int ans = max_min(n, a0);
    if(ans == 1){
        cout << "MAX" << endl;
    } else{
        cout << "MIN" << endl;
    }
}