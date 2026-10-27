/*
Question:
We have to ship all the packages within d days.

The packages must be shipped in the given order.

Find the minimum ship capacity such that all packages
can be shipped within d days.

Example:
weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
d = 5

We have to find the minimum possible capacity.
*/

#include <bits/stdc++.h>
using namespace std;


int findDays(vector<int> &weights, int capacity)
{
    int days = 1;
    int load = 0;

    for(int i = 0; i < weights.size(); i++)
    {
        if(load + weights[i] > capacity)
        {
            days++;
            load = weights[i];
        }
        else
        {
            load += weights[i];
        }
    }

    return days;
}

int main()
{
    int n, d;

    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> weights(n);

    cout << "Enter the weights: ";
    for(int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }

    cout << "Enter number of days: ";
    cin >> d;

    // Minimum possible capacity = maximum weight
    int low = *max_element(weights.begin(), weights.end());

    // Maximum possible capacity = total weight
    int high = accumulate(weights.begin(), weights.end(), 0);

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        int numberOfDays = findDays(weights, mid);

        if(numberOfDays <= d)
        {
            // We can ship within d days.
            // Try to find a smaller capacity.
            high = mid - 1;
        }
        else
        {
            // We need more capacity.
            low = mid + 1;
        }
    }

    cout << "Minimum capacity: " << low;

    
    return 0;
}


/*
Time Complexity:
findDays() takes O(n)
Binary search runs O(log(sum of weights))
TC = O(n * log(sum of weights))

Space Complexity:
O(1) auxiliary space
*/