#include<bits/stdc++.h>
using namespace std;

// In tabulation is bottom up approch
int fib(int n)
{

    int f[n+1];
    f[0] = 0, f[1]=1;

    for(int i=2; i<=n;i++)
    {
        f[i] = f[i-1]+f[i-2];
    }
    return f[n];
}



int main()
{

    cout<<"\nfibonacii Number"<<endl;
    cout<<fib(10)<<endl;
    return 0;
}