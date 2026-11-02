//find out the median in a row wise sorted 2D matrix

#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int>& arr, int n, int x) {

    int low = 0;
    int high = n - 1;
    int ans = n;

    while(low <= high) {

        int mid = (low + high) / 2;

        // Maybe an answer
        if(arr[mid] > x) {
            ans = mid;

            // Look for a smaller index on the left
            high = mid - 1;
        }

        else {
            // Look on the right
            low = mid + 1;
        }
    }

    return ans;
}

int countSmallEqual(vector<vector<int>>& matrix, int n, int m, int x) {

    int cnt = 0;

    for(int i = 0; i < n; i++) {
        cnt += upperBound(matrix[i], m, x);
    }

    return cnt;
}

int main() {

    int n, m;

    cout << "Enter number of rows: ";
    cin >> n;

    cout << "Enter number of columns: ";
    cin >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    cout << "Enter the row-wise sorted matrix: " << endl;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    int low = INT_MAX;
    int high = INT_MIN;

    // Find the minimum and maximum possible values
    for(int i = 0; i < n; i++) {

        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][m - 1]);
    }

    int required = (n * m) / 2;

    while(low <= high) {

        int mid = low + (high - low) / 2;

        int smallEqual = countSmallEqual(matrix, n, m, mid);

        if(smallEqual <= required) {
            low = mid + 1;
        }

        else {
            high = mid - 1;
        }
    }

    cout << "Median of the matrix is: " << low << endl;

    return 0;

    // Time Complexity: O(n * log(m) * log(max-min))
    // Space Complexity: O(1)
}