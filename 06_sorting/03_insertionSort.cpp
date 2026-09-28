//insertion sort
//array divided into two parts , sorted and unsorted 


#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cout<<"Enter the length of the array :";
    cin>>n;
    vector<int> arr(n);

    cout<<"Enter the elemts of the array : ";
    for (int i = 0; i < n; i++)
    {
       cin>>arr[i];
    }

    for (int i = 1; i < n; i++){
       int j=i;
        while (j>0 && arr[j]<arr[j-1])
        {
          swap(arr[j],arr[j-1]);
           j--;
        }
        
        
    }
    

    cout<<"Sorted array :";
        for (int i = 0; i < n; i++)
        {
           cout<<arr[i]<<" ";
        }
    


    return 0;
}

//TC best case o(n) and worst and avarage case mei n sqaure