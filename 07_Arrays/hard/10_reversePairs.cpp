//Reverse Pairs 
//ex- arr=[40,25,19,12,9,6,2]
//i<j && arr[i]>2*arr[j]
// return answer as 15

//Method 1 --> Brute force approach

//Method 2 --> using merge sort technique

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
        }else{
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

int countPairs(vector <int> &arr , int low , int mid , int high){
    int cnt=0;
    int right = mid+1;
    for (int i = low; i <= mid; i++)
    {
        while(right <= high && (arr[i]>2*arr[right])) right++;
        cnt+=(right-(mid+1));
    }
    return cnt;
}

int mergeSort(vector <int> &arr , int low , int high){
    int cnt=0;
    int mid = (low + high)/2;
    if(low>=high)  return cnt;
    cnt+= mergeSort(arr , low , mid);
    cnt+= mergeSort(arr , mid + 1 , high);
    cnt+= countPairs(arr , low , mid , high);
    mergee(arr , low , mid , high);
    return cnt;
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

    int ans = mergeSort(arr , 0 , n-1);


    cout<<"The number of reverse pairs = "<<ans;

    return 0;
}

//TC O(2nlogn)
//SC here in this coe is O(1)
//but in interview we are genrally not allowed to alter the original data like we did here so we will first make new copy of original array perform merge sort over that so O(n)