#include <bits/stdc++.h>
using namespace std;

int main() {

    // -------------------- INPUT STRING --------------------

    string s;

    cout << "Enter the string: ";
    cin >> s;


    // -------------------- PRECOMPUTATION --------------------

    // map stores:
    // character -> frequency

    map<char, int> mpp;

    // Count frequency of each character
    for (int i = 0; i < s.length(); i++) {
        mpp[s[i]]++;
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

        // Fetch frequency from map
        cout << "Frequency of '" << ch
             << "' = " << mpp[ch] << endl;
    }


    return 0;
}





// For normal frequency-counting problems,
//     unordered_map is often preferred when
//     we don't need the keys in sorted order.

/*
    ==================== MAP vs UNORDERED_MAP ====================

    1. MAP
    -------
    map stores keys in SORTED ORDER.

    Internally uses a self-balancing BST (usually Red-Black Tree).

    Time Complexity:
        Insert       -> O(log N)
        Search       -> O(log N)
        Access       -> O(log N)
        Delete       -> O(log N)

    Example:
        map<int, int> mpp;

        mpp[5]++;
        mpp[2]++;
        mpp[10]++;

    Keys will be stored in sorted order:
        2, 5, 10


    2. UNORDERED_MAP
    ----------------
    unordered_map uses a HASH TABLE.

    Keys are NOT stored in sorted order.

    Average Time Complexity:
        Insert       -> O(1)
        Search       -> O(1)
        Access       -> O(1)
        Delete       -> O(1)

    Worst-case Time Complexity:
        O(N)

    Example:
        unordered_map<int, int> mpp;

        mpp[5]++;
        mpp[2]++;
        mpp[10]++;

    Order of keys is NOT guaranteed.


    3. WHICH ONE TO USE?
    --------------------

    Use MAP when:
        -> You need keys in sorted order.
        -> You need ordered operations.
        -> O(log N) is acceptable.

    Use UNORDERED_MAP when:
        -> You only need fast insertion/search.
        -> You DON'T care about sorted order.
        -> You are doing frequency counting.
        -> You want O(1) average lookup.


    4. FOR FREQUENCY COUNTING
    --------------------------

    map:
        map<int, int> mpp;

        Precomputation -> O(N log N)
        Q queries      -> O(Q log N)
        Total           -> O((N + Q) log N)


    unordered_map:
        unordered_map<int, int> mpp;

        Precomputation -> O(N) average
        Q queries      -> O(Q) average
        Total           -> O(N + Q) average


    5. EASY WAY TO REMEMBER
    ------------------------

        MAP
        ↓
        Sorted
        ↓
        Tree
        ↓
        O(log N)


        UNORDERED_MAP
        ↓
        Not sorted
        ↓
        Hash Table
        ↓
        O(1) Average


    IMPORTANT:
        unordered_map is NOT always O(1).

        Average case -> O(1)
        Worst case   -> O(N)

*/