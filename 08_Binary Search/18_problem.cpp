//find the kth element of two sorted array
//i.e we need to find out what kth elemnt would be if we merge those two sorted array

//method 1 --> brute foce --? merge in third array and find out the kth element 


//method 2
//we can use similar concept as we use in median method 
//like we will formulate left half to be exact k no. of element then display that element and return (max(l1,l2))

#include <bits/stdc++.h>
using namespace std;

int main() {

    int n1, n2, k;

    cout << "Enter size of first array: ";
    cin >> n1;

    vector<int> a(n1);

    cout << "Enter elements of first sorted array: ";
    for(int i = 0; i < n1; i++) {
        cin >> a[i];
    }

    cout << "Enter size of second array: ";
    cin >> n2;

    vector<int> b(n2);

    cout << "Enter elements of second sorted array: ";
    for(int i = 0; i < n2; i++) {
        cin >> b[i];
    }

    cout << "Enter the value of k: ";
    cin >> k;

    // Always do binary search on the smaller array
    if(n1 > n2) {
        swap(a, b);
        swap(n1, n2);
    }

    int low = max(k - n2, 0);
    int high = min(k, n1);

    int left = k;

    while(low <= high) {

        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;

        int l1 = INT_MIN;
        int l2 = INT_MIN;

        int r1 = INT_MAX;
        int r2 = INT_MAX;

        if(mid1 < n1)
            r1 = a[mid1];

        if(mid2 < n2)
            r2 = b[mid2];

        if(mid1 - 1 >= 0)
            l1 = a[mid1 - 1];

        if(mid2 - 1 >= 0)
            l2 = b[mid2 - 1];

        if(l1 <= r2 && l2 <= r1) {

            cout << "The " << k << "th element is: "
                 << max(l1, l2) << endl;

            return 0;
        }

        else if(l1 > r2) {
            high = mid1 - 1;
        }

        else {
            low = mid1 + 1;
        }
    }

    cout << "Invalid input or kth element not found." << endl;

    return 0;

    // Time Complexity: O(log(min(n1, n2)))
    // Space Complexity: O(1)
}