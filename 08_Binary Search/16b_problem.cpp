//more optimal way for the same gas station problem 
//this time using binary search approach for better space complexity


#include <bits/stdc++.h>
using namespace std;

int numberOfGasStationsRequired(long double dist, vector<int>& arr) {

    int cnt = 0;

    for(int i = 1; i < arr.size(); i++) {

        long double gap = arr[i] - arr[i - 1];

        int numberInBetween = ceil(gap / dist) - 1;

        cnt += numberInBetween;
    }

    return cnt;
}

int main() {

    int n, k;

    cout << "Enter the number of existing gas stations: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the positions of the gas stations:\n";

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the number of new gas stations to add: ";
    cin >> k;

    long double low = 0;
    long double high = 0;

    // Find the maximum distance between existing stations
    for(int i = 0; i < n - 1; i++) {
        high = max(high, (long double)(arr[i + 1] - arr[i]));
    }
    
    long double diff = 1e-6;

    while(high - low > diff) {

        long double mid = low + (high - low) / 2.0;

        int cnt = numberOfGasStationsRequired(mid, arr);

        if(cnt > k) {
            // We need more than k stations
            // So mid is too small
            low = mid;
        }
        else {
            // We can achieve this distance
            // Try to find an even smaller distance
            high = mid;
        }
    }

    cout << fixed << setprecision(6);

    cout << "Minimum possible maximum distance = " << high << endl;

    // TC: O(n * log(maxDistance / diff))
    //     For every binary search iteration,
    //     we traverse the array once.
    //
    // SC: O(1)
    //     No extra space is used apart from variables.

    return 0;
}