//left rotate an array by k places without using an extra array 

//brute force approach ==> same as previous problem 

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the length of the array: ";
    cin >> n;

    if (n <= 0) return 0;

    vector<int> arr(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int d;
    cout << "Enter value d: ";
    cin >> d;

    d = d % n;

    // Store first d elements
    vector<int> temp(d);
    for (int i = 0; i < d; i++) {
        temp[i] = arr[i];
    }

    // Shift remaining elements to the left
    for (int i = d; i < n; i++) {
        arr[i - d] = arr[i];
    }

    // Copy stored elements to the end
    for (int i = 0; i < d; i++) {
        arr[n - d + i] = temp[i];
    }

    cout << "New array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}


//TC--> O(N+d)
//SC--> O(d)