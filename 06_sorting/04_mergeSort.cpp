//Merge sort --> DIVIDE AND MERGE


#include <bits/stdc++.h>
using namespace std;

void mergee(vector <int> &arr , int low , int mid , int high){
    vector <int> temp;
    int left = low ;
    int right = mid+1;
    while(mid>=left && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(mid>=left ){
         temp.push_back(arr[left]);
            left++;
    }
    while (right<=high)
    {
         temp.push_back(arr[right]);
            right++;
    }
    
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i-low];
    }
    
}

void mergeSort(vector <int> &arr , int low , int high){
    int mid = (low + high)/2;
    if(low>=high)  return ;
    mergeSort(arr , low , mid);
    mergeSort(arr , mid + 1 , high);
    mergee(arr , low , mid , high);

}

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



    mergeSort(arr , 0 , n-1);

    
    cout<<"Sorted array :";
        for (int i = 0; i < n; i++)
        {
           cout<<arr[i]<<" ";
        }

    return 0;
}




 // TC
// in best , average and worst cse ==> O(nlogn)
//SC
//O(N)