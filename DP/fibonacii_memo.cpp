//fibonaii number with dynamic programming 



// 1-D array of memoisation for fibonaccii number;
#include<bits/stdc++.h>
using namespace std;
// memoization methode

vector<long long>memo(500,-1);

long long  fib(long long n)
{
    if(memo[n]==-1)
    {
        long long res;
        if(n==0 || n==1)
        {
            res = n;
        }
        else{
            res = fib(n-1)+fib(n-2);
        }


        memo[n]=res;
    }


    return memo[n];
}

// long long fib(long long n)
// {
//     if(n<=1) return n;
//     return fib(n-1)+fib(n-2);
// }


int main()
{
    int k = 5;
    // 0,1,1,2,3,5,8,13,21
    for(int i=0; i<=10; i++){ 
    cout<<endl;
    cout<<"fibonacii number for "<<i<<endl;
    cout<<fib(i)<<endl;}
    return 0;
}