//Maximum Product Subarray

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int pre = 1;
    int suff = 1;
    int ans = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        // If product becomes 0, start a new subarray
        if(pre == 0)
            pre = 1;

        if(suff == 0)
            suff = 1;

        // Product from left side
        pre = pre * arr[i];

        // Product from right side
        suff = suff * arr[n - i - 1];

        // Store maximum product found so far
        ans = max(ans, max(pre, suff));
    }

    cout << "Maximum product subarray: " << ans << endl;

    return 0;
}

//TC O(n)
//SC O(1)