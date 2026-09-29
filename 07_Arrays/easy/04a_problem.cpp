//remove duplicates from the sorted array

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

    int i = 0;
    while (i < (int)arr.size() - 1) {
        if (arr[i] == arr[i + 1]) {
            arr.erase(arr.begin() + i + 1);
        } else {
            i++;
        }
    }

    cout << "New array: ";
    for (int i = 0; i < (int)arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}


//  TC O(n square)  very much inefficent for large array {in best case TC O(n)}
// SC O(1)