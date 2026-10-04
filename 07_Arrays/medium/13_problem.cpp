//Find the number of subarray with sum K
//you are given a array of size n , then you need to find total number of subaarays whose sum is equal to the k which is provided by the user



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
    int k;
    cout<<"Enter the value of sum: ";
    cin>>k;


    map<int,int>mpp;
    mpp[0]=1;
    int preSum = 0 , cnt = 0;

    for (int i = 0; i < n; i++)
    {
        preSum+=arr[i];
        int remove = preSum-k;
        cnt+=mpp[remove];
        mpp[preSum]+=1;
    }
    


    cout<<"Number of subarray given sum are : "<<cnt;


    return 0;
}