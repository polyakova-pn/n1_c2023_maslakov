#include <iostream>

using namespace std;

int fibonacci(unsigned i)
{
    if(i > 1){
        return fibonacci(i - 1) + fibonacci(i - 2);
    }else{ if(i == 1){
        return 1;
    }else{
        return 0;
    }
        
    }
}

int main()
{
    unsigned i;
    cin >> i;
    cout << fibonacci(i) << endl;
    
}