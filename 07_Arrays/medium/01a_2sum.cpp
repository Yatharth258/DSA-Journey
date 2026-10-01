//Method 3
//using two pointer method 

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

    int tar;
    cout << "Enter the target: ";
    cin >> tar;

    // Store original indices before sorting
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        v.push_back({arr[i], i});
    }

    // Sort based on array elements
    sort(v.begin(), v.end());

    int left = 0;
    int right = n - 1;
    bool isPresent = false;

    while (left < right) {
        int sum = v[left].first + v[right].first;

        if (sum == tar) {
            cout << v[left].second << " " << v[right].second << endl;
            isPresent = true;
            break;
        }
        else if (sum > tar) {
            right--;
        }
        else {
            left++;
        }
    }

    if (!isPresent) {
        cout << "The given target is not present in the array";
    }

    return 0;
}

/*
Time Complexity: O(n log n)
- Creating the pair vector: O(n)
- Sorting the array: O(n log n)
- Two-pointer traversal: O(n)
- Overall: O(n log n)

Space Complexity: O(n)
- Extra pair vector stores elements and their original indices.
- Sorting may also use additional stack space.
*/