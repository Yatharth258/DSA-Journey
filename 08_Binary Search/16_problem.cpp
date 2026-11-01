// You are given the positions of existing gas stations on a straight road.

// You can build k additional gas stations anywhere on the road.

// Your goal is:
// Place the k new gas stations such that the maximum distance between any two consecutive gas stations is as small as possible.




#include <bits/stdc++.h>
using namespace std;

long double minimiseMaxDistance(vector<int> &arr, int k) {

    int n = arr.size();

    // howMany[i] tells how many gas stations
    // are placed between arr[i] and arr[i+1]
    vector<int> howMany(n - 1, 0);

    // {current maximum distance, section index}
    priority_queue<pair<long double, int>> pq;

    // Initially, there are no extra gas stations
    // so every section has its original distance
    for(int i = 0; i < n - 1; i++) {

        long double diff = arr[i + 1] - arr[i];

        pq.push({diff, i});
    }

    // Place k gas stations one by one
    for(int gasStations = 1; gasStations <= k; gasStations++) {

        // Get the section having the largest distance
        auto tp = pq.top();
        pq.pop();

        int secInd = tp.second;

        // Place one gas station in this section
        howMany[secInd]++;

        long double iniDiff = arr[secInd + 1] - arr[secInd];

        // Divide the section into (stations + 1) parts
        long double newSecLen =
            iniDiff / (long double)(howMany[secInd] + 1);

        // Insert the new maximum distance of this section
        pq.push({newSecLen, secInd});
    }

    // Largest remaining section is our answer
    return pq.top().first;
}

int main() {

    int n, k;

    cout << "Enter the number of gas stations already present: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the positions of the gas stations:\n";

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the number of new gas stations to add: ";
    cin >> k;

    long double ans = minimiseMaxDistance(arr, k);

    cout << fixed << setprecision(6);

    cout << "Minimum possible maximum distance = " << ans << endl;

    // TC: O(n log n + k log n)
    //     O(n log n) for inserting initial sections
    //     O(k log n) for placing k gas stations
    //
    // SC: O(n)
    //     priority queue + howMany array

    return 0;
}