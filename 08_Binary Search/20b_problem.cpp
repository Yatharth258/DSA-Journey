//this time entire 2D  array is not necessarily sorted but each individual row and columns of matrix are sorted 
//Method --> Stairccase approach 

#include <bits/stdc++.h>
using namespace std;

bool searchElement(vector<vector<int>>& mat, int target) {

    int n = mat.size();
    int m = mat[0].size();

    int row = 0;
    int col = m - 1;

    while(row < n && col >= 0) {

        if(mat[row][col] == target) {
            return true;
        }

        else if(mat[row][col] < target) {
            row++;
        }

        else {
            col--;
        }
    }

    return false;
}

int main() {

    int n, m, target;

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

    cout << "Enter target: ";
    cin >> target;

    if(searchElement(mat, target)) {
        cout << "Target found!" << endl;
    }
    else {
        cout << "Target not found!" << endl;
    }

    return 0;

    // Time Complexity: O(n + m)
    // Space Complexity: O(1)
}