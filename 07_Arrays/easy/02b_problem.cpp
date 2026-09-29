//second largest in an unsorted array
//method 3

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
    int seclargest = -1; // assuming no negative integer in an array

    for(int i = 1 ; i<n ; i++){
        if(arr[i]>largest){
            seclargest = largest;
            largest = arr[i];
        }
        else if(arr[i]<largest && arr[i]>seclargest){
            seclargest = arr[i];
        }
    }


    cout<<seclargest;

    return 0;

}

//in similar pattern we can find out the smallest and the second smallest elemnt in an array without sorting it