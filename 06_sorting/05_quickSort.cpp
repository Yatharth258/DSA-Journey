//QUICK SORT 
//PICK THE PIVOT AND PLACE IT AT ITS ORIGINAL PLACE IN SORTED ARRAY
//SMALLER ON THE LEFT AND LARGER ON THE RIGHT

#include <bits/stdc++.h>
using namespace std;

int part(vector <int> &arr , int low , int high){
    int pivot = arr[low] ;
    int i = low ;
    int j = high;
    while(i<j){
        while(arr[i]<= pivot && i<=high-1){
            i++;
        }
        while (pivot<arr[j] && j>=low+1)
        {
            j--;
        }

        if(i<j) swap(arr[i] , arr[j]);
        
    }

    swap (arr[low] , arr[j]);

    return j;
}

void quickSort(vector <int> &arr , int low , int high){
    if(low<high){
        int partIndex = part(arr , low , high);
        quickSort(arr , low , partIndex - 1);
        quickSort(arr , partIndex + 1 , high);
    }
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

    quickSort(arr , 0 , n-1 );

    cout<<"Sorted array :";
        for (int i = 0; i < n; i++)
        {
           cout<<arr[i]<<" ";
        }


    


    return 0;
}



//TC
// O(nlogn)

//SC ==> O(log n)
//we did not count recursion stack space in space complexity but do count the space taken in each recursion space