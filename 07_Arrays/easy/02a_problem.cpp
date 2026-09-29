//second largest element in an array without sorting the array

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

    int largest = arr[0];
    int secLar = -1;

    for (int i = 1; i < n; i++)
    {
        if(arr[i]>largest){
            largest = arr[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i]>secLar && arr[i]<largest){
            secLar = arr[i];
        }
    }
    
    cout<<secLar;



    return 0;
}