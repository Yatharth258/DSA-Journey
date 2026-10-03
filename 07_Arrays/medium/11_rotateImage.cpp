//Rotate an 2D array in clockwise direction by 90 degree

//Solution--> Transpose that 2D matrix --> Reverse each column

#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;

    cout<<"Enter the size of the square matrix: ";
    cin>>n;

    vector<vector<int>> matrix(n, vector<int>(n));

    cout<<"Enter the elements of the matrix: ";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin>>matrix[i][j];
        }
    }

    // Transpose of the matrix
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse each row
    for(int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }

    cout<<"Matrix after 90 degree clockwise rotation is:"<<endl;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

/*
Time Complexity: O(n^2)
- Transposing the matrix takes O(n^2).
- Reversing each row takes O(n^2).
- Overall TC = O(n^2).

Space Complexity: O(1) auxiliary space
- No extra matrix is created.
- Only a few variables are used.
- Overall SC = O(1).
*/