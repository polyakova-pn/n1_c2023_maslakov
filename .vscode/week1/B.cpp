#include <iostream>

using namespace std;

int zero_fact(int a)
{
    int ans = 0;
    for(int i = 5; i < 1000000; i = i * 5){
        ans = ans + a / i;
    }

    return ans;
}

int main()
{
    int a;
    cin >> a;
    int ans = zero_fact(a);
    cout << ans << endl;
    
}