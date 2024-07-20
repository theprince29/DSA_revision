#include<bits/stdc++.h>
using namespace std;



int lcs(string s1, string s2,int n, int m)
{
    if(n==0 || m==0) return 0;
    if(s1[n-1] == s2[m-1]) 
    return 1 + lcs(s1, s2, n - 1 , m - 1);
    else
    {
        max(lcs(s1,s2,n,m-1),lcs(s1,s2,n-1,m));
    }
}





int main()
{
    string s1="A";
    string s2 = "B";
    int n1=s1.length();
    int n2=s2.length();  

    cout<<lcs(s1,s2,n1,n2)<<endl;

    return 0;
}