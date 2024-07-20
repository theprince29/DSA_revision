/* Stable sort algorithms sort equal elements in the same order
that they appear in the input. For example, in the card sorting
example to the right, the cards are being sorted by their rank,
and their suit is being ignored. This allows the possibility of
multiple different correctly sorted versions of the original list.
Stable sorting algorithms choose one of these, according to the
 following rule: if two items compare as equal (like the two 5
 cards), then their relative order will be preserved, i.e. if one
 comes before the other in the input, it will come before the other
  in the output. */



// stable sorting algorithm are bubble sort, insertion sort, mearge 
// unstable sorting algorithm are selection sort, quick sort,heap sort etc,

#include<bits/stdc++.h>
using namespace std;

void print(int arr[],int n)
{
    cout<<"->"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<",";
    }
    cout<<endl;
}

void bubble_sort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[i])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void selection_sort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                swap(arr[i],arr[j]); 
            }
        }
    }
}


void insertion_sort(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        int key = arr[i];
        int  j = i - 1;
        while(j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}



void merge(int arr[],int l,int mid,int r)
{
    int n1 = mid-l+1;
    int n2 = r-mid;
    int L[n1],R[n2];

    for(int i=0;i<n1;i++) L[i]=arr[l+i];
    for(int j=0;j<n2;j++) R[j]=arr[n1+j];
    

    int i=0, j=0,k=0;

    while(i<n1 && j<n2)
    { 
        if(L[i] <= R[j]){ 
            arr[k] = L[i];
            i++;
            k++;
        }
        else{
            arr[k] = R[j];
            j++;
            k++;
        }
    }
    while(i<n1){  arr[k]=L[i];i++; k++; }  //copy
    while(j<n2){  arr[k]=R[j];j++;k++;  } 

}

void merge_sort(int arr[],int l,int r)
{
    if(l < r)
    {
        int mid = l+(r-l)/2;
        merge_sort(arr,l,mid);
        merge_sort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}



int main()
{
    int arr [5] = {10,4,16,98,17};
    print(arr,5);
    //  bubble_sort(arr,5);
    merge_sort(arr,0,4);




    print(arr,5);
     return 0;
}