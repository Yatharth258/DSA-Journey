#include <bits/stdc++.h>
using namespace std;

int main() {

    // -------------------- INPUT STRING --------------------

    string s;

    cout << "Enter the string: ";
    cin >> s;


    // -------------------- PRECOMPUTATION --------------------

    // hash[0] -> frequency of 'a'
    // hash[1] -> frequency of 'b'
    // ...
    // hash[25] -> frequency of 'z'

    int hash[26] = {0};

    // Calculate frequency of each character
    for (int i = 0; i < s.length(); i++) {

        hash[s[i] - 'a']++;
    }


    // -------------------- QUERIES --------------------

    int q;

    cout << "Enter the number of queries: ";
    cin >> q;

    cout << "\n----- Query Results -----\n";

    while (q--) {

        char ch;

        cout << "Enter character to search: ";
        cin >> ch;

        // Fetch the precomputed frequency
        cout << "Frequency of '" << ch
             << "' = " << hash[ch - 'a'] << endl;
    }


    return 0;
}