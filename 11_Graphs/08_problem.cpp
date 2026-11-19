//Rotten oranges 

// Given a grid of dimension nxm where each cell in the grid can have
// values 0, 1 or 2 which has the following meaning:
// 0: Empty cell
// 1: Cells have fresh oranges
// 2: Cells have rotten oranges
// We have to determine what is the minimum time required to rot all
// oranges. A rotten orange at index [i,j] can rot other fresh orange at
// indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit
// time.



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Function to find minimum time required to rot all oranges
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> q;

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int cntFresh = 0;

        // Store all initially rotten oranges and count fresh oranges
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
                else {
                    vis[i][j] = 0;

                    if(grid[i][j] == 1) {
                        cntFresh++;
                    }
                }
            }
        }

        int tm = 0;
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};

        int cnt = 0;

        // BFS traversal
        while(!q.empty()) {

            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;

            tm = max(tm, t);

            q.pop();

            for(int i = 0; i < 4; i++) {

                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow >= 0 && nrow < n &&
                   ncol >= 0 && ncol < m &&
                   vis[nrow][ncol] == 0 &&
                   grid[nrow][ncol] == 1) {

                    q.push({{nrow, ncol}, t + 1});

                    vis[nrow][ncol] = 2;

                    cnt++;
                }
            }
        }

        if(cnt != cntFresh) {
            return -1;
        }

        return tm;
    }
};

int main() {

    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    Solution obj;

    cout << "Minimum time required: "
         << obj.orangesRotting(grid) << endl;

    return 0;
}

/*
Time Complexity: O(N * M)

- Every cell is visited at most once.
- Every cell checks 4 neighbouring cells.
- Therefore, TC = O(N * M).

Space Complexity: O(N * M)

- Visited matrix: O(N * M).
- Queue: O(N * M) in the worst case.
- Therefore, SC = O(N * M).
*/
