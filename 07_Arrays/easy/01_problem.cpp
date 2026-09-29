//largest element in the array
 //method 1 --> sort the array and print the last element


 //method 2
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

    for (int i = 1; i < n; i++)
    {
       if(arr[i]>largest){
        largest = arr[i];
       }
    }
    



    cout<<"Largest elemnt is : "<<largest;

    return 0;
}