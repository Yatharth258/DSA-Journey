//left rotate an array by one place without creating a new array 


// TC O(n) and SC O(1){this is extra space o)=(1) but in order to solve the prblem its needed o(n) when we are making an array}


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the length of the array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // BRUTE FORCE APPROACH

    int temp = arr[0];
    for (int i = 1; i < n; i++)
    {
        arr[i-1]=arr[i];
    }
    arr[n-1]=temp;


    cout << "New array: ";
    for (int i = 0; i < (int)arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}