//find the peak element in the 2D matrix 
//nothing is to be in soretd
//peak element is an element which is greater than its top , right , bottom and left elements

#include <bits/stdc++.h>
using namespace std;

int findMaxIndex(vector<vector<int>>& mat, int n, int m, int col) {

    int maxValue = -1;
    int index = -1;

    for(int i = 0; i < n; i++) {

        if(mat[i][col] > maxValue) {
            maxValue = mat[i][col];
            index = i;
        }
    }

    return index;
}

int main() {

    int n, m;

    cout << "Enter number of rows: ";
    cin >> n;

    cout << "Enter number of columns: ";
    cin >> m;

    vector<vector<int>> mat(n, vector<int>(m));

    cout << "Enter the matrix: " << endl;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    int low = 0;
    int high = m - 1;

    while(low <= high) {

        int mid = (low + high) / 2;

        int maxRowIndex = findMaxIndex(mat, n, m, mid);

        int left = (mid - 1 >= 0)
                   ? mat[maxRowIndex][mid - 1]
                   : -1;

        int right = (mid + 1 < m)
                    ? mat[maxRowIndex][mid + 1]
                    : -1;

        if(mat[maxRowIndex][mid] > left &&
           mat[maxRowIndex][mid] > right) {

            cout << "Peak element is: "
                 << mat[maxRowIndex][mid] << endl;

            cout << "Peak element position: ["
                 << maxRowIndex << ", " << mid << "]" << endl;

            return 0;
        }

        else if(mat[maxRowIndex][mid] < left) {
            high = mid - 1;
        }

        else {
            low = mid + 1;
        }
    }

    cout << "Peak element not found." << endl;

    return 0;

    // Time Complexity: O(n * log(m))
    // Space Complexity: O(1)
}