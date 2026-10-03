//SET MATRIX TO ZERO5
//in an 2D array , if any elemnt is 0 then marks all elemnt in that row and column as zero , consider only inital zero for this process not the further obtained zero

#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,m;
    cout<<"Enter the number of rows: ";
    cin>>n;

    cout<<"Enter the number of columns: ";
    cin>>m;

    vector<vector<int>> arr(n, vector<int>(m));

    cout<<"Enter the elements of the binary array: ";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin>>arr[i][j];
        }
    }

    vector<int> row(n, 0);
    vector<int> col(m, 0);

    // Mark the rows and columns which contain 0
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(arr[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    // Make marked rows and columns zero
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(row[i] == 1 || col[j] == 1){
                arr[i][j] = 0;
            }
        }
    }

    cout<<"New array is:"<<endl;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

/*
Time Complexity: O(n * m)
- First traversal of the matrix takes O(n * m).
- Second traversal of the matrix takes O(n * m).
- Overall TC = O(n * m).

Space Complexity: O(n + m)
- row[] takes O(n) space.
- col[] takes O(m) space.
- Overall SC = O(n + m).
*/