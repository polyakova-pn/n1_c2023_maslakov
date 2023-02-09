#include <iostream>

using namespace std;

int v_year(int a)
{
    int ans = 0;
    if(a % 4 == 0 and (a % 100 != 0 or a % 400 == 0)){
        ans = 1;
    }
    return ans;
}

int main()
{
    int a;
    cin >> a;
    
    int ans = v_year(a);
    if(ans == 1){
        cout << "YES" << endl;
    } else{
        cout << "NO" << endl;
    }
    
    
}