//KOKO eating bananas
//return the minimum integer k such that kokocan eat all the bananas within h hours

#include <bits/stdc++.h>
using namespace std;

// Find maximum element
int findMax(vector<int>& arr)
{
    int maxi = INT_MIN;

    for(int i = 0; i < arr.size(); i++)
    {
        maxi = max(maxi, arr[i]);
    }

    return maxi;
}

// Calculate total hours needed at given rate
int calculateTotalHours(vector<int>& arr, int hourly)
{
    int totalH = 0;

    for(int i = 0; i < arr.size(); i++)
    {
        totalH += ceil((double)arr[i] / hourly);
    }

    return totalH;
}

int main()
{
    int n;

    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the number of bananas in each pile: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int h;
    cout << "Enter the number of hours: ";
    cin >> h;

    if(h < n)
    {
         cout << "It is not possible to finish all bananas within given hours.";
         return 0;
    }

    int low = 1;
    int high = findMax(arr);

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        int totalH = calculateTotalHours(arr, mid);

        if(totalH <= h)
        {
            // Rate is sufficient, try a smaller rate
            high = mid - 1;
        }
        else
        {
            // Rate is too slow, increase it
            low = mid + 1;
        }
    }

    cout << "Minimum eating rate is: " << low;

    return 0;
}

/*
    Time Complexity: O(n * log(max(arr)))
    Space Complexity: O(1)

    Binary Search is applied on the eating rate.

    low  = 1
    high = maximum bananas in a pile
*/