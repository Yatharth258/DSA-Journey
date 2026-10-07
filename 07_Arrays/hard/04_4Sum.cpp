//4 Sum --> almost similar to 3 sum problem 
//M1 --> Brute force
//M2 --> Using hash , executing loops three times , and assuming last elemnt as {k-a-b-c}

//M3

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

    int target;
    cout << "Enter target: ";
    cin >> target;

    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {

        // Skip duplicate first elements
        if (i > 0 && arr[i] == arr[i - 1])
            continue;

        for (int j = i + 1; j < n; j++) {

            // Skip duplicate second elements
            if (j > i + 1 && arr[j] == arr[j - 1])
                continue;

            int k = j + 1;
            int l = n - 1;

            while (k < l) {

                long long sum = (long long)arr[i] + arr[j] + arr[k] + arr[l];

                if (sum < target) {
                    k++;
                }
                else if (sum > target) {
                    l--;
                }
                else {

                    vector<int> temp = {
                        arr[i],
                        arr[j],
                        arr[k],
                        arr[l]
                    };

                    ans.push_back(temp);

                    k++;
                    l--;

                    // Skip duplicates
                    while (k < l && arr[k] == arr[k - 1])
                        k++;

                    while (k < l && arr[l] == arr[l + 1])
                        l--;
                }
            }
        }
    }

    for (auto it : ans) {
        for (auto x : it) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}

// Time Complexity: O(n^3)
// Space Complexity: O(n)   // excluding the output vector