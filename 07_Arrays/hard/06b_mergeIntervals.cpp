//Method 2

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
    if (ans.empty() || arr[i][0] > ans.back()[1])
    {
        ans.push_back(arr[i]);
    }
    else
    {
        ans.back()[1] = max(ans.back()[1], arr[i][1]);
    }
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

//TC nlogn+n
//SC O(n)