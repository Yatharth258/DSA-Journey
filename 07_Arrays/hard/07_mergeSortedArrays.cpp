//Merge two sorted arrays without using any extra spaces

// ex- arr1=[1,3,5,7] and arr2=[2,5,6,9] after sorting 
// first array [1,2,3,5] and second array as [5,6,7,9]

// method1 .

// void merge(long long arr1[], long long arr2[], int n, int m)
// {
    // int left = n - 1;   // Last element of arr1
    // int right = 0;      // First element of arr2

    // Compare largest of arr1 with smallest of arr2
    // while (left >= 0 && right < m)
    // {
    //     if (arr1[left] > arr2[right])
    //     {
            // Wrong elements are in respective arrays, so swap
        //     swap(arr1[left], arr2[right]);

        //     left--;
        //     right++;
        // }
        // else
        // {
            // Arrays are already correctly divided
    //         break;
    //     }
    // }
    // Restore sorted order after swapping
//     sort(arr1, arr1 + n);
//     sort(arr2, arr2 + m);
// }


//TC --> O(min(n.m)+nlogn+mlogm)
//SC--> O(1)

//Method 2 --> GAP METHOD (uses dhell sort technique)



#include <bits/stdc++.h>
using namespace std;

void swapIfGreater(vector<int>& arr1 , vector<int>& arr2 ,int left , int right){
    if(arr1[left]>arr2[right]){
        swap(arr1[left],arr2[right]);
    }
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<int> arr1(n);

    cout << "Enter the elements(in sorted order): ";
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    int m;
    cout << "Enter the value of m: ";
    cin >> m;

    vector<int> arr2(m);

    cout << "Enter the elements(in sorted order): ";
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    int len = n+m;
    int gap = (len/2)+(len%2);

    while(gap>0){
        int left = 0 ;
        int right = gap + left;
        while(right< len){
            //case1: left is in arr1 and right is in arr2
            if(left<n && right>=n){
                swapIfGreater(arr1 , arr2 , left , right-n);
            }//case2: both left and right are on arr2
            else if(left>=n){
                swapIfGreater(arr2 , arr2 , left-n , right-n);
            }//case3: both the left and right are on arr1
            else{
                swapIfGreater(arr1 , arr1 , left , right);
            }
            left++;
            right++;
        }
        if(gap==1) break;
        gap = gap/2 + gap%2;
    }

    cout<<"array1: ";
    for (int i = 0; i < n; i++)
    {
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    cout<<"array2: ";
    for (int i = 0; i < m; i++)
    {
        cout<<arr2[i]<<" ";
    }
    

    return 0;
}

//TC O(log2(n+m) * (n+m))
//SC O(1)