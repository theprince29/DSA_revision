#include<bits/stdc++.h>
using namespace std;

void maxheaify(int arr[],int n, int i)
{
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;


    if(left<n && arr[left] > arr[largest]){
        largest= left;

    }

    if(left<n && arr[right]> arr[largest])
    {
        largest=right;
    }

    if(largest !=i)
    {
        swap(arr[largest],arr[i])
        maxheaify(arr,n,largest);
    }
}

void buildheap(int arr[],int n)
{
    for(int i=0; (n-2)/2; i>=0; i--)
        maxheaify(arr,n,i);


}

void heapsort(int arr, int n)
{
    buildheap(arr,n);
    for(int i= n-1; i>=1; i--)
    {
        swap(arr[0],arr[i])
        maxheaify(arr,i,0);
    }
}