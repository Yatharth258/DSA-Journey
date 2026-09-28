#include <bits/stdc++.h>
using namespace std;

int main() {

    // -------------------- INPUT ARRAY --------------------

    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter " << n << " elements: ";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }


    // -------------------- PRECOMPUTATION --------------------

    // map stores:
    // number -> frequency

    map<int, int> mpp;

    // Count frequency of each number
    for (int i = 0; i < n; i++) {
        mpp[arr[i]]++;
    }



    // -------------------- QUERIES --------------------

    int q;

    cout << "\nEnter the number of queries: ";
    cin >> q;

    cout << "\n----- Query Results -----\n";

    while (q--) {

        int number;

        cout << "Enter the number to search: ";
        cin >> number;

        // Fetch frequency from map
        cout << "Frequency of " << number
             << " = " << mpp[number] << endl;
    }


    return 0;
}