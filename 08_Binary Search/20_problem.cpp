//search for the target in sorted 2D matrix

//formula for converting 1D coordinates to 2D coordinates 
// assume 1D coordinate to be k and there needs to be converted for 2D matrix n*m
// therefore in 2D : Row no= k/m and Colums no.=k%m , where m= no.of columns in that 2D array 

#include <bits/stdc++.h>
using namespace std;

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

    int low = 0;
    int high = n * m - 1;

    while(low <= high) {

        int mid = (low + high) / 2;

        int row = mid / m;
        int col = mid % m;

        if(mat[row][col] == target) {
            cout << "Target found!" << endl;
            return 0;
        }

        else if(mat[row][col] < target) {
            low = mid + 1;
        }

        else {
            high = mid - 1;
        }
    }

    cout << "Target not found!" << endl;

    return 0;

    // Time Complexity: O(log(n * m))
    // Space Complexity: O(1)
}
