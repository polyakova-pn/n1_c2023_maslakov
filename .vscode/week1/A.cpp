#include <iostream>

using namespace std;

int is_polinom(int a)
{
    int znak = 0;
    int w = 1;
    int i = 0;
    int ans = 1;
    int zn = 0;
    int zk = 0;
    
    while(w < a){
        w = w * 10;
        i = i + 1;
        
        }
    w = w / 10;
    i = i - 1;
    
    
    while(a > 0){
        cout << a << w << endl;
        zk = a % 10;
        zn = a / w;
        if(zn != zk){
            ans = 0;
            }
        a = a % w;
        a = (a - zk) / 10;
        w = w / 100;
        
    }
    return ans;
}

int main()
{
    int a;
    cin >> a;
    int ans = is_polinom(a);
    if(ans == 1){
        cout << "YES" << endl;
    } else{
        cout << "NO" << endl;
    }
    
}