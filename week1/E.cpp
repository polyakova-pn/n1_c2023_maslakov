#include <iostream>

using namespace std;

int my_power(int base, int power)
{
    int ans = 1;
    for(int i = 1; i <= power; i++){
        ans = ans * base;
    }
    return ans;
}

int main()
{
    int base, power;
    cin >> base >> power;
    cout << my_power(base, power) << endl;
    
}