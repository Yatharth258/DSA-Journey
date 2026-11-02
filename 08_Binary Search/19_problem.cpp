//find the row with the maximum 1's

#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> arr, int n, int x) {

    int low = 0;
    int high = n - 1;
    int ans = n;

    while(low <= high) {

        int mid = (low + high) / 2;

        // Maybe an answer
        if(arr[mid] >= x) {
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

int main() {

    int n, m;

    cout << "Enter number of rows: ";
    cin >> n;

    cout << "Enter number of columns: ";
    cin >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    cout << "Enter the matrix: " << endl;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    int cnt_max = 0;
    int index = -1;

    for(int i = 0; i < n; i++) {

        int firstOne = lowerBound(matrix[i], m, 1);

        int cnt_ones = m - firstOne;

        if(cnt_ones > cnt_max) {
            cnt_max = cnt_ones;
            index = i;
        }
    }

    cout << "Row with maximum number of 1s is: " << index << endl;
    cout << "Maximum number of 1s: " << cnt_max << endl;

    return 0;
}

// Time Complexity: O(n * log(m))
// Space Complexity: O(1)