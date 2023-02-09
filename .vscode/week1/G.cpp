#include <iostream>

using namespace std;

int lmax_lmin(int n, int a0, int a1) {
    int a;
    int in = 0;
    int ax = 0;
    for(int i = 1; i < n - 1; ++i){
        cin >> a;
        if(a1 < a0 and a1 < a){
            ++in;
        } else{
            if(a1 > a0 and a1 > a){
                ++ax;
            }
        }
        int vsp = a1;
        a1 = a;
        a0 = vsp;
    }
    if(ax > in){
        return 1;
    } else{if(ax < in){
        return 0;
    }else{
        return -1;
    }
    }
}

int main() {
    int n, a0, a1;
    cin >> n >> a0 >> a1;
    int ans = lmax_lmin(n, a0, a1);
    if(ans == 1){
        cout << "MAX" << endl;
    } else{if(ans == 0){
        cout << "MIN" << endl;
    }else{
        cout << "EQUAL" << endl;
    }
    }
}