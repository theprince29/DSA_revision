#include<bits/stdc++.h>
using namespace std;


// print all 

// void prints(int idx, vector<int>&ds,int s,int arr[], int n,int sum)
// {
//     if(idx == n)
//     {
//         if(s == sum)
//         {
//             for(auto i : ds)
//             cout<<i<<" ";
//             cout<<endl;
//         }
//             return;
//     }

//     ds.push_back(arr[idx]);
//     s += arr[idx];
//     prints(idx+1,ds,s,arr,n,sum);
    

//     ds.pop_back();
//     s -= arr[idx];
//     prints(idx+1,ds,s,arr,n,sum);
// }

// print one of them


// bool prints(int idx, vector<int>&ds,int s,int arr[], int n,int sum)
// {
//     if(idx == n)
//     {
//         // condition is satisfied
//         if(s == sum )
//         {
//             for(auto i : ds)
//             cout<<i<<" ";
//             cout<<endl;
//             return true;
//         }
//         else
//         return false;
//     }

//     ds.push_back(arr[idx]);
//     s += arr[idx];

//     if(prints(idx+1,ds,s,arr,n,sum) == true)
//         return true;
    

//     ds.pop_back();
//     s -= arr[idx];
//     if(prints(idx+1,ds,s,arr,n,sum) == true) return true;

//     return false;
// }



//  count the posible conditions 

int prints(int idx, vector<int>&ds,int s,int arr[], int n,int sum)
{
    if(idx == n)
    {
        if(s == sum)
        {
            // for(auto i : ds)
            // cout<<i<<" ";
            // cout<<endl;
            return 1;
        }else
            return 0;
    }

    ds.push_back(arr[idx]);
    s += arr[idx];
    int lh = prints(idx+1,ds,s,arr,n,sum);
    

    ds.pop_back();
    s -= arr[idx];
    int rh = prints(idx+1,ds,s,arr,n,sum);
    return rh+lh;
}


int main()
{
    int arr [] = {1,2,1};
    int n =3;
    int sum =2;

    vector<int> ds;
    
    cout<<prints(0,ds,0,arr,n,sum);

    return 0;
}