//Best time to buy and sell the stock

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the stock prices: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int mini = INT_MAX;
    int maxi = 0;

    int buyDay = -1, sellDay = -1;
    int minIndex = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] < mini) {
            mini = arr[i];
            minIndex = i;
        }

        int profit = arr[i] - mini;

        if (profit > maxi) {
            maxi = profit;
            buyDay = minIndex + 1;
            sellDay = i + 1;
        }
    }

    cout << "Maximum profit is: " << maxi << endl;

    if (maxi > 0) {
        cout << "Buy on day: " << buyDay << endl;
        cout << "Sell on day: " << sellDay << endl;
    }
    else {
        cout << "No profit possible" << endl;
    }

    return 0;
}

/*
Time Complexity: O(n)
- Single traversal of the array.
- Each iteration takes O(1) time.

Space Complexity: O(1)
- Only a few extra variables are used.
- No additional data structure is required.
*/