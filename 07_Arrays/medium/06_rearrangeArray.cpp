// rearrange an array by sign

//Brute force approach-
// crate two arrays positive and negative and store respective values 
// reassign value in main array

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n), pos, neg;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        if (arr[i] > 0)
            pos.push_back(arr[i]);
        else
            neg.push_back(arr[i]);
    }

    vector<int> result(n);

    for (int i = 0; i < n / 2; i++) {
        result[2 * i] = pos[i];
        result[2 * i + 1] = neg[i];
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }

    return 0;
}

    // Time: O(n) — three linear traversals in total.

// Space: O(n) — two auxiliary arrays and the result array.