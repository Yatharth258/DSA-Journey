//find the next permuation of the array

#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cout<<"Enter the length of the array: ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int index =-1;
    for (int i = n-2; i >=0; i--)
    {
        if(arr[i]<arr[i+1]){
            index=i;
            break;
        }
    }
    if(index==-1){
        reverse(arr.begin(),arr.end());
    }else{
        for(int i=n-1 ; i>index ; i--){
            if(arr[i]>arr[index]){
                swap(arr[i],arr[index]);
                break;
            }
        }
        reverse(arr.begin()+index+1,arr.end());
    }
    
    

    cout<<"The next permuted array will be: ";
    for(int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}

// TC O(N)
// SC O(1)