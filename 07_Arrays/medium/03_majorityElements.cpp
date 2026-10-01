//Find the majority element
//in an array find an element which apperas more than n/2 , then display that element 

//BRUTE FORCE --> count for each elemnt 

//Method 2 --> create an hashmap --> store the freq of each elemnt --> iterate through map and check which elemnt is occuring more than n/2 times
//TC Oo(nlogn)+O(n)   SC O(n)

//Method 3 
//MORE's VOTING ALGORITHM


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int count = 0;
    int ele;

    // Finding the potential majority element
    for (int i = 0; i < n; i++) {
        if (count == 0) {
            ele = arr[i];
            count = 1;
        }
        else if (arr[i] == ele) {
            count++;
        }
        else {
            count--;
        }
    }

    // Verifying the majority element
    count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == ele) {
            count++;
        }
    }

    if (count > n / 2) {
        cout << "Majority element is: " << ele;
    }
    else {
        cout << "No majority element exists";
    }

    return 0;
}

/*
Time Complexity: O(n)
- First traversal finds the potential majority element: O(n).
- Second traversal verifies its frequency: O(n).
- Overall: O(n).

Space Complexity: O(1)
- Only a few variables are used.
- No extra array or data structure is required.
*/




