//Print the rray in spiral order 
//Our order --> right-->bottom-->left-->up
//There is only one solution , not any brute force approach



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

    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = m - 1;

    cout<<"Spiral order is: ";

    while(top <= bottom && left <= right)
    {
        // Left to Right
        for(int j = left; j <= right; j++)
        {
            cout<<matrix[top][j]<<" ";
        }
        top++;

        // Top to Bottom
        for(int i = top; i <= bottom; i++)
        {
            cout<<matrix[i][right]<<" ";
        }
        right--;

        // Right to Left
        if(top <= bottom)
        {
            for(int j = right; j >= left; j--)
            {
                cout<<matrix[bottom][j]<<" ";
            }
            bottom--;
        }

        // Bottom to Top
        if(left <= right)
        {
            for(int i = bottom; i >= top; i--)
            {
                cout<<matrix[i][left]<<" ";
            }
            left++;
        }
    }

    return 0;
}

/*
Time Complexity: O(n * m)
- Every element of the matrix is visited exactly once.
- Overall TC = O(n * m).

Space Complexity: O(1)
- Only four pointer variables are used.
- No extra matrix or array is created.
- Overall SC = O(1).
*/