//sort an array of 0 ,1 and 2

//Method 1 --> brute force --> using any of the sorting algorithm

//Method 2 --> in one loop just count number of 0 , 1, 2 , then in another loop place them in original array on three short loops 
//TC O(n) or {n+n} and SC O(1)


//Dutch National Flag Algorithm

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements (0, 1 and 2): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

/*
Time Complexity: O(n)
- Each element is processed at most a constant number of times.
- The algorithm traverses the array using three pointers.

Space Complexity: O(1)
- Sorting is performed in-place.
- Only three pointers are used (low, mid, high).
- No extra array is required.
*/