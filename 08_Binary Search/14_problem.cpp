//you are given an array , i.e. basically the coordinates where cows can be placed and you will be given k cows
//your task is to find the minimum distance such that cows can be placed on those coordinated such that minimum distace could be maximised



#include <bits/stdc++.h>
using namespace std;

int countCows(vector<int> &stalls, int dist) {

    int cntCows = 1;
    int last = stalls[0];

    for (int i = 1; i < stalls.size(); i++) {

        if (stalls[i] - last >= dist) {
            cntCows++;
            last = stalls[i];
        }
    }

    return cntCows;
}

int main() {

    int n, k;
    cin >> n >> k;

    vector<int> stalls(n);

    for (int i = 0; i < n; i++) {
        cin >> stalls[i];
    }

    sort(stalls.begin(), stalls.end());

    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    int ans = 0;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        int cows = countCows(stalls, mid);

        if (cows >= k) {
            // mid distance is possible
            // try for a larger distance
            ans = mid;
            low = mid + 1;
        }
        else {
            // mid distance is not possible
            // try a smaller distance
            high = mid - 1;
        }
    }

    cout << ans << endl;

    // TC: O(n log n) for sorting
    //     + O(n log(maxDistance)) for binary search
    //     Overall: O(n log n + n log(maxDistance))
    //
    // SC: O(1) extra space
    //     (Ignoring input vector)

    return 0;
}