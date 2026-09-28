// reverse an array using recursion

#include<bits/stdc++.h>
using namespace std;


void reverseArr(int i , int arr[] , int n){
    if(i>=(n/2)) return ;
    swap(arr[i], arr[n-i-1]);
    reverseArr(i+1 , arr , n);
}

int main(){

    int n ;
    cout<<"Enter the size of array :";
    cin>>n;

    int arr[n];

    cout<<"Enter elements of array :";
    for(int i = 0 ; i<n ; i++){
        cin>>arr[i];
    }

    reverseArr(0 , arr , n);

    cout<<"Reverse of the array is :";
    for(int i = 0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }

}