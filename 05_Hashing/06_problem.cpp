//find the hisghest and the lowest frequency of the given data or array or map

#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;

    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter all the elements of array: ";

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }


    // Store frequency of each element
    unordered_map<int, int> mpp;

    for(int i = 0; i < n; i++) {
        mpp[arr[i]]++;
    }


    // Find highest and lowest frequency
    pair<int, int> high = {INT_MIN, 0};
    pair<int, int> low = {INT_MAX, INT_MAX};

    for(auto it : mpp) {

        // Highest frequency
        if(it.second > high.second) {
            high.second = it.second;
            high.first = it.first;
        }

        // Lowest frequency
        if(it.second < low.second) {
            low.second = it.second;
            low.first = it.first;
        }
    }


    cout << "\nThe element with lowest frequency is: "
         << low.first
         << " with frequency: "
         << low.second << endl;

    cout << "The element with highest frequency is: "
         << high.first
         << " with frequency: "
         << high.second << endl;


    return 0;
}


// TIME COMPLEXITY:
//     O(N) average

// SPACE COMPLEXITY:
//     O(N)

// Why?
//     - Vector stores N elements → O(N)
//     - unordered_map stores K distinct elements → O(K)
//     - Frequency calculation → O(N) average
//     - Finding min/max frequency → O(K)
//     - Since K ≤ N → Overall O(N)

// IMPORTANT:
//     unordered_map → O(1) average
    // unordered_map → O(N) worst case