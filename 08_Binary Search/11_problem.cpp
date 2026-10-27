//Find the minimum number of days to make M boquet
//you will be given an array in which number represnt how much time that index flower take too bloom
//also will be given 'r' as number of bouquet and 'b' as number of consescutive flower required to make a bouqet
//we need to return minimum number of days to make the r bouqet

#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int> &arr, int day, int r, int b)
{
    int count = 0;
    int bouquets = 0;

    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] <= day)
        {
            count++;
        }
        else
        {
            bouquets += count / b;
            count = 0;
        }
    }

    bouquets += count / b;

    return bouquets >= r;
}

int main()
{
    int n, r, b;

    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter number of bouquets: ";
    cin >> r;

    cout << "Enter flowers required for each bouquet: ";
    cin >> b;

    long long required = r * 1LL * b;

    if(required > n)
    {
        cout << -1;
        return 0;
    }

    int mini = INT_MAX;
    int maxi = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }

    int low = mini;
    int high = maxi;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if(possible(arr, mid, r, b))
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << "Minimum day: " << low;

    return 0;
}

// TC: O(n * log(maxi - mini + 1))
// SC: O(1) auxiliary space