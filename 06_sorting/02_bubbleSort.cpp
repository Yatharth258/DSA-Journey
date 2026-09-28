//Bubble sort
//pushes the max element to the last


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

    for (int i = 0; i < n-1; i++) {
        bool swapp=false;
       for (int j = 0; j < n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapp=true;
            }
       }
       if(!swapp){
        break;
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