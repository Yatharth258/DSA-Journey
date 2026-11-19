//Flood fill algorithm 

// An image is represented by a 2-D array of integers, each integer
// representing the pixel value of the image.
// Given a coordinate (sr, sc) representing the starting pixel (row
// and column) of the flood fill, and a pixel value newColor, "flood
// fill" the image.
// To perform a "flood fill", consider the starting pixel, plus any
// pixels connected 4-directionally to the starting pixel of the same
// color as the starting pixel, plus any pixels connected 4-
// directionally to those pixels (also with the same color as the
// starting pixel), and so on. Replace the color of all of the
// aforementioned pixels with the newColor. 



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:

    void dfs(int row, int col, vector<vector<int>>& ans,
             vector<vector<int>>& image, int newColor,
             int delRow[], int delCol[], int iniColor) {

        ans[row][col] = newColor;

        int n = image.size();
        int m = image[0].size();

        for(int i = 0; i < 4; i++) {

            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if(nrow >= 0 && nrow < n &&
               ncol >= 0 && ncol < m &&
               image[nrow][ncol] == iniColor &&
               ans[nrow][ncol] != newColor) {

                dfs(nrow, ncol, ans, image, newColor,
                    delRow, delCol, iniColor);
            }
        }
    }

public:

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int newColor) {

        int iniColor = image[sr][sc];

        vector<vector<int>> ans = image;

        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};

        // If initial color and new color are same
        // No changes required
        if(iniColor == newColor) {
            return ans;
        }

        dfs(sr, sc, ans, image, newColor,
            delRow, delCol, iniColor);

        return ans;
    }
};

int main() {

    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    int sr = 1;
    int sc = 1;
    int newColor = 2;

    Solution obj;

    vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);

    cout << "Flood Filled Image:" << endl;

    for(auto row : ans) {
        for(auto pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
Time Complexity: O(N * M)

- In the worst case, every pixel is visited once.
- Each pixel checks 4 neighbouring pixels.
- Therefore, TC = O(N * M).

Space Complexity: O(N * M)

- Answer matrix: O(N * M).
- Recursive DFS stack: O(N * M) in the worst case.
- Therefore, auxiliary SC = O(N * M).
*/
