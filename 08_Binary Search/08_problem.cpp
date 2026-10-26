//find the square root of a number using binary search
//in case of any number whoch is not perfect square we are returning the ceil value of its sqrt

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int low = 1;
    int high = n;

    while(low <= high)
    {
        long long mid = low + (high - low) / 2; //BUG FIX: yha int use karne pe overflow ho sakta h while calculating val
        //becuase long long val = mid * mid; is expression mei phele int me mid*mid calculate karte h fir uski value ko val mei dalte h 

        // Use long long to avoid overflow
        long long val = mid * mid;

        if(val <= n)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << "Floor square root of " << n << " is: " << high;

    return 0;
}

/*
    Time Complexity: O(log n)
    Space Complexity: O(1)

    Example:
    n = 28

    5 * 5 = 25 <= 28
    6 * 6 = 36 > 28

    Answer = 5
*/