#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,m;

    cout<<"Enter the number of rows: ";
    cin>>n;

    cout<<"Enter the number of columns: ";
    cin>>m;

    vector<vector<int>> matrix(n, vector<int>(m));

    cout<<"Enter the elements of the matrix: ";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin>>matrix[i][j];
        }
    }

    int col0 = 1;

    // Mark the first row and first column
    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j < m; j++)
        {
            if(matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }

        if(matrix[i][0] == 0)
        {
            col0 = 0;
        }
    }

    // Make elements zero using the markers
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < m; j++)
        {
            if(matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }

    // Make first row zero if required
    if(matrix[0][0] == 0)
    {
        for(int j = 0; j < m; j++)
        {
            matrix[0][j] = 0;
        }
    }

    // Make first column zero if required
    if(col0 == 0)
    {
        for(int i = 0; i < n; i++)
        {
            matrix[i][0] = 0;
        }
    }

    cout<<"New matrix is:"<<endl;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

/*
Time Complexity: O(n * m)
- First traversal takes O(n * m).
- Second traversal takes O(n * m).
- Making first row and first column zero takes O(n + m).
- Overall TC = O(n * m).

Space Complexity: O(1)
- No extra row[] or col[] arrays are used.
- Only one extra variable col0 is used.
- Overall SC = O(1).
*/