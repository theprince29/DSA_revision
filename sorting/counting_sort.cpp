#include<bits/stdc++>
using namespace std;

void coutnsort(int arr[],int n,int k)
{
    int count[k];
    for(int i=0; i<k; i++)
    {
        count[i]=0;
    }
    
    for(int i=0; i<n;i++)
    count[arr[i]]++;

    int index=0;

    for(int i=0; i<k; i++)
    {
        for(int j=; j<count[i]; j++)
        {
            arr[index]=i;
            index++;
        }
    }
}


void counting_sort(int arr[],int n, int k)
{
    int count[k];
    for(int i=0; i<k; i++)
    {
        count[i]=0;
    }

    for(int i=1; i<k;i++)
    {
        count[count[arr[i]]]++;
    }

    for(int i=n-1; i>=0; i--)
    {
        output[count[arr[i]-1]]=arr[i];
        count[arr[i]]--;
    }


    for(int i=0; i<n; i++)
    {
        arr[i]=output[i];
    }
}