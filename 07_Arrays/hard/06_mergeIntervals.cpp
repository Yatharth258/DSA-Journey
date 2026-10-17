//Merge all the overlapping intervals  and find the out of minimum possible overallping interval
// Example:
// Input:
// intervals = {{1,3}, {2,6}, {8,10}, {9,12}, {15,18}}
// Final Answer:
// {{1,6}, {8,12}, {15,18}}


//Method 1 --> Brute force approach

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(2));

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "th Range: ";

        // Input: start and end of each range
        for (int j = 0; j < 2; j++)
        {
            cin >> arr[i][j];
        }
    }

    // Sort according to starting point
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        int start = arr[i][0];
        int end = arr[i][1];

        // If current interval is already covered
        if (!ans.empty() && end <= ans.back()[1])
        {
            continue;
        }

        // Check following intervals for overlap
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j][0] <= end)
            {
                end = max(end, arr[j][1]);
            }
            else
            {
                break;
            }
        }

        ans.push_back({start, end});
    }

    cout << "The minimum non-overlapping ranges are: ";

    for (auto it : ans)
    {
        cout << "{";
        for (auto x : it)
        {
            cout << x << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}

//TC is nlog + 2n(sorting + iterating)
//SC O(n)