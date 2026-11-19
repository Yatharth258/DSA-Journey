// Number of Islands | Number of Connected Components in Matrix
// you will be given a 2D matrix , where 0 represnt water and 1 represent island
//you need to find out how many new island are occuring if we join connected isalnd and count them a single one 




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:

    void bfs(int row, int col, vector<vector<int>>& vis,
             vector<vector<char>>& grid) {

        vis[row][col] = 1;

        queue<pair<int, int>> q;
        q.push({row, col});

        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty()) {

            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            // Traverse all 8 directions
            for(int delrow = -1; delrow <= 1; delrow++) {
                for(int delcol = -1; delcol <= 1; delcol++) {

                    int nrow = row + delrow;
                    int ncol = col + delcol;

                    if(nrow >= 0 && nrow < n &&
                       ncol >= 0 && ncol < m &&
                       grid[nrow][ncol] == '1' &&
                       !vis[nrow][ncol]) {

                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }

public:

    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int cnt = 0;

        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {

                if(!vis[row][col] && grid[row][col] == '1') {

                    cnt++;
                    bfs(row, col, vis, grid);
                }
            }
        }

        return cnt;
    }
};

int main() {

    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'0', '1', '0', '0', '1'},
        {'1', '0', '0', '1', '1'},
        {'0', '0', '0', '0', '0'}
    };

    Solution obj;

    cout << "Number of Islands: " << obj.numIslands(grid) << endl;

    return 0;
}

/*
Time Complexity: O(N * M)

- Every cell is visited at most once.
- Each cell checks 9 possible positions.
- Therefore, O(N * M).

Space Complexity: O(N * M)

- Visited matrix: O(N * M).
- BFS queue: O(N * M) in the worst case.
- Therefore, O(N * M).
*/
