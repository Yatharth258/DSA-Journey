//3 Sum
// return triplet whose sum is equal to zero, return all those triplet



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

    int k;
    cout << "Enter target: ";
    cin >> k;

    set<vector<int>> st;

    for (int i = 0; i < n; i++) {
        set<int> hashSet;

        for (int j = i + 1; j < n; j++) {

            int third = k - arr[i] - arr[j];

            if (hashSet.find(third) != hashSet.end()) {
                vector<int> temp = {arr[i], arr[j], third};

                sort(temp.begin(), temp.end());

                st.insert(temp);
            }

            hashSet.insert(arr[j]);
        }
    }

    for (auto it : st) {
        for (auto x : it) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}

// Time Complexity: O(n^2 * log n)
// Space Complexity: O(n)
// Space Complexity: O(n^2)  // including result set