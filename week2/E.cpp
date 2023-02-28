#include <iostream>
using namespace std;
#ifndef N
#define N 3
#endif

void ch(int(&a)[N])
{
    for (int i=0; i<N; i++)
    {
        cin >> a[i];
    }
}

void vyv(int(&a)[N*2])
{
    for (int i=0; i<N*2; i++)
    {
        cout << a[i] << " ";
    }
}

void mergeArrays(int (&a1)[N], int (&a2)[N], int (&a)[2*N])
{
    for (int i=0; i<N; i++)
    {
        a[i] = a1[i];
        a[i+N] = a2[i];
    }

    for (int i=0; i<2*N; i++)
    {
        for (int j=0; j<2*N-1; j++)
        {
            if (a[j]>a[j+1])
            {
                auto b = a[j];
                a[j] = a[j+1];
                a[j+1] = b;
            }
        }
    }
}

int main()
{
    int a1[N];
    int a2[N];
    int a[2*N];
  
    ch(a1);
    ch(a2);
    mergeArrays(a1, a2, a);
    vyv(a);
    return 0;
}