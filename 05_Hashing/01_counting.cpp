// Given an array, count how many times each number occurs, and then answer queries about those frequencies quickly.

#include <bits/stdc++.h>
using namespace std;

int main() {

    // -------------------- INPUT ARRAY --------------------

    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " elements: ";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }


    // -------------------- PRECOMPUTATION --------------------

    // hash[i] will store how many times the number 'i' occurs
    // Here, we assume array elements are between 0 and 12.
    int hash[13] = {0};

    // Count the frequency of each element
    for (int i = 0; i < n; i++) {
        hash[arr[i]]++;
    }


    // -------------------- QUERIES --------------------

    int q;

    cout << "\nEnter the number of queries: ";
    cin >> q;

    cout << "\n----- Query Results -----\n";

    while (q--) { // this means run the loop the q times 

        int number;

        cout << "Enter the number to search: ";
        cin >> number;

        // Fetch the precomputed frequency
        cout << "Frequency of " << number
             << " = " << hash[number] << endl;
    }


    return 0;
}


// Why use Global Hash Array for 10⁶ / 10⁷?
// >>Large array = large memory requirement
// >>10⁶ int ≈ 4 MB
// >>10⁷ int ≈ 40 MB
// >>If a large array is declared inside a function, it goes to the stack.
// >>Stack memory is limited → large arrays can cause Stack Overflow.
// >>Declaring the hash array globally puts it in static/global memory instead of the stack.
// >>Global arrays are automatically initialized to 0.


// #include <bits/stdc++.h>
// using namespace std;

// int hash[10000000];

// int main() {

//     use hash here

// }