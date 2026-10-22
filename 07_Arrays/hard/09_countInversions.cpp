//Count Inversions 
// Assume an array like arr=[5,3,2,4,1] it would have pairs like (5,3),(5,2),(5,4),(5,1),(3,2),(3,1),(2,1),(4,1) {total 8 pairs so return 8}
// then you have return output as 8

//Method 1 --> Brute force approach --> itertae through all the elemnts and try to make a pair with the right elmnts and count++


#include <bits/stdc++.h>
using namespace std;

int cnt=0; //global variable
//note: in leetcode or interview avoid global variables , just try to reurn it in function 
void mergee(vector <int> &arr , int low , int mid , int high){
    vector <int> temp;
    int left = low ;
    int right = mid+1;
    while(mid>=left && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }//right is smaller
        else{
            temp.push_back(arr[right]);
            cnt+=(mid-left+1);
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


int main(){

    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mergeSort(arr , 0 , n-1);


    cout<<"The number of inversions = "<<cnt;

    return 0;
}


//TC nlogn
//SC here in this coe is O(1)
//but in interview we are genrally not allowed to alter the original data like we did here so we will first make new copy of original array perform merge sort over that so O(n)